# Megan Conley
# conleyme@onid.oregonstate.edu
# CS344 400
# Homework5

CC=gcc
CFLAGS=-std=c99 -lm -pthread -lrt -D_POSIX_C_SOURCE -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -g

all: prime_pthread prime_mproc

prime_pthread: prime_pthread.o
	$(CC) $(CFLAGS) -o prime_pthread prime_pthread.o

prime_pthread.o: prime_pthread.c
	$(CC) $(CFLAGS) -c prime_pthread.c

prime_mproc: prime_mproc.o
	$(CC) $(CFLAGS) -o prime_mproc prime_mproc.o

prime_mproc.o: prime_mproc.c
	$(CC) $(CFLAGS) -c prime_mproc.c

clean:
	rm -f *.o prime_mproc prime_pthread 
