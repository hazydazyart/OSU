#Megan Conley
#conleyme@onid.oregonstate.edu
#CS344-400
#Homework 2

import os
import subprocess

if __name__ == '__main__':

	command = 'who'

	# Uses popen module to enter command and pipe output
	# I used http://www.saltycrane.com/blog/2008/09/how-get-stdout-and-stderr-using-python-subprocess-module/ as a reference for this problem.
	# That site has a much more complex example. For this assignment, since the only specification is to print the output of 'who',
	# I only piped stdout. The support for stdin and sterr will likely be useful in future assignments, but this one is hard coded to do
	# one task and do it correctly.
	popen_cmd = subprocess.Popen(command, stdout=subprocess.PIPE)

	#Prints the output that was piped through the Popen command
	output = popen_cmd.stdout.read()

	print output
