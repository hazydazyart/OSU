#Megan Conley
#conleyme@onid.oregonstate.edu
#CS344-400
#Homework 2

import os
import sys
import getopt
import math

#Function to check if a number is prime
#Arguments: int
#Return: boolean
#Notes: a much improved function to find primes using the sieve, this time using the
#square root hint from Homework 1.
def isPrime(input):
	for i in range (2, int(math.sqrt(input))+1):
		if (input % i) == 0:
			return False
	return True

#Function which finds and prints nth prime
#Arguments: passed from command line
#Return: none
def findPrime(argv):

	count = 0
	val = 2

	if len(sys.argv) != 2:
		print 'Usage: python Problem4.py <number>'
		sys.exit(2)

	userInput = int(sys.argv[1])

	#Loops until the number of primes founds reaches the user's input upper bound and prints it
	while count < userInput:
		if isPrime(val):
			count += 1
			if count == userInput:
				print 'The ' +  str(userInput) + 'th prime is ' + str(val)
		val += 1

if __name__ == '__main__':
	findPrime(sys.argv[1:])

