# Create a 2D matrix with user-specified number of rows and columns

def create_matrix():
    rows, columns = list(map(int, input('Give me space seperated rows and columns: ').split()))
    matrix = []
    for i in range(rows):
        row = []
        for j in range(columns):
            row.append(0)
        matrix.append(row)
    return matrix

# Example usage
matrix = create_matrix()
print(matrix)

