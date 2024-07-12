from typing import List

def rotate_array_by_k(arr: List[int], k: int) -> None:
  """
  Rotates a given array by k places to the left.

  Args:
    arr: A list of numbers.
    k: The number of places to rotate the array.

  Returns:
    None. The array is modified in-place.
  """
  n = len(arr)
  k %= n  # Handle cases where k is greater than the array length

  # Reverse the entire array
  reverse_array(arr, 0, n - 1)

  # Reverse the first k elements
  reverse_array(arr, 0, k - 1)

  # Reverse the remaining elements
  reverse_array(arr, k, n - 1)

  return arr

def reverse_array(arr: List[int], start: int, end: int) -> None:
  """
  Reverses a portion of the array in-place.

  Args:
    arr: The array to be reversed.
    start: The starting index of the portion to be reversed.
    end: The ending index of the portion to be reversed.

  Returns:
    None. The array is modified in-place.
  """
  while start < end:
    arr[start], arr[end] = arr[end], arr[start]
    start += 1
    end -= 1

if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  k = int(input('Enter the number of places to rotate: '))
  rotate_array_by_k(arr, k)
  print(f'Array after rotating by {k} places: {arr}')
