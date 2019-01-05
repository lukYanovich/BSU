import numpy as np
import scipy.stats as st

_m = 4
_N1 = 5000
_N2 = 15000
_a = 0
_b = 1


def f(x, y):
    return 2 * x * np.cos(y)


def monte(N):
    lag = 1 / N
    x = np.arange(_a, _b, lag)
    y = np.arange(_a, _b, lag)
    return np.sum([f(x[i], y[i]) for i in range(len(x))]) / N


def main():
    # 1
    # ///

    # 2
    # ///

    # 3
    print(monte(_N1))
    print(monte(_N2))


if __name__ == "__main__":
    main()
