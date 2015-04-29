// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344 400
// Homework 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <pthread.h>
#include <getopt.h>
#include <signal.h>

// Bitset operations from http://c-faq.com/misc/bitsets.html

//#define MAX_BITS 500
//#define NUM_THREADS 1 

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

// These are global to avoid issues passing them to various threads
char *bitarray;
int num_threads;
uint64_t upper_limit;

struct thread_array {
	uint64_t index;
	uint64_t start;
	uint64_t end;
};

void *set_primes(void *args);
void print_twins(int ignored);

// Mark all prime numbers. Like prime_mproc, it stores only odd numbers
// since even numbers are never prime (besides 2) and marks all composites
// as not prime.
void *set_primes(void *args) {

	uint64_t notprime;
	struct thread_array *data = (struct thread_array*)args;

	if(data->start == 1) {
		data->start = 3;
	}

        for(int i = data->start; i <= data->end; i+=2) {
                if(!BITTEST(bitarray, i)) {
			for(int c = 3; i*c <= upper_limit; c += 2) {
				notprime = (i*c)/2;
				BITSET(bitarray, notprime);
			}
                }
        }
	return 0;
}

// Prints the prime values, restoring it from the bitarray index values
// This is the same function as in prime_mproc
void print_twins(int ignored) {

	long long unsigned int twin1;
	long long unsigned int twin2;
	long long unsigned int primeset[upper_limit + 1];
	uint64_t i = 1;

	for(int j = 1; j < (upper_limit/2); j++) {
		if(!BITTEST(bitarray, j)) {
			primeset[i] = (j*2) +1;
			i++;
		}
	}

	primeset[0] = 2;

	for(uint64_t k = 1; k < i; k++) {
		if(primeset[k] - primeset[k-1] == 2) {
			twin1 = primeset[k-1];
			twin2 = primeset[k];
			printf("%llu %llu\n", twin1, twin2);
		}
	}

}

int main(int argc, char **argv) {

	int q_selected;
	int c;
	uint64_t max_bits;
	uint64_t max;
	uint64_t split;
	uint64_t t_remainder = 0;
	uint64_t offset = 1;
	//clock_t start_time;
	//clock_t stop_time;
	//double total_time;
	pthread_attr_t attr;
	void *status;
	pthread_t ptid[num_threads];
        struct thread_array threads[num_threads];
	q_selected = 0;
        num_threads = 0;
        upper_limit = 0;

	while((c = getopt(argc, argv, "qm:c:")) != -1) {
	switch(c) {
		case 'q':
			q_selected = 1;
			break;
		case 'm':
			upper_limit = strtoull(optarg, NULL, 10);
			break;
		case 'c':
			num_threads = atoi(optarg);
			break;
		default:
			printf("Useage: threadedp -q -m # -c #\n");
			exit(-1);
		}
	}

	if(upper_limit == 0) {
		upper_limit = 50;
	}

	if(num_threads == 0) {
		num_threads = 1;
	}

	max_bits = (upper_limit/2) + 1;
	max = upper_limit/2;

	bitarray = (char *) malloc(sizeof(char) * ((max_bits / CHAR_BIT)));
	memset(bitarray, 0, BITNSLOTS(max_bits));

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	split = (BITNSLOTS(max_bits) / num_threads);
	t_remainder = (BITNSLOTS(max_bits) % num_threads);

//	start_time = clock(); // I ended up using the Unix time script since it is more reliable

	// Split the work among the threads
	for(int i = 0; i < num_threads; i++) {
		if(t_remainder > 0) {
			threads[i].start = offset;
			offset += (split + 1) * CHAR_BIT;
			threads[i].end = offset + 1;
			t_remainder--;
		} else { 
			threads[i].start = offset;
			offset += split * CHAR_BIT;
			threads[i].end = offset - 1;
		}
		threads[i].index = i;

		// Create the threads and run the prime finder
		if(pthread_create(&ptid[i], &attr, set_primes, (void*)&threads[i]) != 0) {
			perror("Thread create");
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);

	// Join the threads
	for(int i = 0; i < num_threads; i++) {
		if(pthread_join(ptid[i], &status) != 0) {
			perror("Pthread join");
			exit(-1);
		}
	
	}


//	stop_time = clock();
//	total_time = (double)(stop_time - start_time) / (double)CLOCKS_PER_SEC;
//	printf("Time: %f\n", total_time);

	if(!q_selected) {
		print_twins(0);
	}

	free(bitarray);
	pthread_exit(NULL);

}
