#Write code for moving zeros to end of array
from typing import List

def move_zeros_to_end(arr: List[int]) -> None:
  """
  Moves all zeros to the end of a given array.

  Args:
    arr: A list of numbers.

  Returns:
    None. The array is modified in-place.
  """
  #Optimal Solution: TC: O(N), SC: O(1)
  n = len(arr)
  i = 0
  for j in range(n):
    if arr[j] != 0:
      arr[i], arr[j] = arr[j], arr[i]   
      i += 1
  return arr

if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  move_zeros_to_end(arr)
  print(f'Array after moving zeros to the end: {arr}')