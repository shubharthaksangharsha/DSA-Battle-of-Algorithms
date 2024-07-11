'''
1. 
* * * * 
* * * * 
* * * * 
* * * * 
'''
print('using for loop')
n = int(input("Enter the number of rows: "))
# n = 4
for i in range(n):
    for j in range(n):
        print("*", end=" ")
    print()

print('using while loop')
n = 4  # Number of rows 
i = 0  # Row counter
while i < n:
    j = 0  # Column counter
    while j < n:
        print("*", end=" ")
        j += 1
    print()  # Move to the next line
    i += 1


