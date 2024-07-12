from typing import List

def rotate_array_by_one(arr: List[int]) -> None:
  """
  Rotates a given array by one place to the left.

  Args:
    arr: A list of numbers.

  Returns:
    None. The array is modified in-place.
  """
  #Optimal Solution: TC: O(N), SC: O(1)
  temp = arr[0]
  for i in range(len(arr) - 1):
    arr[i] = arr[i+1]
  arr[-1] = temp
  return arr


if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  rotate_array_by_one(arr)
  print(f'Array after rotating by one place: {arr}')
