// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344-400
// Homework 1

#include <stdio.h>
#include <math.h>

int sieve(int in, int* prime);

int main() {

	int user_input;

	printf("Enter an integer: ");
	scanf("%d", &user_input);

	int primes[user_input];

        for(int i = 0; i < user_input; i++) {
                primes[i] = 0;
        }

	int total = sieve(user_input, primes);

	printf("Prime numbers: ");
	for(int i = 0; i < user_input; i++) {
		if(primes[i] == 1) {
			printf("%d ", i);
		}
	}

        printf("\nThere are %d primes between 1 - %d.\n", total, user_input);

	return 0;
}

int sieve(int in, int* prime) {
	int count = 0;
	for (int i = 2; i < in; i++) {
		if(prime[i] == 0) {
			count++;
			prime[i] = 1;
			int mult = 2;
			int prod = i * mult;
			for(int j = 0; prod < in; j++) {
				prime[prod] = -1;
				mult++;
				prod = i * mult;
			}
		}
	}

	return count;
}

