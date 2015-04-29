# CS325 Project 1 Group 3
# Megan Conley, Wayne Cordrey, Katie Musick
# Algorithm 2 source code

def better_enumeration(A):

   length = len(A)
   max = 0
   max_i = 0
   max_j = 0

   for i in range(0, length):
      sum = 0
      for j in range(1, (length - i + 1)):
         sum += A[i + j - 1]
         if sum > max:
            max = sum
            max_i = i
            max_j = j+i

   sub_a = A[max_i:max_j]
   sub_str = ", ".join(map(str,sub_a))
   array = '[' + sub_str + ']'

   return (max, array)
