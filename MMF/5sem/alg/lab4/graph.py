import networkx as nx
import matplotlib.pyplot as plt
import scipy
import numpy


def remove_edge(matrix, first_node, second_node):
    matrix[first_node][second_node] = matrix[second_node][first_node] = 0


def add_edge(matrix, first_node, second_node):
    matrix[first_node][second_node] = matrix[second_node][first_node] = 1


def remove_node(matrix, node):
    del matrix[node]
    for i in matrix:
        del i[node]


def add_node(matrix):
    for i in matrix:
        i.append(0)
    matrix.append([0] * len(matrix[0]))


def find_euler_path(matrix):
    A = _copy_matrix(matrix)
    # check theorem
    for i in A:
        if sum(i) % 2 != 0:
            return -1

    stack = []
    answer = []
    # find start node
    start_node = 0
    for i in range(0, len(A)):
        if sum(A[i]) % 2 == 1:
            start_node = i
            break
        elif sum(A[i]) != 0:
            start_node = i

    # alg
    stack.append(start_node)
    while len(stack) > 0:
        v = stack[len(stack) - 1]
        if sum(A[v]) == 0:
            stack.pop()
            answer.append(v)
        else:
            index = 0
            for i in range(0, len(A[v])):
                if A[v][i] == 1:
                    index = i
                    break
            remove_edge(A, v, index)
            stack.append(index)
    return answer


def breadth_first_search(matrix, start_node=0):
    A = _copy_matrix(matrix)
    n = len(A)
    queue = [start_node]
    used = [False] * n
    used[start_node] = True
    while len(queue) > 0:
        v = int(queue[0])
        del queue[0]
        for i in range(0, n):
            if A[v][i] != 0 and not used[i]:
                used[i] = True
                queue.append(i)
    answer = []
    for i in range(0, n):
        if used[i]:
            answer.append(i)
    return answer


def check_on_bipartite_graph(matrix, start_node=0):
    A = _copy_matrix(matrix)
    n = len(A)
    list_of_nodes = [i for i in range(0, n)]
    # 0-no color, 1-first color, 2-second color
    color = [0] * n
    color[0] = 1
    for i in range(0, len(A)):
        for j in range(0, len(A[i])):
            if A[i][j] != 0:
                if color[i] == color[j]:
                    return -1
                elif color[j] == 0:
                    if color[i] == 1:
                        color[j] = 2
                    elif color[i] == 2:
                        color[j] = 1
    part1 = []
    part2 = []
    for i in range(0, n):
        if color[i] == 1:
            part1.append(i)
        elif color[i] == 2:
            part2.append(i)
    return (part1, part2)


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
    G = nx.from_numpy_matrix(numpy.matrix(A))
    w = 5
    h = 4
    d = 70
    plt.figure(figsize=(w, h), dpi=d)
    nx.draw_networkx(G, node_color="red", node_size=500, with_labels=True)
    plt.axis("off")
    plt.show()
