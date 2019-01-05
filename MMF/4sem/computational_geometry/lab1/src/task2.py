import matplotlib.pyplot as plt


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


def printPlot(lines):
    if isIntersect(lines[0], lines[1]) == 1:
        plt.title("Пересекаются")
    elif isIntersect(lines[0], lines[1]) == 0:
        plt.title("не пересекаются")
    for line in lines:
        plt.plot(line['x'], line['y'])
    plt.show()


def main():
    lines = []
    p1 = (4, 1)
    p2 = (5, 5)
    p3 = (1, 1)
    p4 = (10, 4)
    lines.append({'x': [p1[0], p2[0]], 'y': [p1[1], p2[1]]})
    lines.append({'x': [p3[0], p4[0]], 'y': [p3[1], p4[1]]})
    printPlot(lines)


if __name__ == "__main__":
    main()
