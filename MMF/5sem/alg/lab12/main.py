import sys


# seq - последовательность
def find_sequences(S):
    n = len(S)
    N = [i for i in range(n)]
    L = [1 for i in range(n)]
    for i in range(n - 1):
        if S[i] <= S[i + 1]:
            L[i + 1] = L[i] + 1
            N[i + 1] = N[i]
    return L, N


if __name__ == "__main__":
    print("введите последовательность:")
    number = list(map(int, input().split()))
    L, N = find_sequences(number)
    pos = L.index(max(L))
    print("\nпозиции:", N[pos], N[pos] + L[pos] - 1)
    print(number[N[pos]:N[pos] + L[pos]])
    sys.exit(0)
