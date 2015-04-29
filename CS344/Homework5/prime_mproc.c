// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344 400
// Homework 5

#define _BSD_SOURCE

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
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/types.h>

// Bitset operations from http://c-faq.com/misc/bitsets.html

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

char *bitarray;
int num_procs;
uint64_t upper_limit;
int shmem_fd;

struct proc_array {
	uint64_t index;
	uint64_t start;
	uint64_t end;
};

void *mount(char *path, int size);
void print_twins(char *barray);
void set_primes(struct proc_array data);

// Mount the shared memory. Code from lecture
void *mount(char *path, int size) {

	void *addr;

	shmem_fd = shm_open(path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (shmem_fd == -1) {
		perror("Shared memory create");
		exit(-1);
	}

	if(ftruncate(shmem_fd, size) == -1) {
		perror("Resize shared memory");
		exit(-1);
	}

	addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmem_fd, 0);
	if(addr == MAP_FAILED) {
		perror("Map shared memory");
		exit(-1);
	}

	return addr;
}

// Marks all non-prime numbers as prime.
// The bit array holds half the max value as it only takes odd numbers into
// consideration. It marks all composites of each value as not prime until it
// hits the end of the values passed.
void set_primes(struct proc_array data) {

	uint64_t notprime;

	if(data.start == 1) {
		data.start = 3;
	}

        for(int i = data.start; i <= data.end; i+=2) {
                if(!BITTEST(bitarray, i)) {
			for(int c = 3; i*c <= upper_limit; c += 2) {
				notprime = (i*c)/2;
				BITSET(bitarray, notprime);
			}
                }
        }

	//return;
	exit(EXIT_SUCCESS);
}


// Prints the twin prime values
// Because the bit array only holds odd numbers, I created a second array
// to hold the expanded list of primes, which are restored by multiplying each
// index in the bit array that is not marked by 2 and adding one.
// 2 is a special case so it is set before printing the values.
void print_twins(char *barray) {

	long long unsigned int twin1;
	long long unsigned int twin2;
	long long unsigned int primeset[upper_limit + 1];
	int i = 1;

	for(int j = 1; j < (upper_limit/2); j++) {
		if(!BITTEST(barray, j)) {
			primeset[i] = (j*2) +1;
			i++;
		}
	}

	primeset[0] = 2;

	for(int k = 1; k < i; k++) {
		if(primeset[k] - primeset[k-1] == 2) {
			twin1 = primeset[k-1];
			twin2 = primeset[k];
			printf("%llu %llu\n", twin1, twin2);
		}
	}

}


int main(int argc, char **argv) {

	int c;
	int size;
	int q_selected;
	uint64_t max_bits;
	uint64_t max;
	uint64_t split;
	uint64_t t_remainder = 0;
	uint64_t offset = 1;
	clock_t start_time;
	clock_t stop_time;
	double total_time;
	void *addr;
        pid_t pids[num_procs];
        struct proc_array procs;
	//int status = -1;
        num_procs = 1;
        upper_limit = 0;
        q_selected = 0;

	while((c = getopt(argc, argv, "qm:c:")) != -1) {
	switch(c) {
		case 'q':
			q_selected = 1;
			break;
		case 'm':
			upper_limit = strtoull(optarg, NULL, 10);
			break;
		case 'c':
			num_procs = atoi(optarg);
			break;
		default:
			printf("Useage: threadedp -q -m # -c #\n");
			exit(-1);
		}
	}

	if(upper_limit == 0) {
		upper_limit = UINT32_MAX;
	}

	max_bits = (upper_limit/2) + 1;
	max = upper_limit/2;

	size = 1024 * 1024 * 600;
	addr = mount("/conleyme", size);
	bitarray = addr;
	memset(bitarray, 0, BITNSLOTS(max_bits));

	split = (BITNSLOTS(max_bits) / num_procs);
	t_remainder = (BITNSLOTS(max_bits) % num_procs);

	start_time = clock();

	// Split up the work in each process
	for(int i = 0; i < num_procs; i++) {
		if(t_remainder > 0) {
			t_remainder--;
			procs.start = offset;
			offset += (split + 1) * CHAR_BIT;
			procs.end = offset + 1;
		} else { 
			procs.start = offset;
			offset += split * CHAR_BIT;
			procs.end = offset - 1;
		}
		procs.index = i;
	
		switch(pids[i] = fork()) {
		case -1:
			perror("Fork");
			exit(-1);
		case 0:
			set_primes(procs);
		default:
			break;
		}
	
	}


	stop_time = clock();
	total_time = (double)(stop_time - start_time) / (double)CLOCKS_PER_SEC;

	while(wait(NULL) != -1);

        if(!q_selected) {
        	print_twins(bitarray);
	}

        printf("Primes found in: %f seconds\n", total_time);

	munmap("/conleyme", size);
	close(shmem_fd);
	shm_unlink("/conleyme");

	return 0;
}
