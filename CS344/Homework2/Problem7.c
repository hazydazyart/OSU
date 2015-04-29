//Megan Conley
//conleyme@onid.oregonstate.edu
//CS344-400
//Homework 2


#include <stdio.h> 
#include <getopt.h> 
#include <sys/utsname.h> 
#include <time.h> 
#include <sys/stat.h> 

int main(int argc, char **argv) {

	char c; 
	struct utsname uname_pointer; 
	time_t time_raw_format; 
	struct stat s;
	
	// Loops through user's command line arguments and prints appropriate output as provided
	// in homework documentation
	while ((c = getopt(argc, argv, "htf:")) != -1) {
		switch(c) {
			case 'h':
				uname(&uname_pointer); 
				printf("Hostname = %s \n", uname_pointer.nodename);	
				break;
			case 't':
				time(&time_raw_format); 
				printf("The current local time: %s", ctime(&time_raw_format));
				break;
			case 'f':
				if (stat(optarg, &s) == 0) { 
					printf("size of file '%s' is %d bytes\n" , optarg, (int) s.st_size); 
				} else { 
			 		printf("file '%s' not found\n", optarg); 
				} 
				break;
			default:
				printf("Useage: Problem8.c -h -t -f <filename>\n");
		}
	}

	return 0;
}
