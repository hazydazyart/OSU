#!/usr/bin/python

import sys
import re
import time

def changedp(coins, amt):

	output = []
	temp = [0]
	total_coins = [0]
	
	coin = 0

	for i in range(0, len(coins)):
		output.append(0)

	for i in range(1, amt+1):
		min = 9999999
		for j in range(0, len(coins)):
			if(coins[j] <= i):
				if(temp[i-coins[j]] + 1 < min):
					min = temp[i-coins[j]] + 1
					coin = j
		temp.append(min)
		total_coins.append(coin)

	while(amt > 0):
		output[total_coins[amt]] += 1
		amt -= coins[total_coins[amt]]

	sum = 0

	for i in range(0, len(output)):
		sum += output[i]

	return (output, sum)
'''
if len(sys.argv) < 2:
	print "No input file name found."
else:
	f_name = sys.argv[1].split(".")[0]
	out_f_name = f_name + "change.txt"
	out_f = open(out_f_name, 'a')
	f = open(sys.argv[1], 'r')
	for line in f:
		if not line.strip():
			continue
		else:
			list = line[1:-2].split(',')
			change = map(int, list)
			line = f.next()
			amt = int(line.rstrip())
			(result, sum) = changedp(change, amt)
			stringed = ""
			for a in result:
				stringed += str(a) + ","
			out_f.write("[" + stringed[:-1] + "]\n")
			out_f.write(str(sum) +"\n")
	f.close()
'''

V = [1, 10, 25, 50]
for A in xrange(2000, 3100, 100):
	(results, sum) = changedp(V, A)
	print "A = ", A, "sum = ", sum

