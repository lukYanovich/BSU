import networkx as nx
import matplotlib.pyplot as plt
import scipy
import numpy

count_of_add_node = 0
inf = float("inf")


def remove_edge(matrix, first_node, second_node):
    matrix[first_node][second_node] = matrix[second_node][first_node] = inf


def add_edge(matrix, first_node, second_node, weight=inf):
    matrix[first_node][second_node] = matrix[second_node][first_node] = weight


def remove_node(matrix, node):
    del matrix[node]
    for i in matrix:
        del i[node]


def add_node(matrix):
    for i in matrix:
        i.append(inf)
    matrix.append([inf] * len(matrix[0]))
    global count_of_add_node
    if count_of_add_node < 2:
        remove_node(matrix, 0)
        count_of_add_node += 1


def alg_prima(matrix):
    A = _copy_matrix(matrix)
    F = _create_clear_matrix(matrix)

    # find edge with min weight, that is near tree
    def find_edge(m1, arr):
        arr_min = []
        for i in range(0, len(m1)):
            for j in range(0, len(m1[i])):
                if (j not in arr and i in arr) or (j in arr and i not in arr) \
                        and m1[i][j] is not inf and F[i][j] != m1[i][j]:
                    arr_min.append((i, j))
        min_val = inf
        result = (0, 0)
        for i in arr_min:
            if m1[i[0]][i[1]] < min_val:
                min_val, result = m1[i[0]][i[1]], (i[0], i[1])
        return result

    used = [False for i in range(0, len(matrix))]
    while False in used:
        arr = []
        for i in range(0, len(used)):
            if used[i] is True:
                arr.append(i)
        edge = find_edge(A, arr)
        used[edge[0]] = used[edge[1]] = True
        F[edge[0]][edge[1]], F[edge[1]][edge[0]] = A[edge[0]][edge[1]], A[edge[1]][edge[0]]
    return F


def alg_crask(matrix):
    A = _copy_matrix(matrix)
    F = _create_clear_matrix(matrix)
    used = [False for i in range(0, len(A))]

    # find edge with min weight
    def find_edge(m1, m2):
        arr_min = []
        for i in range(0, len(m1) - 1):
            for j in range(i + 1, len(m1[i])):
                if m2[i][j] is inf and m1[i][j] is not inf and m2[i][j] != m1[i][j]:
                    arr_min.append((i, j))
        min_val = inf
        result = (0, 0)
        for i in arr_min:
            if m1[i[0]][i[1]] < min_val and (used[i[0]] is False or used[i[1]] is False):
                min_val, result = m1[i[0]][i[1]], (i[0], i[1])
        return result

    while False in used:
        edge = find_edge(A, F)
        used[edge[0]] = used[edge[1]] = True
        F[edge[0]][edge[1]], F[edge[1]][edge[0]] = A[edge[0]][edge[1]], A[edge[1]][edge[0]]

    def find_last(m1, m2):
        arr_min = []
        for i in range(0, len(m1) - 1):
            for j in range(i + 1, len(m1[i])):
                if m2[i][j] is inf and m1[i][j] is not inf and m2[i][j] != m1[i][j]:
                    arr_min.append((i, j))
        min_val = inf
        result = (0, 0)
        for i in arr_min:
            if m1[i[0]][i[1]] < min_val:  # and (used[i[0]] is False or used[i[1]] is False):
                min_val, result = m1[i[0]][i[1]], (i[0], i[1])
        return result

    def number_of_edges(m):
        number = 0
        for i in range(0, len(m) - 1):
            for j in range(i + 1, len(m[i])):
                if m[i][j] not in (0, inf):
                    number += 1
        return number

    while number_of_edges(F) != len(F) - 1:
        edge = find_last(A, F)
        F[edge[0]][edge[1]], F[edge[1]][edge[0]] = A[edge[0]][edge[1]], A[edge[1]][edge[0]]
    return F


def _create_clear_matrix(matrix):
    F = []
    for i in matrix:
        _list = [inf for i in range(0, len(matrix))]
        F.append(_list)
    return F


def _copy_matrix(matrix):
    A = []
    for i in matrix:
        temp_list = list(i)
        A.append(temp_list)
    return A


def create_matrix_from_file(filename):
    file = open("tests/" + filename + ".txt")
    A = []
    for line in file:
        arr = line.split()
        A.append(list(map(int, arr)))
    return A


def print_graph(A):
    for i in range(len(A)):
        for j in range(len(A[i])):
            if A[i][j] is inf:
                A[i][j] = 0
    # has orientation?
    # G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A), create_using=nx.DiGraph)
    G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A))
    plt.figure(figsize=(5, 4), dpi=100)
    pos = nx.spring_layout(G)
    nx.draw_networkx(G, pos, node_color="red", node_size=500, with_labels=True, arrows=True, arrowsize=20)
    # weight of edges
    labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos=pos, edge_labels=labels)
    plt.axis("off")
    plt.show()
