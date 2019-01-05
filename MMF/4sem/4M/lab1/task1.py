import matplotlib.pyplot as plt
import numpy as np


def f(x):
    return 4 * pow(np.cos(x), 3)


_x = [0, np.pi / 6, np.pi / 4, np.pi / 3, np.pi / 2, np.pi, 9 / 5 * np.pi]
_y = f(_x)


def Tn(x):
    N = len(_x)

    def a_k(k):
        sum = 0.0
        for i in range(0, N):
            sum += _y[i] * np.exp(1j * -2 * np.pi * k * _x[i])
        return sum / N

    sum = 0.0
    for k in range(int(-N / 2), int(N / 2) + 1):
        sum += a_k(k) * np.exp(1j * 2 * np.pi * x * k)
    return sum


def main():
    lag = 0.1
    x = np.arange(0.0, 9 / 5 * np.pi + lag, lag)
    y = 4 * pow(np.cos(x), 3)
    plt.plot(x, y, label='f(x)', color='black')
    plt.plot(x, Tn(x), color='green')
    plt.scatter(_x, f(_x), c="red")
    plt.show()

    arg = np.pi / 7
    print("точное: " + str(f(arg)))
    print("приближенное: " + str(Tn(arg)))


if __name__ == "__main__":
    main()
