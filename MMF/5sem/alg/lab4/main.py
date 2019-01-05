from graph import *
import sys

'''
    "a 0 1" - add edge between nodes 0 and 1
    "d 0 1" - delete edge between nodes 0 and 1
    "a" - add a node
    "d 1" - delete a node 1, if that does exist
    
    return -1: the function failed
'''

if __name__ == '__main__':
    A = create_matrix_from_file("2")
    print_graph(A)
    while True:
        line = input("enter command: ")
        if line == "exit":
            sys.exit()
        input_line = line.split()
        flag = True
        if len(input_line) == 3:
            if input_line[0] == "a":
                add_edge(A, int(input_line[1]), int(input_line[2]))
                flag = False
            elif input_line[0] == "d":
                remove_edge(A, int(input_line[1]), int(input_line[2]))
                flag = False
        elif len(input_line) == 2 and input_line[0] == "d":
            remove_node(A, int(input_line[1]))
            flag = False
        elif len(input_line) == 1 and input_line[0] == "a":
            add_node(A)
            flag = False
        if flag:
            continue

        # 1
        print("euler_path:\n", find_euler_path(A), end="\n")
        # 2
        components = []
        list_of_nodes = [i for i in range(0, len(A))]
        while len(list_of_nodes) > 0:
            temp_list = breadth_first_search(A, list_of_nodes[0])
            components.append(temp_list)
            list_of_nodes = list(set(list_of_nodes) - set(temp_list))
        print("components:\n", components, end="\n")
        # 3
        print("parts of graph:")
        if len(components) == 1:
            print(check_on_bipartite_graph(A))
        else:
            print("none")
        print("\n")
        print_graph(A)
