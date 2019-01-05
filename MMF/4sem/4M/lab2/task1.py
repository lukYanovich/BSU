import pylab
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt
import itertools
from scipy import interpolate

_m = 3
_size = len(list(itertools.combinations(range(_m + 2), 2)))


def f(x, y):
    return 5 * x * np.sin(y)


def generate_and_check():
    x = [np.random.uniform(-5, 5) for i in range(_size)]
    y = [np.random.uniform(-5, 5) for i in range(_size)]
    xy = [(x[i], y[i]) for i in range(len(x))]
    for i in range(len(x) - 1):
        for j in range(i + 1, len(x)):
            if xy[i] == xy[j]:
                raise ValueError("определитель Вандермонда равен 0")
    z = []
    for i in range(len(x)):
        z.append(f(x[i], y[i]))
    return x, y, z


def make_data():
    lag = 0.25
    x = np.arange(-5, 5, lag)
    y = np.arange(-5, 5, lag)
    xgrid, ygrid = np.meshgrid(x, y)
    zgrid = f(xgrid, ygrid)
    return xgrid, ygrid, zgrid


def lagrange2(x,y,z):
    for i in range(len(x)):
        pass


def main():
    fig = plt.figure()
    axes = fig.gca(projection='3d')  # Axes3D(fig)
    x, y, z = make_data()
    axes.plot_wireframe(x, y, z)
    _x, _y, _z = generate_and_check()
    axes.scatter(_x, _y, _z, c='red', s=100)
    polynom = interpolate.interp2d(x, y, z)
    z1 = polynom(_x, _y)
    axes.plot(_x, z1[:, 0], color='green')
    pylab.show()
    # print(np.linalg.det(np.vander(xy, len(x))))


if __name__ == "__main__":
    main()
