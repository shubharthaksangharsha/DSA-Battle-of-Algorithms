#Remove Duplicates from sorted array
from typing import List

def remove_duplicates(arr: List[int]) -> int:
  """
  Removes duplicates from a sorted array in-place.

  Args:
    arr: A sorted list of numbers.

  Returns:
    The length of the array after removing duplicates.
  """
  #Optimal Solution: TC: O(N), O(1)
  if not arr:
    return 0
  i , j = 0 , 0 
  while i < len(arr):
    if arr[i] == arr[j]:
      i += 1 
    else:
      arr[j+1] = arr[i]
      j += 1
      i += 1
  return j + 1

if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  n = remove_duplicates(arr)
  print(f'Array after removing duplicates: {arr[:n]}')
