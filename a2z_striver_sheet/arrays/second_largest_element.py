from typing import List 

def find_second_largest(arr: List[int]):
  """
  Finds the second largest element in a given array.

  Args:
    arr: A list of numbers.

  Returns:
    The second largest element in the array, or None if the array has less than two elements.
  """
  #Optimal Solution - TC: O(N), SC: O(1)
  largest, second_largest = arr[0], -1
  for i in range(len(arr)):
    if arr[i] == largest:
      continue
    if arr[i] > largest:
      second_largest = largest
      largest = arr[i]
    elif arr[i] > second_largest:
      second_largest = arr[i]

  return second_largest

#   Brute Force - sorting TC: O(nlogn) + O(N) = NlogN, SC: O(1)
#   arr.sort()
#   ans = 0; largest = arr[-1]
#   for i in range(len(arr)-2, 0, -1):
#     if arr[i] != largest:
#       ans = arr[i]
#       break
#   return ans 

#  Better Solution - TC: O(N + N) , SC: O(1)
#   largest = arr[0]
#   for i in range(len(arr)):
#     if arr[i] > largest: 
#       largest = arr[i]

#   second_largest =  -1 
#   for i in range(len(arr)):
#     if arr[i] > second_largest and arr[i] != largest:
#       second_largest = arr[i]
#   return second_largest
    

    
  

if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  print(find_second_largest(arr))
    