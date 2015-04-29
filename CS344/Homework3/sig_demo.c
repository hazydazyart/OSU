// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344-400
// Homework 3

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig) {

	if (sig == SIGUSR1) {
		printf("SIGUSR1 has been caught.\n");
	} else if (sig == SIGUSR2) {
		printf("SIGUSR2 has been caught.\n");
	} else {
		printf("SIGINT has been caught, terminating the program.\n");
	}
}

int main() {

	// Establish handler for SIGUSR1, SIGUSR2, and SIGINT
	if (signal(SIGUSR1, sigHandler) == SIG_ERR) {
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, sigHandler) == SIG_ERR) {
		exit(EXIT_FAILURE);
	}
	if (signal(SIGINT, sigHandler) == SIG_ERR) {
		exit(EXIT_FAILURE);
	}

	int sig = kill(getpid(), SIGUSR1);
	sig = kill(getpid(), SIGUSR2);
	sig = kill(getpid(), SIGINT);

	return 0;
}

