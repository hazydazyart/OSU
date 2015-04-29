# CS325 Project 1 Group 3
# Megan Conley, Wayne Cordrey, Katie Musick
# Algorithm 4 source code

#!/usr/bin/python
 
import random
import time

def linear_time(A):
     
    bestNow = 0
    bestSoFar = 0
    bestStartIndexNow = 0
    bestStartIndexSoFar = 0
    bestStopIndexSoFar = 0
    sumvalue =0
    for i in range(len(A)):
     
        sumvalue = bestNow + A[i]
     

        if (sumvalue > 0):
            if(bestNow==0):
                bestStartIndexNow = i 
            bestNow = sumvalue
        else:
            bestNow = 0
     
        if(bestNow > bestSoFar):
            bestSoFar = bestNow
            bestStopIndexSoFar = i+1
            bestStartIndexSoFar = bestStartIndexNow
              
    sub_a = A[bestStartIndexSoFar:bestStopIndexSoFar]
    sub_str = ", ".join(map(str,sub_a))
    array = '[' + sub_str + ']'
    return (bestSoFar, array)

def main():
    for i in range(0,11):
	list = random.sample(range(11000),10000)
	t1 = time.time()
	linear_time(list)
	t2 = time.time()
	totaltime = t2 - t1
	print totaltime

if __name__ == '__main__':
    main()

