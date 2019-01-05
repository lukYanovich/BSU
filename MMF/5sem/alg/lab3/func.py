import operator
import math


def my_hash(key):
    # return key % 857
    key ^= (key << 13)
    key ^= (key >> 17)
    key ^= (key << 5)
    return key


def add_hash_1(hash_list, value):
    key_hash = my_hash(value)
    if key_hash in hash_list:
        if value not in hash_list[key_hash]:
            hash_list[key_hash].append(value)
    else:
        hash_list[key_hash] = [value]


def add_hash_2(hash_list, value):
    key_hash = my_hash(value)
    if key_hash in hash_list and hash_list[key_hash] != value:
        while key_hash in hash_list:
            key_hash += 1
    hash_list[key_hash] = value


# ----------------------------------------------------------------
# auxiliary function


def read_file(filename):
    file = open("tests/" + filename + ".txt")
    for line in file:
        arr = line.split()
        return list(map(int, arr))


def print_dict(my_dict):
    sorted_my_dict = sorted(my_dict.items(), key=operator.itemgetter(0))
    print(sorted_my_dict)
