matrix = []

def create_matrix(cols, rows):
    return [[0 for j in range(rows)] for i in range(cols)]

def fill_sequence_matrix(matrix, horizontal=True):
    num = 1
    for i in range(len(matrix)):
        for j in range(len(matrix[i])): 
            matrix[i if horizontal else j][j if horizontal else i] = num
            num += 1
    return matrix

def pprint_matrix(matrix, label="", horizontal=True):
    print(label)
    for i in range(len(matrix)):
        for j in range(len(matrix[i])): print(f"{matrix[i if horizontal else j][j if horizontal else i]:2d}", end=" ")
        print()

def pprint_change_matrix(matrix1, matrix2, label=""):
    if len(matrix2) != len(matrix1): raise Exception("Matricies are not the same sizes!")
    if len(matrix2[0]) != len(matrix1[0]): raise Exception("Matricies are not the same sizes!")
    print(label)
    for i in range(len(matrix1)):
        for j in matrix1[i]: 
            print(f"{j:2d}", end=" ")
        if i == len(matrix1)//2:
            print(" => ", end="")
        else: print("    ", end="")
        for j in matrix2[i]: 
            print(f"{j:2d}", end=" ")
        print()

def transpose(matrix):
    for x in range(len(matrix)//2):
        for y in range(len(matrix[x])):
            matrix[y][x], matrix[y][len(matrix[y])-x-1] = matrix[y][len(matrix[y])-x-1], matrix[y][x]
    return matrix

def rotareLeft(matrix):
    for y in range(len(matrix)):
        for x in range(y, len(matrix[y])):
            matrix[y][x], matrix[x][y] = matrix[x][y], matrix[y][x]
    return matrix

def rotareRight(matrix):
    return transpose(rotareLeft(matrix))

def rotare(matrix):
    return rotareLeft(transpose(matrix))

def rotare180(matrix):
    for i in range(len(matrix)):
        matrix[i][0], matrix[i][len(matrix[i])-1] = matrix[i][len(matrix[i])-1], matrix[i][0]
    matrix[0], matrix[len(matrix)-1] = matrix[len(matrix)-1], matrix[0]
    return matrix

def zeros(matrix):
    return len([0 for i in range(len(matrix)) for j in range(len(matrix[i])) if matrix[i][j] == 0])       

def sum_rows_cols(matrix):
    for y in range(len(matrix)):
        sum_row = 0
        sum_column = 0
        for x in range(len(matrix[y])): 
            sum_row += matrix[y][x]
            sum_column += matrix[x][y]
        print(f"  > {y} row, col: {sum_row:3d} {sum_column:3d}")
        
def matrix_max(matrix):
    m_index = [0, 0]
    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            if (matrix[y][x] > matrix[m_index[0]][m_index[1]]):
                m_index = [y, x]; 
    return m_index

def sum_of_even(matrix):
    even_sum = 0
    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            if matrix[y][x] % 2 == 0: even_sum += matrix[y][x]
    return even_sum
    
def sum_matrix(matrix):
    matrix_sum = 0
    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            matrix_sum+= matrix[y][x]
    return matrix_sum
    
matrix = fill_sequence_matrix(create_matrix(3, 3))
pprint_change_matrix(matrix, transpose(fill_sequence_matrix(create_matrix(3, 3))), "transposed matrix")
pprint_change_matrix(matrix, rotareRight(fill_sequence_matrix(create_matrix(3, 3))), "rotared to the left matrix")
pprint_change_matrix(matrix, rotareLeft(fill_sequence_matrix(create_matrix(3, 3))), "rotared to the right clockwise matrix")
pprint_change_matrix(matrix, rotare(fill_sequence_matrix(create_matrix(3, 3))), "rotared to the right anticlockwise matrix")
pprint_change_matrix(matrix, rotare180(fill_sequence_matrix(create_matrix(3, 3))), "rotared 180 clockwise matrix")
matrix_with_zeros = fill_sequence_matrix(create_matrix(3, 3))
matrix_with_zeros[0][0] = 0
matrix_with_zeros[0][2] = 0
pprint_matrix(matrix_with_zeros, f" zeros in matrix: {zeros(matrix_with_zeros)}")
pprint_matrix(matrix, " sum of rows and cols")
sum_rows_cols(matrix)
pprint_matrix(matrix, f" max in matrix: {matrix_max(matrix)}")
pprint_matrix(matrix, "print horizontal")
pprint_matrix(matrix, "print vertical", False)
pprint_matrix(matrix, f"sum of even: {sum_of_even(matrix)}")
pprint_matrix(matrix, f"sum of matrix: {sum_matrix(matrix)}")