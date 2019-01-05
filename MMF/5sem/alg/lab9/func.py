# ----------------------------------------------------------------
# auxiliary function


def read_file(filename):
    file = open("tests/" + filename + ".txt")
    A = []
    for line in file:
        arr = line.split()
        A.append(list(map(int, arr)))
    for i in A:
        if len(i) != len(A[0]):
            raise Exception("invalid input file")
    result = []
    for i in A:
        for j in range(i[0]):
            temp = (i[1], i[2])
            result.append(temp)
    return result


def print_matrix(matrix, start_i=0, start_j=0):
    for i in range(start_i, len(matrix)):
        for j in range(start_j, len(matrix[i])):
            print(matrix[i][j], end=" ")
        print()
