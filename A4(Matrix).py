# Print the matrix
def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print("\t", matrix[i][j], end=" ")
        print("\n")

# Initialize the matrix to zero
def init_matrix(matrix, m, n):
    matrix = [[0 for j in range(0, n)] for i in range(0, m)]
    return matrix

# Input the Matrix elements
def read_matrix():
    mat = []
    r = int(input("Enter the number of rows for Matrix: "))
    c = int(input("Enter the number of columns for Matrix: "))
    mat = init_matrix(mat, r, c)  # matrix 1 initialization with 0s
    for i in range(0, r):
        for j in range(0, c):
            mat[i][j] = int(input("Enter an element: "))
    return mat, r, c

# Addition of two matrices
def mat_add(m1, m2, res, m, n):
    for i in range(0, m):
        for j in range(0, n):
            res[i][j] = m1[i][j] + m2[i][j]
    return res

# Subtraction of two matrices
def mat_sub(m1, m2, res, m, n):
    for i in range(0, m):
        for j in range(0, n):
            res[i][j] = m1[i][j] - m2[i][j]
    return res

# Multiplication of two matrices
def mat_mul(m1, m2, res, r1, c1, c2):
    for i in range(0, r1):
        for k in range(0, c2):
            for j in range(0, c1):
                res[i][k] += m1[i][j] * m2[j][k]
    return res

# Transpose of matrix1
def trans_mat(m1, res, r1, c1):
    for i in range(0, r1):
        for j in range(0, c1):
            res[j][i] = m1[i][j]
    return res

matrix1 = []
matrix2 = []
res_matrix = []

print("******PRACTICAL NO-04(A-9) MATRIX OPERATIONS******")
print(" First Matrix : ")
matrix1, r1, c1 = read_matrix()

print(" Second Matrix : ")
matrix2, r2, c2 = read_matrix()

res_matrix = init_matrix(res_matrix, r1, c2)  # matrix for storing result

# print input matrices
print(" Matrix 1")
print_matrix(matrix1)
print(" Matrix 2")
print_matrix(matrix2)

while True:
    print("/*********MENU********/")
    print(" 1. Addition of two matrices ")
    print(" 2. Subtraction of two matrices ")
    print(" 3. Multiplication of two matrices ")
    print(" 4. Transpose of a matrix ")
    print(" 5. Exit")

    choice = int(input("Enter Your Choice : "))

    if choice == 1:
        # printing Addition matrix
        if r1 == r2 and c1 == c2:
            print("Resultant matrix after addition:")
            res_matrix = mat_add(matrix1, matrix2, res_matrix, r1, c1)
            print_matrix(res_matrix)
        else:
            print("Addition can't be performed")

    elif choice == 2:
        if r1 == r2 and c1 == c2:
            print("Resultant matrix after subtraction:")
            res_matrix = mat_sub(matrix1, matrix2, res_matrix, r1, c1)
            print_matrix(res_matrix)
        else:
            print("Subtraction can't be performed")

    elif choice == 3:
        if c1 == r2:
            print("Resultant matrix after multiplication:")
            res_matrix = mat_mul(matrix1, matrix2, res_matrix, r1, c1, c2)
            print_matrix(res_matrix)
        else:
            print("Multiplication can't be performed")

    elif choice == 4:
        print("Transpose of First Matrix is:")
        res_matrix1 = []
        res_matrix1 = init_matrix(res_matrix1, c1, r1) 
        res_matrix = trans_mat(matrix1, res_matrix1, r1, c1)
        print_matrix(res_matrix)

    elif choice == 5:
        print("Terminated successfully")
        break

    else:
        print("Wrong choice")
