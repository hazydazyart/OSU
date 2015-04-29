# Megan Conley
# conleyme@onid.oregonstate.edu
# CS344-400
# Homework 1

CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=check_vowel helloworld odd_even read_file sieve


all: $(PROGS)


check_vowel: check_vowel.o
	$(CC) $(CFLAGS) -o check_vowel check_vowel.o

check_vowel.o: check_vowel.c
	$(CC) $(CFLAGS) -c check_vowel.c

helloworld: helloworld.o
	$(CC) $(CFLAGS) -o helloworld helloworld.o

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c helloworld.c

odd_even: odd_even.o
	$(CC) $(CFLAGS) -o odd_even odd_even.o

odd_even.o: odd_even.c
	$(CC) $(CFLAGS) -c odd_even.c

read_file: read_file.o
	$(CC) $(CFLAGS) -o read_file read_file.o

read_file.o: read_file.c read_file.h
	$(CC) $(CFLAGS) -c read_file.c read_file.h

sieve: sieve.o
	$(CC) $(CFLAGS) -std=c99 -o sieve sieve.o -lm

sieve.o: sieve.c
	$(CC) $(CFLAGS) -std=c99 -c sieve.c

clean:
	rm -f $(PROGS) *.o *~

