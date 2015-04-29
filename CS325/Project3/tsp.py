# CS325 Project 4
# Katie Musick, Wayne Cordrey, Megan Conley

import sys
import os
import math
import time

def distance(A, B):
   dx = int(A[1]) - int(B[1])
   dy = int(A[2]) - int(B[2])
   dist = round(math.sqrt(dx**2 + dy**2))
   return int(dist)

def nearest_neighbor(A, cities):
   neighbor = min(cities, key=lambda x: distance(x, A))
   min_dist = distance(neighbor, A)
   return (neighbor, min_dist)

if __name__ == "__main__":
   input_file = sys.argv[1]
   try:
      in_file = open(input_file, "r")
      out_file_name = input_file + ".tour"
      out_file = open(out_file_name, "a")
      unvisited = []
      total_distance = 0
      for line in in_file:
	 if not line.strip():
	    continue
	 else:
	    city_line = filter(None, line.rstrip().split(' '))
	    unvisited.append(city_line)
      start = unvisited[0]
      unvisited.pop(0)
      tour = [start]
      while unvisited:
	 n,d = nearest_neighbor(tour[-1], unvisited)
	 tour.append(n)
	 unvisited.remove(n)
	 total_distance += d
      end_dist = distance(tour[len(tour)-1], start)
      total_distance += end_dist
      out_file.write(str(total_distance)+"\n")
      for city in tour:
	 out_file.write(city[0] + "\n")

   except ValueError:
      print "There was an error opening " + input_file
