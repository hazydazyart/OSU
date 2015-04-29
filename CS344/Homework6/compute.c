// Megan Conley
// conleyme@onid.oregonstate.edu
// Cs344-400
// Homework6

#define _POSIX_SOURCE
#define _BSD_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <math.h>
#include <time.h>

#define LISTENQ 5
#define MAXLINE 4096
#define BUFFSIZE 8192

#define SERV_PORT 9998
#define SERV_PORT_STR "9998"

pid_t compute_pid = 0;
pid_t pid;

struct packet {
	char sender[20];
	char request[20];
	unsigned long int min;
	unsigned long int max;
};

void send_handshake(int sockfd, char* sender);
void send_packet(int sockfd, char* packet);
int is_perfect(unsigned int test);
unsigned int get_flops(int ignored);
long int packetvalue(char* str);
struct packet parsepacket(char* str);
void compute(char* port);
void send_perfect(unsigned int perf, int sockfd);
void get_range(int sockfd, unsigned int prev);
void terminate(int sig);


int is_perfect(unsigned int test) {
	int sum = 1;

	if(test == 1) {
		return 0; // 1 is not perfect
	}
	for(int i = 2; i < sqrt(test); i++) {
		if(test % i == 0) {
			sum += i;
			sum += test/i;
		}
	}
	if(sum == test) {
		return 1;
	} else {
		return 0;
	}
}

unsigned int get_flops(int ignored) {

        unsigned int j;
        unsigned int i;
	unsigned int k;
	clock_t start_time;
	clock_t end_time;
	double total_time;
	unsigned int coefficient;
	start_time = clock();

	k = 0;
	j = 7;

	for(i = 1; i < 100000000; i++) {
		k = j % i;
	}
	end_time = clock();

	total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	//printf("K = %u in %f seconds\n", k, total_time);
	coefficient = (int) 1.00/total_time;
	return (i - 1) * coefficient;
}

void send_packet(int sockfd, char* packet) {

	write(sockfd, packet, strlen(packet));
}

long int packetvalue(char* str) {
	long int value;
	int i = 0;
	int j = 0;
	int length = strlen(str);
	char buff[length];

	while(i != strlen(str)) {
		if((str[i] >= 48) && (str[i] <= 57)) {
			buff[j] = str[i];
			i++;
			j++;
		} else {
			i++;
		}
	}

	value = atol(buff);
	return value;
}

struct packet parsepacket(char* str) {
        char buff[MAXLINE];
        char* tokens[15];
        struct packet parsed;
        int i;
	char *p;
        int j = 0;
        int k = 0;

        for(i = 0; i < strlen(str); i++) {
                if((str[i]>=48 && str[i]<=57) || (str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) || str[i] == ' ') {
                        buff[j] =  str[i];
                        j++;
                }
        }
        buff[j+1] = '\0';

        p = strtok(buff, " ");
        while(p != NULL) {
                tokens[k++] = p;
                p = strtok(NULL, " ");
        }

        strcpy(parsed.request,tokens[1]);
        strcpy(parsed.sender,tokens[3]);

	if(tokens[5] != NULL) {
		long int minimum = packetvalue(tokens[5]);
		parsed.min = minimum;
	}
	if(tokens[7] != NULL) {
		long int maximum = packetvalue(tokens[7]);
		parsed.max = maximum;
	}
        return parsed;
}

/*
char* XMLstringify(struct packet pack) {

	char stringed[MAXLINE];

	char reqheader[] = "<request= '";
	char request[20];
	char sendheader[] = "' sender= '";
	char sender[20];

	strncpy(sender, pack.sender, sizeof(sender));
	strncpy(request, pack.request, sizeof(request));
	char end[] = "'></request>";

	snprintf(stringed, sizeof stringed, "%s%s%s%s%s", reqheader, request, sendheader, sender, end);

	return stringed;
}	
*/
void send_handshake(int sockfd, char* sender) {

	char buf[MAXLINE];
	snprintf(buf, MAXLINE, "<request= 'handshake' sender= '%s'", sender);
	send_packet(sockfd, buf);
} 

void get_range(int sockfd, unsigned int prev) {

	char buf[MAXLINE];
	unsigned int flops = get_flops(0);
	snprintf(buf, MAXLINE, "<request= 'getrange' sender= 'compute' performance= %u prevmax= %u/>", flops, prev);
	write(sockfd, buf, strlen(buf));
}

void send_perfect(unsigned int perf, int sockfd) {

	char buf[MAXLINE];
        bzero(buf, MAXLINE);
	snprintf(buf, MAXLINE, "<request= 'perfect' sender= 'compute' value= %u />", perf);
	write(sockfd, buf, strlen(buf));
	bzero(buf, MAXLINE);
}

void compute(char* port) {
	// socket install
	unsigned int i;
	int sockfd;
	struct sockaddr_in servaddr;
	char recvd[MAXLINE];
	char resp[MAXLINE];
	unsigned int prev_max;
	struct packet range;
	clock_t start_t;
	clock_t stop_t;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, port, &servaddr.sin_addr);

	// connect to manage.py
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	// get connection handshake
	if(read(sockfd, recvd, MAXLINE) == 0) {
		perror("read");
		exit(-1);
	}

	// printf("Received handshake: %s\n", recvd);
	
	// send handshake
	send_handshake(sockfd, "compute");

	while(1) {

		// request range from server
		get_range(sockfd, prev_max);

		if(read(sockfd, resp, MAXLINE) == 0) {
			perror("read");
			exit(-1);
		}

		

		//printf("Received response: '%s'\n", resp);
		range = parsepacket(resp);

		//printf("Finding perfect numbers between %u to %u\n", range.min, range.max);


		start_t = clock();
		for(i = range.min; i <= range.max; i++) {
			if(is_perfect(i)) {
				//printf("Found perfect: %u\n", i);
				send_perfect(i, sockfd);
			}
		}

		stop_t = clock();
		//printf("Found perfect numbers in %ld seconds\n", (stop_t-start_t)/CLOCKS_PER_SEC);

		prev_max = range.max;
	}
}

void terminate(int sig) {
	if(compute_pid != 0) {
		kill(compute_pid, SIGQUIT);
		wait(NULL);
	}
	exit(-1);
}

int main(int argc, char **argv) {

        int sockfd;
        struct sockaddr_in servaddr;
	struct packet response;
        char recvd[MAXLINE];

	// signal handling
	struct sigaction sighandler;
	sigemptyset(&sighandler.sa_mask);
	sighandler.sa_handler = terminate;
	sighandler.sa_flags = 0;

	sigaction(SIGQUIT, &sighandler, NULL);
	sigaction(SIGINT, &sighandler, NULL);
	sigaction(SIGHUP, &sighandler, NULL);

	switch(pid = fork()) {
	case -1:
		perror("fork");
		exit(-1);
	case 0:
		compute(argv[1]);
		break;
	case 1:
		compute_pid = pid;
		break;
	}

	// compute manager task
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	// connect to manage and report
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	// get handshake
	if(read(sockfd, recvd, MAXLINE) == 0) {
		perror("read");
		exit(-1);
	}

        //printf("Received handshake: '%s'\n", recvd);
	bzero(recvd, MAXLINE);
	send_handshake(sockfd, "cman");
	
	// wait for signal
	if(read(sockfd, recvd, MAXLINE) == 0) {
		perror("read");
		exit(-1);
	}

	response = parsepacket(recvd);

	// If manage has sent a terminate request, kill the child process and exit program
	if(!strcmp(response.request, "terminate") && !strcmp(response.sender, "manage")) {
		close(sockfd);
		kill(compute_pid, SIGQUIT);
		wait(NULL);
		exit(-1);
	}

	return 0;
}
