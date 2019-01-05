import sys


def find_matrix_of_palindromes(S):
    n = len(S)
    L = [[-1 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j:
                L[i][j] = 1
            elif i > j:
                L[i][j] = 0

    def corect_matrix(left, right):
        if L[left][right] == -1:
            if S[left] == S[right]:
                L[left][right] = corect_matrix(left + 1, right - 1) + 2
            else:
                L[left][right] = max(corect_matrix(left + 1, right), corect_matrix(left, right - 1))
        return L[left][right]

    return L, corect_matrix(0, n - 1)


def palindrome_recovery(L, S, left, right, pal_left, pal_right):
    palindrome = list("_" * L[0][len(S) - 1])
    while left <= right:
        if left == right and L[left][right] == 1:
            palindrome[pal_left] = S[left]
            pal_left, left = pal_left + 1, left + 1
        else:
            if S[left] == S[right]:
                palindrome[pal_left], palindrome[pal_right] = S[left], S[right]
                pal_left, pal_right, left, right = pal_left + 1, pal_right - 1, left + 1, right - 1
            else:
                if L[left + 1][right] >= L[left][right - 1]:
                    left += 1
                else:
                    right -= 1
    return palindrome


if __name__ == "__main__":
    print("введите строку:")
    str_in = input()
    S = str_in.lower()
    n = len(S)
    L, result = find_matrix_of_palindromes(S)
    print("длина:", result)
    palindrome = "".join(palindrome_recovery(L, S, 0, n - 1, 0, result - 1))
    print("палиндром:", palindrome)
    sys.exit(0)
