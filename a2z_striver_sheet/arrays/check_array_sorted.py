
def is_sorted(arr: list[int]) -> bool:
  """
  Checks if a given array is sorted in ascending order.

  Args:
    arr: A list of numbers.

  Returns:
    True if the array is sorted, False otherwise.
  """
  #Optimal Solution - TC: O(N), SC: O(1)
  for i in range(1, len(arr)):
    if arr[i] < arr[i -1]:
      return False 
  return True

if __name__ == '__main__':
  arr = list(map(int, input('Enter the elements space seperated: ').split()))
  if is_sorted(arr):
    print('Array is sorted')
  else:
    print('Array is not sorted')

