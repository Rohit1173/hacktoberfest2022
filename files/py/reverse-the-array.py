def reverseList(A, start, end):
   if start >= end:
      return
   A[start], A[end] = A[end], A[start]
   reverseList(A, start+1, end-1)


# Driver function to test above function
A = [10, 20, 30, 40, 50]
reverseList(A, 0, 4)
print(A)
