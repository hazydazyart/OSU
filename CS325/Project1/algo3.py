# CS325 Project 1 Group 3
# Megan Conley, Wayne Cordrey, Katie Musick
# Algorithm 3 source code

import sys

def divide_and_conquer(A,low,high):
   if (low-high) == 0:
      return (A[low], [A[low]])
   else: 
      mid=(low+high)/2
     
      #this helps with our crossover suffix
      maxsuffix = 0
      runningtotal = 0
      ilow=mid
      ihigh=mid+1
      for i in xrange(mid, low-1, -1):
       runningtotal += A[i]
       if runningtotal > maxsuffix:
          maxsuffix = runningtotal
          ilow=i

      #this helps with our crossover prefix
      maxprefix = 0
      runningtotal = 0
      for i in xrange(mid+1, high+1):
       runningtotal += A[i]
       if runningtotal > maxprefix:
          maxprefix = runningtotal
          ihigh=i

      maxcrossover = maxsuffix + maxprefix

      (maxleft, leftList) = divide_and_conquer(A,low,mid)
      (maxright, rightList) = divide_and_conquer(A,mid+1,high)

      max_sum = max(maxleft, maxright, maxcrossover)

      if(max_sum == maxleft):
       #print leftList
       return (max_sum, leftList)
      elif(max_sum == maxright):
       #print rightList
       return (max_sum, rightList)
      elif(max_sum == maxcrossover):
       return (max_sum, A[ilow:ihigh+1])
