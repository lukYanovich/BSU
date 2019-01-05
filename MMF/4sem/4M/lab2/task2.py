import matplotlib.pyplot as plt
import numpy as np
import itertools

_m = 2
_size = len(list(itertools.combinations(range(_m + 3), 3)))


def f(x, y, z):
    return 2 * x * z * np.cos(y)


def generate():
    x = [np.random.uniform(-5, 5) for i in range(_size)]
    y = [np.random.uniform(-5, 5) for i in range(_size)]
    z = [np.random.uniform(-5, 5) for i in range(_size)]
    return x, y, z


def main():
    # lag = 0.1
    # x = np.arange(0.0, 9 / 5 * np.pi + lag, lag)
    # y = 4 * pow(np.cos(x), 3)
    # plt.plot(x, y, label='f(x)', color='black')
    # plt.scatter(_x, f(_x), c="red")
    # plt.show()
    # print(_size1)
    # print(_size2)
    x, y, z = generate()
    print(x)
    print(y)
    print(z)
    # print(np.linalg.det(np.vander(xy, len(x))))


if __name__ == "__main__":
    main()
