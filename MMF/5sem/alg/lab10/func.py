# ----------------------------------------------------------------
# auxiliary function


def print_matrix(matrix, start_i=0, start_j=0):
    for i in range(start_i, len(matrix)):
        for j in range(start_j, len(matrix[i])):
            print(matrix[i][j], end=" ")
        print()
