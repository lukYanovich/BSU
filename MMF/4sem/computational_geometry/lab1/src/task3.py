import matplotlib.pyplot as plt
import random


def determ(line, point):
    return ((line['x'][1] - line['x'][0]) * (point[1] - line['y'][0])) - (
                (line['y'][1] - line['y'][0]) * (point[0] - line['x'][0]))


def isIntersect(line1, line2):
    d10 = determ(line1, [line2['x'][0], line2['y'][0]])
    d11 = determ(line1, [line2['x'][1], line2['y'][1]])
    d20 = determ(line2, [line1['x'][0], line1['y'][0]])
    d21 = determ(line2, [line1['x'][1], line1['y'][1]])

    if d10 == 0 and d11 == 0 and d20 == 0 and d21 == 0:
        if max(line1['x']) < min(line2['x']) or min(line1['x']) > max(line2['x']):
            return 0
    if d10 * d11 <= 0 and d20 * d21 <= 0:
        return 1
    return 0


X = lambda x: x[0]
Y = lambda y: y[1]


def nAngle(points):
    # Draw figure
    random.seed()
    size = random.randint(4, 7)
    for i in range(size - 1):
        points.append([random.randint(0, 20), random.randint(0, 20)])
    points.append(points[0])
    plt.plot(list(map(X, points)), list(map(Y, points)))
    if isPrime(points) == 1:
        plt.title('Простой')
    else:
        plt.title('Не простой')
    plt.show()


def isPrime(points):
    i = 0
    j = 0
    while i < len(points) - 1:
        j = i + 1
        line1 = {'x': [points[i][0], points[i + 1][0]], 'y': [points[i][1], points[i + 1][1]]}
        while j < len(points) - 1:
            line2 = {'x': [points[j][0], points[j + 1][0]], 'y': [points[j][1], points[j + 1][1]]}
            if (j < i - 1 or j > i + 1) and not (i == 0 and j == len(points) - 2) and isIntersect(line1, line2) == 1:
                return 0
            j += 1
        i += 1
    return 1


def main():
    points = []
    nAngle(points)


if __name__ == "__main__":
    main()
