import math
import matplotlib.pyplot as plt
import numpy as np

_x = [0.1, 0.2, 0.3, 0.4]
_y = [1.02, 2.064, 5.985, 8.564]
_h = _x[1] - _x[0]


def lagranz(x, y, t):
    z = 0
    for j in range(len(y)):
        p1 = 1
        p2 = 1
        for i in range(len(x)):
            if i != j:
                p1 = p1 * (t - x[i])
                p2 = p2 * (x[j] - x[i])
        z += y[j] * p1 / p2
    return z


def f(x):
    return lagranz(_x, _y, x)


def f_pr(x, func, v):
    A = np.array([[1, 1, 1], [x - _h, x, x + _h], [(x - _h) ** 2, x ** 2, (x + _h) ** 2]])
    arr_c = np.linalg.solve(A, v)
    return arr_c[0] * func(x - _h) + arr_c[1] * func(x) + arr_c[2] * func(x + _h)


def main():
    def pr1(x):
        return f_pr(x, f, np.array([0, 1, 2 * x]))

    def pr2(x):
        return f_pr(x, f, np.array([0, 0, 2]))

    lag = 0.01
    x = np.arange(_x[0] - _h, _x[-1] + _h, lag)
    y = [lagranz(_x, _y, i) for i in x]
    y1 = [lagranz(_x, [pr1(elem) for elem in _x], i) for i in x]
    y2 = [lagranz(_x, [pr2(elem) for elem in _x], i) for i in x]

    plt.scatter(_x, _y, c='red')
    plt.plot(x, y, color='black')
    plt.plot(x, y1, color='green')  # первая производная
    plt.plot(x, y2, color='blue')  # вторая производная
    plt.show()

    max_f_pr2 = -math.inf
    for i in x:
        temp = math.fabs(pr2(i))
        if max_f_pr2 < temp:
            max_f_pr2 = temp
    max_f_pr3 = 4219
    n_plus_one_fact = math.factorial(len(_x) + 1)
    print("f'(a): " + str(pr1(_x[0])))
    print("f'(a+h): " + str(pr1(_x[1])))
    print("погрешность: " + str(max_f_pr2 / n_plus_one_fact * _h))
    print("\nf\"(a-h): " + str(pr2(_x[0] - _h)))
    print("f\"(b+h): " + str(pr1(_x[-1] + _h)))
    print("погрешность: " + str(max_f_pr3 / n_plus_one_fact * _h ** 2))


if __name__ == "__main__":
    main()
