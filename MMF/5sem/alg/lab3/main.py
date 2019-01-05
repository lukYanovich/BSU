import sys
from func import *

if __name__ == "__main__":
    arr = read_file("1")
    print("number of unique elements:", len(set(arr)))

    hash_list_1 = {}
    for i in arr:
        add_hash_1(hash_list_1, i)
    print_dict(hash_list_1)

    hash_list_2 = {}
    for i in arr:
        add_hash_2(hash_list_2, i)
    print_dict(hash_list_2)
    sys.exit(0)
