import networkx as nx
import matplotlib.pyplot as plt
import scipy
import numpy

inf = float("inf")


def alg_dekstra(matrix, start_node=0, finish_node=None):
    A = _copy_matrix(matrix)
    used = [False for i in range(0, len(A))]
    result = [(inf, []) for i in range(0, len(A))]
    result[start_node] = (0, [start_node])

    def check_labels(active_label):
        for j in range(0, len(A[active_label])):
            if A[active_label][j] != 0 and used[j] is False:
                temp_value = result[active_label][0] + A[active_label][j]
                if temp_value < result[j][0]:
                    result[j] = (temp_value, list(result[active_label][1]))
                    result[j][1].append(j)
        used[active_label] = True

    check_labels(start_node)

    # print(result)

    def find_min_unused_label():
        temp_list = [result[i][0] for i in range(0, len(A))]
        temp_min = inf
        for i in range(0, len(temp_list)):
            if temp_list[i] < temp_min and used[i] is False:
                temp_min = temp_list[i]
        for i in range(0, len(temp_list)):
            if temp_list[i] == temp_min and used[i] is False:
                return i

    while False in used:
        active_label = find_min_unused_label()
        check_labels(active_label)
    if finish_node is not None:
        return result[finish_node]
    else:
        return result


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
