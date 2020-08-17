import sys

inf = float("inf")


def canonical(number, p=26):
    if number == inf or number == -inf:
        return inf
    while number < 0:
        number += p
    while number >= p:
        number -= p
    return number


def sum(P, Q):
    s, x, y = 0, 0, 1
    x_r, y_r = 0, 0
    if P[x] == inf and P[y] == inf:
        x_r, y_r = Q[x], Q[y]
    elif Q[x] == inf and Q[y] == inf:
        x_r, y_r = P[x], P[y]
    else:
        if P == Q:
            s = division(3 * P[x] ** 2 + a, 2 * P[y])
        else:
            s = division(Q[y] - P[y], Q[x] - P[x])
        x_r = s ** 2 - P[x] - Q[x]
        y_r = s * (P[x] - x_r) - P[y]
    return canonical(x_r, p), canonical(y_r, p)


def division(a, b):
    A = 1
    b = canonical(b, p)
    if b == 0:
        return inf
    while (b * A) % p != 1:
        A += 1
    return canonical(a * A, p)


def deshifration(str, k):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    result = ""
    for i in range(len(str)):
        for j in range(len(alphabet)):
            if str[i] == alphabet[j]:
                result += alphabet[canonical(j - k)]
                break
    return result


a = 3
p = 11

if __name__ == '__main__':
    P = 1, 9
    P_a = 153, 284
    P_b = 149, 40
    # word = "yjgtgctgaqw"
    word = "thtwwdeljszxpezolj"

    n, n_a, n_b, n_a_b = 0, 1, 1, 1
    flag_a, flag_b, flag = True, True, True
    P_now = P

    i = 1
    print(i, P)
    i += 1
    while n * n_a * n_b * n_a_b == 0:
        P_now = sum(P_now, P)
        print(i, P_now)
        '''
        if P_now == P_a and flag_a:
            n_a = i
            flag_a = False
        elif P_now == P_b and flag_b:
            n_b = i
            flag_b = False
        '''
        if P_now == (inf, inf) and flag:
            n = i
            flag = False
        '''
        n_a_b = n_a * n_b
        if n_a_b != i:
            n_a_b = 0
        '''
        i += 1
    print("n:", n)
    # print("n_a:", n_a, ", n_b:", n_b)
    # k = P_now[0]
    # print("k:", k, "or", canonical(k))
    # print(deshifration(word, k))
    sys.exit(0)
