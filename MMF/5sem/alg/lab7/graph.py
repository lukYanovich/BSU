import networkx as nx
import matplotlib.pyplot as plt
import scipy
import numpy

inf = float("inf")


def alg_prima(matrix):
    W = _copy_matrix(matrix)
    n = len(W)

    def swap(a, b):
        for i in range(n):
            for j in range(n):
                if W[i][j] == a:
                    W[i][j] = b

    swap(0, inf)
    for p in range(n):
        for i in range(n):
            for j in range(n):
                if i != j:
                    W[i][j] = min(W[i][j], W[i][p] + W[p][j])
    swap(inf, 0)
    l = [max(i) for i in W]
    return l.index(min(l))


# ----------------------------------------------------------------
# auxiliary function
def _copy_matrix(matrix):
    return [list(i) for i in matrix]


def create_matrix_from_file(filename):
    file = open("tests/" + filename + ".txt")
    A = []
    for line in file:
        arr = line.split()
        A.append(list(map(int, arr)))
    return A


def print_graph(A):
    # G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A), create_using=nx.DiGraph)
    G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A))
    plt.figure(figsize=(5, 4), dpi=100)
    pos = nx.spring_layout(G)
    nx.draw_networkx(G, pos, node_color="red", node_size=500, with_labels=True, arrows=True, arrowsize=20)
    labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos=pos, edge_labels=labels)
    plt.axis("off")
    plt.show()
