import sys
from func import *


def find_number_of_moves(_n, finish):
    n = min(_n, max(finish) + 1)
    field = [[0 for i in range(n + 2)] for j in range(n + 2)]
    field[2][2] = 1
    for i in range(2, n + 2):
        for j in range(2, n + 2):
            field[i][j] += 1*(field[i - 2][j - 1] + field[i - 1][j - 2])
    print_matrix(field, 2, 2)
    return field[finish[0] + 2][finish[1] + 2]


if __name__ == "__main__":
    print("введите размер поля и координаты конца(всё через пробел)")
    str_in = input().split()
    n, finish = int(str_in[0]), (int(str_in[1]), int(str_in[2]))
    print(find_number_of_moves(n, finish))
    sys.exit(0)
