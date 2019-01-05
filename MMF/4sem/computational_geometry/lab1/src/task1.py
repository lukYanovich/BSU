import matplotlib.pyplot as plt


def determ(x, y):
    return ((x[1] - x[0]) * (y[2] - y[0])) - ((y[1] - y[0]) * (x[2] - x[0]))


def printPlot(x, y):
    if determ(x, y) < 0:
        plt.title('правее')
    elif determ(x, y) > 0:
        plt.title('левее')
    elif determ(x, y) == 0:
        plt.title('лежит на прямой')

    plt.plot(x[0:2], y[0:2], label=u"прямая")
    plt.text(x[0], y[0], 'p1', fontsize=8)
    plt.text(x[1], y[1], 'p2', fontsize=8)
    plt.text(x[2], y[2], 'p0', fontsize=8)
    plt.scatter(x[2], y[2])
    plt.show()


def main():
    x = []
    y = []
    _list = []
    _list.append((1, 3))  # p1
    _list.append((5, 10))  # p2
    _list.append((4, 4))  # p3
    for i in range(3):
        x.append(_list[i][0])
        y.append(_list[i][1])
    printPlot(x, y)


if __name__ == "__main__":
    main()
