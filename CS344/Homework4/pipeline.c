// Megan Conley
// conleyme@onid.oregonstate.edu
// Cs344-400
// Homework 4
// Code referenced: https://gist.github.com/zed/7835043
// from which I got the general idea of recursive piping,
// though I cleaned it up a bit into two functions.
// I chose recursive for this one since there is a defined
// number of commands that each run once, so this wouldn't
// be as easy to implement in uniquify.c

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <getopt.h>

void exec_nth_cmd(int ncmd, char ***cmd);
void pipeline(int ncmd, char ***cmd);

// exec_nth_cmd: Recursively forks processes, one for
// 	each command stored in the array.
void exec_nth_cmd(int ncmd, char ***cmd) {

	if(ncmd > 1) {
		int pfd[2];
		pid_t cpid;
		if(pipe(pfd) == -1) {
			perror("Pipe outpfd\n");
			exit(-1);
		}

		switch(cpid = fork()) {
		case -1:
			perror("Fork\n");
			exit(-1);
		case 0:
			dup2(pfd[1], 1);
			close(pfd[0]);
			close(pfd[1]);
			exec_nth_cmd(ncmd-1, cmd);
		default:
			break;
		}
		dup2(pfd[0], 0);
		close(pfd[0]);
		close(pfd[1]);
	}
	execvp(cmd[ncmd-1][0], cmd[ncmd-1]);
	perror("Exec");
	exit(-1);
}

// pipeline: initiates the recursive exec function by creating
// 	the first fork.
void pipeline(int ncmd, char ***cmd) {
	pid_t cpid;
	switch(cpid = fork()) {
	case -1:
		perror("Fork\n");
		exit(-1);
	case 0:
		exec_nth_cmd(ncmd, cmd);
	default:
		break;
	}
}

int main(int argc, char **argv) {

	// Create arrays of null-terminated commands
	char *cmd1[] = {"rev", (char*)NULL};
	char *cmd2[] = {"sort", (char*)NULL};
	char *cmd3[] = {"uniq", "-c", (char*)NULL};
	char *cmd4[] = {"tee", 0, (char*)NULL};
	char *cmd5[] = {"wc", (char*)NULL};

	// Combine the commands into one array
	char **allcmds[] = {cmd1,cmd2,cmd3,cmd4,cmd5};

	int num_cmds = 5;

	int opt;
	pid_t cpid;
	int status;
	char *output = "temp"; // placeholder for tee output file name

	while((opt = getopt(argc, argv, "f:")) != -1) {
		switch(opt) {
		case 'f':
			output = optarg;
			break;
		default:
			printf("Usage: pipeline -f <filename>\n");
			exit(-1);
		}
	}

	cmd4[1] = output; // assign output file name arg to tee
	pipeline(num_cmds, allcmds); //run recursive pipe

        while((cpid = waitpid(-1, &status, 0)) == -1) { // wait on children
                printf("Could not reap child pid %d\n", cpid);
        }
	return 0;
}
