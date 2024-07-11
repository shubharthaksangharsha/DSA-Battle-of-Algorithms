# List Comprehension Practice Questions

# Question 1
# Write a list comprehension to generate the first 10 even numbers.
even_numbers = [x for x in range(1, 21) if x % 2 == 0]
print(even_numbers)  # Output: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

# Question 2
# Write a list comprehension to create a list of squares of the numbers from 1 to 15.
squares_numbers = [x**2 for x in range(1, 16)]
print(squares_numbers)  # Output: [1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225]

# Question 3
# Write a list comprehension to flatten a nested list of integers.
# For example, [[1, 2], [3, 4], [5, 6]] should become [1, 2, 3, 4, 5, 6].
nested_list = [[1, 2], [3, 4], [5, 6]]
flattened_list = [y for x in nested_list for y in x]
print(flattened_list)  # Output: [1, 2, 3, 4, 5, 6]

# Question 4
# Write a list comprehension to create a list of all the uppercase letters in a given string.
s = "The Quick Brown Fox"
uppercase_letters = [c for c in s if c.isupper()]
print(uppercase_letters)  # Output: ['T', 'Q', 'B', 'F']

# Question 5
# Write a list comprehension to create a list of all the files in a directory with a specific file extension,
# such as .txt.
import os
files = os.listdir('.')
text_files = [i for i in files if i[-4:] == '.txt']
print(text_files)  # Output will depend on the current directory

