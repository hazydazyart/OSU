#Megan Conley
#conleyme@onid.oregonstate.edu
#CS344-400
#Homework 2

import urllib2
import sys
import os

if __name__ == '__main__':

	#Check if there are the correct number of command line arguments 
	if len(sys.argv) != 3:
		print 'Usage: python Problem3.py <webpage> <file name>'

	#Initialize variables
	input = sys.argv[1]
	output = sys.argv[2]
	target = input

	#If the input file does not start with http://, append it
	if input[0:7] != 'http://':
		target = 'http://' + input

	webpage = urllib2.urlopen(target) #open the webpage
	output = open(output, 'w+') #open the output file
	output.write(webpage.read()) #write the wepage to the output file
	output.close() #close the outputfile
