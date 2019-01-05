from graph import *
import sys

'''
    "a 0 1" - add edge between nodes 0 and 1
    "d 0 1" - delete edge between nodes 0 and 1
    "a" - add a node
    "d 1" - delete a node 1, if that does exist
    
    return -1: the function failed
'''


def print_matr(A):
    for i in range(0, len(A)):
        for j in range(0, len(A[i])):
            print(A[i][j], end=" ")
        print()


if __name__ == '__main__':
    A = [[inf, inf], [inf, inf]]
    #'''
    add_node(A)
    add_node(A)
    add_node(A)
    add_node(A)
    add_edge(A, 0, 1, weight=7)
    add_edge(A, 0, 3, weight=2)
    add_edge(A, 1, 2, weight=5)
    add_edge(A, 1, 3, weight=1)
    add_edge(A, 2, 3, weight=1)
    '''
    add_node(A)
    add_node(A)
    add_node(A)
    add_node(A)
    add_node(A)
    add_node(A)
    add_node(A)
    add_edge(A, 0, 3, weight=5)
    add_edge(A, 0, 1, weight=7)
    add_edge(A, 1, 2, weight=8)
    add_edge(A, 2, 4, weight=5)
    add_edge(A, 1, 4, weight=7)
    add_edge(A, 1, 3, weight=9)
    add_edge(A, 3, 4, weight=15)
    add_edge(A, 3, 5, weight=6)
    add_edge(A, 4, 5, weight=8)
    add_edge(A, 5, 6, weight=11)
    add_edge(A, 4, 6, weight=9)
    #'''

    # print("source matrix:")
    # print_matr(A)
    # print_graph(A)

    print("\nalg prima:")
    alg_prima = alg_prima(A)
    # print_matr(alg_prima)
    print_graph(alg_prima)

    # print("\nalg_crask:")
    alg_crask = alg_crask(A)
    # print_matr(alg_crask)
    print_graph(alg_crask)
    sys.exit()
