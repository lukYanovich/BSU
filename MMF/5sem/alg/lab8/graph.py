import networkx as nx
import matplotlib.pyplot as plt
import scipy
import numpy

inf = float("inf")


def remove_edge(matrix, first_node, second_node):
    matrix[first_node][second_node] = matrix[second_node][first_node] = inf


def add_edge(matrix, first_node, second_node, weight=1):
    matrix[first_node][second_node] = matrix[second_node][first_node] = weight


def remove_node(matrix, node):
    res = []
    for i in range(len(matrix)):
        if matrix[node][i] != 0:
            res.append((node, i))
            matrix[node][i] = matrix[i][node] = 0
    return res


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


def check_double_coherence(matrix, number_of_edges_in_frequent_components=0):
    A = _copy_matrix(matrix)
    n = len(A)
    arr_of_result = []

    def find_and_join_simple_nodes(M, deleted_node=None):
        def find_node_with_min_degree(inaccessible_node):
            temp_min = (inf, 0)
            for i in range(n):
                if i == inaccessible_node or i in deleted_node:
                    continue
                if sum(M[i]) < temp_min[0]:
                    temp_min = sum(M[i]), i
            return temp_min[1]

        for i in range(n):
            if sum(M[i]) == number_of_edges_in_frequent_components:
                second_node = find_node_with_min_degree(i)
                add_edge(M, i, second_node)
                arr_of_result.append((i, second_node))

    flag = True
    while flag is True:
        temp_list = [sum(i) for i in A]
        index_of_node_with_max_degree = temp_list.index(max(temp_list))
        temp_list.clear()
        for i in range(n):
            if A[index_of_node_with_max_degree][i] != 0:
                temp_list.append(i)
        remove_node(A, index_of_node_with_max_degree)
        temp_list1 = []
        for i in arr_of_result:
            temp_list1.append(i[0])
            temp_list1.append(i[1])
        temp_list1 = list(set(temp_list1))
        temp_list1.append(index_of_node_with_max_degree)
        find_and_join_simple_nodes(A, temp_list1)
        res = []
        for i in temp_list:
            _flag = True
            for j in res:
                if i in j[0]:
                    _flag = False
                    break
            if _flag is False:
                continue
            res_bfs = breadth_first_search(A, i)
            _list = [sum(A[i]) for i in range(n) if i in res_bfs]
            _index = res_bfs[_list.index(min(_list), -1)]
            res.append((res_bfs, _index))
        while len(res) != 1:
            res[0][0].extend(res[1][0])
            t_list = res[0][0]
            first_node = res[0][1]
            second_node = res[1][1]
            add_edge(A, first_node, second_node)
            arr_of_result.append((first_node, second_node))
            _list = [sum(A[i]) for i in range(n) if i in t_list]
            _index = t_list[_list.index(min(_list))]
            res[0] = (t_list, _index)
            del res[1]
        _a = set(res[0][0])
        _b = set([i for i in range(n)])
        if len(_a.intersection(_b)) == n:
            flag = False
        else:
            for i in res[0]:
                t = remove_node(A, i)
                arr_of_result.extend(t)
    A = _copy_matrix(matrix)
    for i in arr_of_result:
        add_edge(A, i[0], i[1])
    return A


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
    # has orientation?
    # G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A), create_using=nx.DiGraph)
    G = nx.convert_matrix.from_numpy_matrix(numpy.matrix(A))
    plt.figure(figsize=(5, 4), dpi=100)
    pos = nx.spring_layout(G)
    nx.draw_networkx(G, pos, node_color="red", node_size=500, with_labels=True, arrows=True, arrowsize=20)
    # weight of edges
    # labels = nx.get_edge_attributes(G, "weight")
    # nx.draw_networkx_edge_labels(G, pos=pos, edge_labels=labels)
    plt.axis("off")
    plt.show()
