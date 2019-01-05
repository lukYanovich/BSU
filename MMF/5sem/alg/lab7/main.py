from graph import *
import sys

if __name__ == '__main__':
    A = create_matrix_from_file("1")
    print_graph(A)
    print(alg_prima(A))
    sys.exit(0)
