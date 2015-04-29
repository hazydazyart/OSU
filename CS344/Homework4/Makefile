# Megan Conley
# conleyme@onid.oregonstate.edu
# CS344-400
# Homework4

CC=gcc
CFLAGS=-std=c99 -D_POSIX_C_SOURCE -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement 

pipeline: pipeline.o
	$(CC) $(CFLAGS) -o pipeline pipeline.o

pipeline.o: pipeline.c
	$(CC) $(CFLAGS) -c pipeline.c

uniquify: uniquify.o
	$(CC) $(CFLAGS) -o uniquify uniquify.o 

uniquify.o: uniquify.c
	$(CC) $(CFLAGS) -c uniquify.c

all: pipeline uniquify

testpipe:
	rm -f outfile1
	rm -f outfile2
	rm -f outfile3
	rm -f outfile4
	./pipetest -f outfile2 < /usr/local/classes/eecs/spring2014/cs311/src/Homework5/Problem1/words.txt > outfile1
	bash pipeline.bash -f outfile4 < /usr/local/classes/eecs/spring2014/cs311/src/Homework5/Problem1/words.txt > outfile3
	diff outfile2 outfile4

testuniq:
	rm -f uniq1
	rm -f uniq2
	./uniquify -n 5 < /usr/local/classes/eecs/spring2014/cs311/src/Homework5/Problem1/websters.txt > uniq1
	bash uniquify.bash -n 5 < /usr/local/classes/eecs/spring2014/cs311/src/Homework5/Problem1/websters.txt > uniq2
	diff uniq1 uniq2

test: testpipe testuniq

clean:
	rm -f *.o pipeline
	rm -f *.o uniquify
