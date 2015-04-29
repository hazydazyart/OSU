#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ar.h>
#include <string.h>
#include <getopt.h>
#include <dirent.h>
#include <utime.h>

#define R_OWNER	00400
#define R_GROUP	00040
#define R_ALL	00004
#define W_OWNER	00200
#define W_GROUP	00020
#define W_ALL	00002
#define X_OWNER	00100
#define X_GROUP	00010
#define X_ALL  	00001
#define BLOCKSIZE 1

// get_fname(int)
// Reads and prints file name from archive
// Parameters: file descriptor
// Output: File name held in the next 16 bytes
//  pointed to by the file descriptor
void get_fname(int fd) {

	char buffer[16];
        if(read(fd, buffer, 16) == -1) {
	        perror("read");
                exit(-1);
        }
        for (int i = 0; i < 16; i++) {
                if(buffer[i] == '/') {
            	    buffer[i] = '\0';
                }
       	}

        printf("%s\n",buffer);
}

// print_perms(long)
// Converts octal permissions to human-readable format
// Parameters: long octal
// Output: Symbolic permissions
void print_perms(long perms) {

	mode_t mode = perms;

	char g_r, g_w, g_x;
	char o_r, o_w, o_x;
        char a_r, a_w, a_x;

	// Print the octal permissions as something readable by humans
	// using the bit masks
	// A resource I used to help me on this was: 
	// http://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c
	// Instead of using the signals, I defined them myself as constants
	// since I don't have a way of getting the fstat() of each file;
	// instead, they're converted from octal to a mode_t variable and translated from there

	g_r = R_GROUP & mode ? 'r' : '-';
        g_w = W_GROUP & mode ? 'w' : '-';
        g_x = X_GROUP & mode ? 'x' : '-';

 	o_r = R_OWNER & mode ? 'r' : '-';
        o_w = W_OWNER & mode ? 'w' : '-';
        o_x = X_OWNER & mode ? 'x' : '-';

 	a_r = R_ALL & mode ? 'r' : '-';
 	a_w = W_ALL & mode ? 'w' : '-';
        a_x = X_ALL & mode ? 'x' : '-';

	printf("%c%c%c", o_r, o_w, o_x);
	printf("%c%c%c", g_r, g_w, g_x);
	printf("%c%c%c ", a_r, a_w, a_x);
}

// append(char*, char*)
// Appends a file and its header to an archive
// Parameters: file to be appened, archive to be appended to
// Output: none
void append(char* file_name, char* input) {

        struct stat fs;
        int cursor;
        char new_line[1];
        new_line[0] = '\n';
	int in_fd;

	int fd = open(file_name, O_RDONLY);
	struct ar_hdr header;
        if(fstat(fd, &fs) == -1) {
		perror("fstat");
		exit(-1);
	}

        int member_size = fs.st_size;

	// The file header is stored as a series of strings
	// padded with spaces in all empty indeces
	// For each necessary piece of information,
	// I copied them into a temporary buffe
	// as sprintf appends a null terminator automatically
	// I then copied the temporary string to the appropriate
	// header variable except the null terminator.
	// Before I did this, the null terminators were spilling over
	// into other strings in the struct.
	sprintf(header.ar_name, "%-16s", file_name);
	header.ar_name[strlen(file_name)] = '/';
	
	char tempuid[7];
	sprintf(tempuid, "%-6d", fs.st_uid);
	strncpy(header.ar_uid, tempuid, 6);

	char tempgid[7];
	sprintf(tempgid, "%-6d", fs.st_gid);
	strncpy(header.ar_gid, tempgid, 6);

	char tempmode[9];
	sprintf(tempmode, "%-8o", fs.st_mode);
	strncpy(header.ar_mode, tempmode, 8);

	char temptime[13];
	sprintf(temptime, "%-12d", fs.st_mtime);
	strncpy(header.ar_date, temptime, 12);

	char tempsize[11];
        sprintf(tempsize, "%-10d", fs.st_size);
	strncpy(header.ar_size, tempsize, 10);

	sprintf(header.ar_fmag, "%s", ARFMAG);

        char out[BLOCKSIZE];
        int bread;
        int written;
        struct stat ar_file;

	// If the archive being appended to doesn't exist, create a new one
        if(stat(input, &ar_file) == -1) {
        	char ar_mag[SARMAG];
                strncpy(ar_mag, ARMAG, strlen(ARMAG));
                in_fd = open(input, O_CREAT | O_WRONLY, 0666);
                write(in_fd, ar_mag, sizeof(ar_mag));
        } else {
                in_fd = open(input, O_WRONLY);
        }


        cursor = lseek(in_fd, 0, SEEK_END);

	// Write each piece of the header to the new archive
        write(in_fd, header.ar_name, 16);
        write(in_fd, header.ar_date, 12);
	write(in_fd, header.ar_uid, 6);
	write(in_fd, header.ar_gid, 6);
        write(in_fd, header.ar_mode, 8);
        write(in_fd, header.ar_size, 10);
        write(in_fd, ARFMAG, 2);

        cursor = lseek(in_fd, 0, SEEK_END);

	// Write the contents of the file itself
        while((bread = read(fd, out, BLOCKSIZE)) > 0) {
	        written = write(in_fd, out, BLOCKSIZE);
                if (written != bread) {
        	        perror("Error writing file");
                        exit(-1);
                }
        }

	// If the file is odd, write in a new line as well
        if(member_size % 2 == 1) {
                write(in_fd, new_line, sizeof(new_line));
        }

	close(in_fd);
	close(fd);
}

// print_contents(char*)
// Prints a list of file names in an archive
// Parameters: file name
// Output: All file names in an archive
void print_contents(char* input) {

        struct stat fs;
        int cursor;
        char new_line[1];
        new_line[0] = '\n';

	int fd = open(input, O_RDONLY);
	if (fstat(fd, &fs)  < 0) {
	        perror("fstat");
                exit(-1);
        }

        cursor = lseek(fd,8,SEEK_CUR);

        while(cursor < (long)fs.st_size) {

        	get_fname(fd);
                cursor = lseek(fd,32,SEEK_CUR);
                char file_size[10];
                if(read(fd, file_size, 10) == -1) {
	                perror("read");
                        exit(-1);
                }
                file_size[9] = '\0';
                int size = atoi(file_size);

                if (size % 2 == 1) {
	                cursor = lseek(fd,1,SEEK_CUR);
                }

                cursor = lseek(fd,size+2,SEEK_CUR);

	}

	close(fd);
}

// extract(int, char*, int)
// Copies a file from an archive passed as a file descriptor
//  to the current directory
// Parameters: archive file as file descriptor, name of file to be extracted,
//  cursor to track current location in file
// Output: none
void extract(int fd, char* file_name, int* cursor) {

	// Create the file to copied
        int extracted = open(file_name, O_CREAT | O_WRONLY, 0666);

	// Get the timestamp from the file in the archive
        char timestamp[12];
        if(read(fd,timestamp,12) == -1) {
        	perror("read");
                exit(-1);
        }

        time_t c_time = strtoul(timestamp, NULL, 0);

        cursor = lseek(fd, 20, SEEK_CUR);

        char size[10];

        if(read(fd,size,10) == -1){
	        perror("read");
                exit(-1);
        }
        size[9] = '\0';

        int fsize = atoi(size);
        cursor = lseek(fd, 2, SEEK_CUR);

        char out[BLOCKSIZE];
        int bread;
        int written;
        int count= 0;

	// Copy contents of file from archive, which is located at the end
	// of the file header and lasts n bytes, where n is the size of the file
        while((bread = read(fd, out, BLOCKSIZE)) > 0 && count != fsize) {
		written = write(extracted, out, BLOCKSIZE);
                count++;
                if (written != bread) {
         		perror("Error writing file");
                        exit(-1);
                }
        }

	// Restore time stamp to newly extracted file
	// Info on utime found at: http://www.mitchr.me/SS/exampleCode/AUPG/utime.c.html
        struct utimbuf uTime;
        uTime.actime = c_time;
        uTime.modtime = c_time;
        if(utime(file_name, &uTime) != 0) {
 	       perror("utime");
               exit(-1);
        }
}

// append_all(char*)
// Iterates through current directory and appends all regular files
// Parameter: file name to append files to
// Output: None
void append_all(char* input) {

	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir (".")) != NULL) {
        	while ((ent = readdir (dir)) != NULL) {
			struct stat reg_file;
			if(stat(ent->d_name, &reg_file) == -1) {
        	        	perror("Can't stat");
                        	exit(-1);
        		}

		// If it's a regular file, append it to the archive
		// Linux considers all items "files" it's important to distinguish
		// files as we know them - text docs, executeables, etc
		// from directories or special files such as pipe files or socket files
		// source: http://www.linuxnix.com/2010/02/file-types-in-linux.html
			if(S_ISREG(reg_file.st_mode) && (strncmp(ent->d_name, input, sizeof(input))) != 0) {
	        	        append(ent->d_name, input);
	                	}
        	}
	        closedir (dir);
        } else {
 	       perror ("Could not open directory.");
               exit(-1);
        }
}

// verbose(int, int)
// Parameter: file descriptor
// Output: verbose table of contents of archive file
void verbose(int fd) {

	struct stat fs;

	if(fstat(fd, &fs) < 0) {
        	perror("fstat");
                exit(-1);
        }

        int cursor = lseek(fd,8,SEEK_CUR);
        while(cursor < (long)fs.st_size) {

	        cursor = lseek(fd,40,SEEK_CUR);
                char mode[8];
                if(read(fd,mode,8) == -1) {
	                perror("read");
                        exit(-1);
                }                      
		// Convert the mode to an octal number for reading permissions
		long perms = strtol(mode, NULL, 8);

                print_perms(perms);

                cursor = lseek(fd,-20,SEEK_CUR);

                char uid[6];
                uid[5] = '\0';
                if(read(fd,uid,5) == -1) {
	                perror("read");
                        exit(-1);
                }
                printf("%s/", uid);

                cursor = lseek(fd,1,SEEK_CUR);

                char gid[6];
                gid[5] = '\0';
                if(read(fd,gid,5) == -1) {
	                perror("read");
                        exit(-1);
                }

                printf("%s", gid);

                cursor = lseek(fd,8,SEEK_CUR);

                char size[10];
                size[9] = '\0';

                if(read(fd,size,9) == -1){
         	       perror("read");
                       exit(-1);
                }

                int fsize = atoi(size);
                printf("%7d", fsize);
                char time_string[12];
                time_string[12] = '\0';

                cursor = lseek(fd,-42,SEEK_CUR);

                if(read(fd,time_string,12) == -1) {
 	               perror("read");
                       exit(-1);
                }

                time_t c_time = strtoul(time_string, NULL, 0);
                char* c_time_string = ctime(&c_time);

                printf(" %12.12s %4.4s ", c_time_string + 4, c_time_string + 20);

                cursor = lseek(fd,-26,SEEK_CUR);

                get_fname(fd);

                if(fsize % 2 == 1) {
	                cursor = lseek(fd,1,SEEK_CUR);
                }

                cursor = lseek(fd,fsize+44,SEEK_CUR);
	}
}

int main(int argc, char** argv) {

	char c;
	char* input;
	char* file_name;
	int fd;
	struct stat fs;
	int cursor;
	int in_fd;

        while ((c = getopt(argc, argv, "q:t:v:x:d:A:")) != -1) {
                switch(c) {
                        case 't': // Print file names in archive
				input = optarg;
				
				print_contents(input);

                                break;
                        case 'q': // Append all specified members
				input = optarg;

				// If no files were named for appending,
				// create new empty archive
				if(argc == 2) {
					struct stat ar_file;
			        	if(stat(input, &ar_file) == -1) {
			                	char ar_mag[SARMAG];
				                strncpy(ar_mag, ARMAG, strlen(ARMAG));
				                in_fd = open(input, O_CREAT | O_WRONLY, 0666);
				                write(in_fd, ar_mag, sizeof(ar_mag));
					}
			        } else {
					// Otherwise append all named files
					for(int i = optind; i < argc; i++) {

						file_name = argv[i];
						append(file_name, input);
					}
				}

                                break;
                        case 'v': // Verbose table of contents
                                input = optarg;
                                fd = open(input, O_RDONLY);

				verbose(fd);

				close(fd);

                                break;
                        case 'x': // Extract file
	
				input = optarg;
				int found = 0;
				fd = open(input, O_RDONLY);

                                if(fstat(fd, &fs) < 0) {
                                        perror("fstat");
                                        exit(-1);
                                }

                                cursor = lseek(fd,8,SEEK_CUR);

                                while(cursor < (long)fs.st_size && found != 1) {

                                        char buffer[16];
                                        if(read(fd, buffer, 16) == -1) {
                                                perror("read");
                                                exit(-1);
                                        }
                                        for (int i = 0; i < 16; i++) {
                                                if(buffer[i] == '/') {
                                                buffer[i] = '\0';
                                                }
                                        }

                                        if(strncmp(buffer, argv[3], sizeof(argv[3])) == 0) {
						// First instance matching the requested name was entered
						// Extract it
						found = 1;
						extract(fd, buffer, &cursor);

					} else {
						// Name does not match; skip it and check the next one
                                                cursor = lseek(fd, 32, SEEK_CUR);
                                                char size[10];

                                                if(read(fd,size,10) == -1){
                                                        perror("read");
                                                        exit(-1);
                                                }
                                                size[9] = '\0';

                                                int fsize = atoi(size);

                                                if(fsize % 2 == 1) {
                                                        cursor = lseek(fd, 1, SEEK_CUR);
                                                }

                                                cursor = lseek(fd, fsize + 2, SEEK_CUR);
                                        }
                                }

                                if(found == 0) {
                                        printf("Error: file not found in archive.\n");
                                }

                                break;
                        case 'd': // Delete named file
			// Warning: this function is not fully correct - the resulting
			// new archive file's contents are incorrect.
			// Below is my best attempt at the general idea of the process,
			// though.

                                input = optarg;
                                found = 0;
                                fd = open(input, O_RDONLY);

                                if(fstat(fd, &fs) < 0) {
                                        perror("fstat");
                                        exit(-1);
                                }

                                cursor = lseek(fd,8,SEEK_CUR);

				// Create temporary new archive to hold contents of
				// original archive that are not to be deleted
                                int new_ar = open("temp.a", O_CREAT | O_WRONLY, 0666);

				// Copy ar header to new archive
                                write(new_ar, ARMAG, sizeof(ARMAG));

                                while(cursor < (long)fs.st_size) {

                                        char buffer[16];
                                        if(read(fd, buffer, 16) == -1) {
                                                perror("read");
                                                exit(-1);
                                        }
                                        for (int i = 0; i < 16; i++) {
                                                if(buffer[i] == '/') {
                                                buffer[i] = '\0';
                                                }
                                        }
					buffer[15] = '\0';
					
                                        if(strncmp(buffer, argv[3], sizeof(argv[3])) == 0 && found == 0) {
                                                // Found first file matching this name to be deleted -
                                                // skip instead of copying it
                                                cursor = lseek(fd, 32, SEEK_CUR);
                                                char size[10];

                                                if(read(fd,size,10) == -1){
                                                        perror("read");
                                                        exit(-1);
                                                }
						size[9] = '\0';

                                                int fsize = atoi(size);

                                                if(fsize % 2 == 1) {
                                                        cursor = lseek(fd, 1, SEEK_CUR);
                                                }

                                                cursor = lseek(fd, fsize + 2, SEEK_CUR);
						found = 1;

                                        } else {
						// File name does not match file to be deleted
                                                cursor = lseek(fd, 32, SEEK_CUR);
                                                char size[10];

                                                if(read(fd,size,10) == -1){
                                                        perror("read");
                                                        exit(-1);
                                                }
                                                size[9] = '\0';

                                                int fsize = atoi(size);


						// Go back to the start of the header for this file
						cursor = lseek(fd, -58, SEEK_CUR);

						// Extract it, then append it to the new temp archive
						// then delete the extracted file
						extract(fd, buffer, &cursor);
						append(buffer, "temp.a");
						unlink(buffer);

                                                if(fsize % 2 == 1) {
                                                        cursor = lseek(fd, 1, SEEK_CUR);
                                                }

                                                cursor = lseek(fd, fsize + 2, SEEK_CUR);
					}
                                }

				// File not in archve - delete temporary archive
                                if(found == 0) {
                                        printf("Error: file not found in archive.\n");
					close(new_ar);
					unlink("temp.a");
					close(fd);
				// File was in archive - new archive created missing that
				// file but with the rest of the contents copied;
				// now delete orginal archive and rename the new archive
				// to the name of original archive
                                } else {
					close(fd);
					close(new_ar);
					unlink(input);
					rename("temp.a", input);
				}

                                break;
                        case 'A': // Append all regular files
                                input = optarg;
				if(argc > 2) {
					printf("Warning: arguments after %s will be ignored.\n", input);
				}

				append_all(input);

                                break;
                        default:
                                printf("Useage: -qxdtvA [archive] [member(s)]\n");
                }

       }
	return 0;
}
