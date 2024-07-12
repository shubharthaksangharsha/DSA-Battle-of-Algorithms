#Write code of finding union of 2 sorted arrays
from typing import List

def find_union(arr1: List[int], arr2: List[int]) -> List[int]:
  """
  Finds the union of two sorted arrays.

  Args:
    arr1: The first sorted array.
    arr2: The second sorted array.

  Returns:
    A new sorted array containing the union of arr1 and arr2.
  """
  #Optimal Solution - TC: O(M+N), SC: O(M+N)
  union = []
  i, j = 0, 0
  while i < len(arr1) and j < len(arr2):
    if arr1[i] < arr2[j]:
      union.append(arr1[i])
      i += 1
    elif arr1[i] > arr2[j]:
      union.append(arr2[j])
      j += 1
    else:
      union.append(arr1[i])
      i += 1
      j += 1

  # Add remaining elements from arr1
  while i < len(arr1):
    union.append(arr1[i])
    i += 1

  # Add remaining elements from arr2
  while j < len(arr2):
    union.append(arr2[j])
    j += 1

  return union

if __name__ == '__main__':
  arr1 = list(map(int, input('Enter the elements of the first array space seperated: ').split()))
  arr2 = list(map(int, input('Enter the elements of the second array space seperated: ').split()))
  print(f'Union of the two arrays: {find_union(arr1, arr2)}')
