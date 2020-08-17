import sys
import math
import numpy as np

inf = float("inf")


def find_l(k, mod):
    l = 1
    while (k * l) % mod != 1:
        l += 1
    return l


def deshifration(arr, l, n):
    alphabet = "** abcdefghijklmnopqrstuvwxyz"
    result = ""
    arr = [i ** l % n % len(alphabet) for i in arr]
    for i in range(len(arr)):
        for j in range(2, len(alphabet)):
            if arr[i] == j:
                result += alphabet[j]
                break
    return result


def get_primes_multipliers(number):
    multipliers = []
    i, max = 2, int(math.sqrt(number) + 1)
    while i < max:
        if number % i == 0:
            number /= i
            multipliers.append(i)
            i -= 1
        i += 1
    if number != 1:
        multipliers.append(int(number))
    return multipliers


def fi(n):
    multipliers = get_primes_multipliers(n)
    print("mult:", multipliers)
    elem = multipliers[0]
    fi = [elem]
    for i in range(1, len(multipliers)):
        if elem == multipliers[i]:
            fi[-1] *= elem
        else:
            elem = multipliers[i]
            fi.append(elem)
    fi = [i - 1 for i in fi]
    fi = np.prod(fi)
    return fi


if __name__ == '__main__':
    n, k = 1739, 523
    arr = [973, 170, 973, 718, 1224, 718, 973, 131, 682, 553, 897, 1224, 170, 1228]
    fi = fi(n)
    print("fi:", fi)
    l = find_l(k, fi)
    print("l:", l)
    print(deshifration(arr, l, n))
    sys.exit(0)
