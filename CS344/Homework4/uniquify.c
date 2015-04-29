// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344-400
// Homework 4
// I had issues compiling with c99 and signal.h, I used this source to find the complier flag to fix it:
// http://stackoverflow.com/questions/8846047/compile-errors-using-signal-h-in-linux

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <getopt.h>
#include <time.h>

#define MAX_LEN 100 //Max word length is twice the longest common English word for safety

void uniquify(int sort_num);
void parse(int sort_num, int** in_pipe);
void forked_sort(int sort_num, int **in_pipe, int **out_pipe);
void sort(int sort_num, int **in_pipe, int **out_pipe);
void forked_merge(int sort_num, int **out_pipe);
void merge(int sort_num, int** out_pipe);
void sigchild_handler(int sig);
void sigint_handler(int sig);
void tolowercase(char* word);
void close_pipes(int sort_num, int **in_pipe, int **out_pipe);
void open_pipes(int sort_num, int **in_pipe, int **out_pipe);

// Tolowercase: converts mixed case string to lower case
// Parameters: string to be converted as word
void tolowercase(char* word) {
	for(int i = 0; i < strlen(word); i++) {
		word[i] = tolower(word[i]);
	}
}

// Sigchild_handler: Reaps child processes
// Parameters: dummy parameter
void sigchild_handler(int sig){
	while(waitpid(-1, NULL, WNOHANG) > 0){
		continue;
	}
}

// Sigint_handler: Handles interrupt signal
// Parameters: dummy parameter
void sigint_handler(int sig){
	perror("SIGINT caught, exiting");
	exit(-1);
}

// close_pipes: Closes both in/out file descriptors for in/out pipes used by the program
// Parameters: number of sort processes as sort_num
// 		input from stdin as in_pipe
// 		output from functions as out_pipe
void close_pipes(int sort_num, int **in_pipe, int **out_pipe) {
	for(int i = 0; i < sort_num; i++) {
		close(in_pipe[i][0]);
		close(in_pipe[i][1]);
		close(out_pipe[i][0]);
		close(out_pipe[i][1]);
	}
}

// uniquify: calls parser, sorter, and merger functions
// 		handles SIGCHLD and SIGINT
// Parameters: number of sort processes as sort_num
void uniquify(int sort_num){
	
	int **in_pipe; 
	int **out_pipe; 
	struct sigaction sa_sigchild;
	struct sigaction sa_sigint;
	
	// Sigaction setup from http://stackoverflow.com/questions/7171722/how-can-i-handle-sigchld-in-c	
	sigemptyset(&sa_sigchild.sa_mask);
	sa_sigchild.sa_flags = 0;
	sa_sigchild.sa_handler = sigchild_handler;

	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = 0;
	sa_sigint.sa_handler = sigint_handler;
	
	if (sigaction(SIGCHLD, &sa_sigchild, NULL) == -1){
		perror("Error creating signal handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1){
		perror("Error creating signal handler");
		exit(EXIT_FAILURE);
	}
	
	// Allocate memory for as many pipes as there are sort subproccesses
	in_pipe = (int**)malloc(sort_num * sizeof(int*));
	out_pipe = (int**)malloc(sort_num * sizeof(int*));
	
	for (int i = 0; i < sort_num; i++){
		in_pipe[i] = malloc(2 * sizeof(int));
		out_pipe[i] = malloc(2 * sizeof(int));
	}
	
	sort(sort_num, in_pipe, out_pipe);
	
	parse(sort_num, in_pipe);
	
	forked_merge(sort_num, out_pipe);

	// Free allocated memory
	for (int i = 0; i < sort_num; i++){
		free(in_pipe[i]);
		free(out_pipe[i]);
	}
	free(in_pipe);
	free(out_pipe);	
	
	// Wait on children
	while(wait(NULL) > 0) {
		continue;
	}
}

void forked_merge(int sort_num, int **out_pipe) {

	pid_t cpid;
        switch(cpid = fork()){
                case -1:
                        perror("Could not create child");
                        exit(-1);
                case 0:
                        merge(sort_num, out_pipe);
                        break;
                default:
                        break;
        }
}

void open_pipes(int sort_num, int **in_pipe, int **out_pipe) {
	for(int i = 0; i < sort_num; i++) {
		if (pipe(in_pipe[i]) == -1 || pipe(out_pipe[i]) == -1){
        		perror("Error creating sort input pipe");
                	exit(-1);
	                }
	}
}

void sort(int sort_num, int **in_pipe, int **out_pipe){
	
	// Save the parent's in/out file descriptors
	int in_fd = dup(STDIN_FILENO);
	int out_fd = dup(STDOUT_FILENO);

	open_pipes(sort_num, in_pipe, out_pipe);
	
	for (int i = 0; i < sort_num; i++){
		
		close(STDIN_FILENO);
	        close(STDOUT_FILENO);
	
		// Duplicate stdin on read end of pipe	
		if (dup2(in_pipe[i][0], STDIN_FILENO) == -1){
			perror("Error duplicating pipe");
			exit(EXIT_FAILURE);	
		}
		
		// Duplicate stdout on write end of pipe
		if (dup2(out_pipe[i][1], STDOUT_FILENO) == -1){
			perror("Sort: dup2 outpipe");
			exit(-1);	
		}		
		
		// Fork sort process
		forked_sort(sort_num, in_pipe, out_pipe);

		// Close unneeded ends of pipes
		if (close(in_pipe[i][0]) == -1){
			perror("Error closing pipe");
			exit(EXIT_FAILURE);	
		}

		if (close(out_pipe[i][1]) == -1){
			perror("Error closing pipe");
			exit(EXIT_FAILURE);	
		} 
	}	

	// Restore stdin/stdout file descriptors for parent
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);   
}

void forked_sort(int sort_num, int **in_pipe, int **out_pipe) {

	pid_t cpid;	
	switch(cpid = fork()){
        	case -1:
                	perror("forked_sort: fork");
	                exit(-1);
                case 0:
                        close_pipes(sort_num, in_pipe, out_pipe);
                        execlp("sort", "sort", (char*) NULL);
                        break;
                default:
                        break;
                }
}


// Parse: remove all non-letter characters and convert words to lower case
// Parameters: number of sort processes as sort_num
// 		pipe from stdin as in_pipe
void parse(int sort_num, int** in_pipe){
	
	char word[MAX_LEN];
	int test;
	int n = 0;
	FILE *input[sort_num]; 
	
	// Pipe from stdin to an array of files
	for (int i = 0; i < sort_num; i++) {
		input[i] = fdopen(in_pipe[i][1], "w");
	}
	
	do {
		// Get next word
		test = scanf("%[a-zA-Z]", word);
		if (test == 1) {
			tolowercase(word); // turn it to lower case
			strcat(word, "\n"); // append newline for sort process
			fputs(word, input[n]); // add it to file
			n = (n + 1) % sort_num; // move to next file
		}
		test = scanf("%*[^a-zA-Z]"); // skip anything that is not a letter
	} while (test != EOF);
	
	// Parsing done, close input
	for (int i = 0; i < sort_num; i++) {
		fclose(input[i]);
	}
}

// Merge takes the sorted input and mimics performing 'uniq -c'
// by counting and suppressing duplicates
// Parameters: number of sort processes as sort_num
// 		piped input from sort function as out_pipe
void merge(int sort_num, int** out_pipe) {

	int word_count = 0;
	int position = 0;
	int empty = 0;
	char word[MAX_LEN] = "";
	char sorted[sort_num][MAX_LEN];
	FILE* output[sort_num];

	// Prepare pipe to read from sort function
	for (int i = 0; i < sort_num; i++) {
		output[i] = fdopen(out_pipe[i][0], "r");
	}
	
	// If any of the inputs are blank, add it to the count of empty spaces
	for (int i = 0; i < sort_num; i++) {
		if(fgets(sorted[i], MAX_LEN, output[i]) == NULL) {
			sorted[i][0] = '\0';
			empty++;
		}
	}

	// Grab the first word
	strcpy(word, sorted[position]);
	
	// Iterate through input from sort until all words have been read
	while(empty < sort_num) {
		// Get next alphabetical word
		for (int i = 0; i < sort_num; i++) {
			if (sorted[i] != NULL) {
				if (strcmp(sorted[i], sorted[position]) < 0) {
					position = i;
				}
			}
		}

		// Compare to word just added
		// If a repeat, add to word count
		if (strcmp(sorted[position], word) == 0) {
			word_count++;
		// If new word is unique, write the previous word and its count to file
		// Then restart the word count for the new one at 1
		} else {
			printf("%7d %s", word_count, word);
			strcpy(word, sorted[position]);
			word_count = 1;
		}
		
		// Get rid of the word so it isn't recounted in the next loop
		if(fgets(sorted[position], MAX_LEN, output[position]) == NULL) {
			sorted[position][0] = '\0';
			empty++;
		}
			
		// Get next word, or add to empty count if it is not there
		for (int i = 0; i < sort_num; i++){
			if (sorted[i] != NULL){
				position = i;
				break;
			} else {
				empty++;
			}
		}
	}
	
	// Print the last word
	printf("%7d %s", word_count, word);

	// Close the output now that merge is done
	for (int i = 0; i < sort_num; i++) {
		fclose(output[i]);
	}
}

int main(int argc, char *argv[]){
        char c;
        int sort_num = 0;

        while ((c = getopt (argc, argv, "n:")) != -1){
                switch (c){
                        case 'n':
                                sort_num = atoi(optarg);
                                break;
                        default: // if the user did not input a process number
                                break; // go to below logic check
                }
        }

	// Sets default to 1 if input is not between 1-50
	// If user did not input a value, it was initialized to 0,
	// so it will default to 1 as well
        if (sort_num > 50 || sort_num < 1){
                printf("Number of processes must be between 1-50. Default is one process.\n");
                sort_num = 1;
        }

	// Run uniquify
        
	uniquify(sort_num);
        return 0;
}

