from graph import *
import sys

if __name__ == '__main__':
    A = create_matrix_from_file("2")
    print_graph(A)
    print(alg_dekstra(A, 3, 5))
    sys.exit(0)
