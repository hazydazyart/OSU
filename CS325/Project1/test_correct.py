# CS325 Project 1 Group 3
# Megan Conley, Wayne Cordrey, Katie Musick
# Project 1 tester code

#!/usr/bin/python

import algo1
import algo2
import algo4A
import algorithm3
import data
import sys

def test():
   in_file = open("MSS_Problems.txt", "r")
   out_file = open("MSS_Results.txt", "w")
   algs = (algo1.enumeration, algo2.better_enumeration, algorithm3.divide_and_conquer, algo4A.linear_time)
   
   fails = 0
   (tests, answers) = data.get_with_answers()

   #test problem set
   print "\nThe following FAILURE/PASS results are based on the MSS_TestSets-1.txt file"
   for t in range(0, len(tests)):
      for a in algs:
	 if a == algorithm3.divide_and_conquer:
	    (sum, list) = a(tests[t], 0, len(tests[t])-1)
	    if answers[t] != sum:
                print "\nFAILURE!"
                print "\t" + str(a)
                print "\tsaid " + str(sum) + " when correct was " + str(answers[t]) + "\n"
                fails += 1
	 else:
	    (sum, list) = a(tests[t])
	    if answers[t] != sum:
                print "\nFAILURE!"
                print "\t" + str(a)
                print "\tsaid " + str(sum) + " when correct was " + str(answers[t]) + "\n"
                fails += 1
		
   print "Done with tests. " + str(fails) + " failures.\n"


def output():
   #Run MSS_Problems.txt on all algorithms, output to MSS_Results.txt
   print "Please check your directory for a MSS_Results.txt file displaying the results\nof MSS_Problems.txt running through each algorithm\n\n"
   in_file = open("MSS_Problems.txt", "r")
   out_file = open("MSS_Results.txt", "w")
   algs = (algo1.enumeration, algo2.better_enumeration, algorithm3.divide_and_conquer, algo4A.linear_time)

   out_file.write("Results for Project 1\n\n")
   for line in in_file:
      if not line.strip():
	 continue
      else:
	 list = (line[1:-3]).split(',')
	 array = map(int, list)
	 for a in algs:
	    out_file.write("Algorithm: " + a.__name__ + "\n")
	    if a == algorithm3.divide_and_conquer:
	       (sum, subarray) = a(array, 0, len(array)-1)
	       out_file.write("Result: " + str(array) + ", " + str(subarray) + ", " + str(sum) + "\n\n")
	    else:
	       (sum, subarray) = a(array)
	       out_file.write("Result: " + str(array) + ", " + str(subarray) + ", " + str(sum) + "\n\n")

if __name__ == "__main__":
   test()
   output()
