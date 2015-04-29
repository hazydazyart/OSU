# CS325 Project 1 Group 3
# Megan Conley, Wayne Cordrey, Katie Musick
# Algorithm 1 source code

def enumeration(A):
   length = len(A)

   def calc_sum(i, j):
      sum = 0
      for k in range(0, j):
         sum += A[i + k]
      return sum

   max = 0
   max_i = 0
   max_j = 0

   for i in range(0, length):
      for j in range(1, (length - i + 1)):
         sum = calc_sum(i, j)
         if sum > max:
            max = sum
            max_i = i
            max_j = j+i

   sub_a = A[max_i:max_j]
   sub_str = ", ".join(map(str,sub_a))
   array = '[' + sub_str + ']'

   return (max, array)
