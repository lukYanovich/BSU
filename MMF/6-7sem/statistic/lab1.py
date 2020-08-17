import sys
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import math
from auxiliary.func import *


def get_var_arr(arr):
    # случайные величины и сколько раз встречались
    arr.sort()
    var_arr_x, var_arr_count = [], []
    for i in range(len(arr)):
        if arr[i] in var_arr_x:
            var_arr_count[var_arr_x.index(arr[i])] += 1
        else:
            var_arr_x.append(arr[i])
            var_arr_count.append(1)
    return var_arr_x, var_arr_count


def get_arr_distribution(n, avg, mean_square, distribution, alpha=1):
    arr_distribution = []
    if distribution == "gauss":
        alpha = 1  # 1 or 100
        arr_distribution = [round(np.random.normal(avg, mean_square), 1) for i in range(int(alpha * n))]
    elif distribution == "poisson":
        beta = 1  # 1 or 5
        arr_distribution = [round(np.random.poisson(avg), 1) for i in range(int(beta * n))]
    return arr_distribution


def func1(arr):
    # print(arr)
    n = len(arr)
    var_arr_x, var_arr_count = get_var_arr(arr)
    var_arr = [(var_arr_x[i], var_arr_count[i]) for i in range(len(var_arr_x))]
    print(var_arr)

    avg = np.mean(arr)
    print("выборочное среднее:", avg)
    temp = sum([(i - avg) ** 2 for i in arr])
    disp = temp / n
    print("выборочная дисперсия:", disp)
    disp_correct = temp / (n - 1)
    print("исправленная дисперсия:", disp_correct)
    mean_square = math.sqrt(disp_correct)

    print("среднее линейное отклонение:", sum([math.fabs(i - avg) for i in arr]) / n)
    print("среднее квадратичное отклонение:", mean_square)

    # характеризует меру скошенности полигона или гистограммы влево/вправо относительно самого высокого участка
    # в сравнении с нормальным распределением
    # <0.25 - асимметрия незначительна; (0.25-0.5) - умеренная; >0.5 - значительная
    skewness = (avg - float(stats.mode(arr)[0][0])) / mean_square  # Пирсона
    # print("коэффициент асимметрии (Пирсона):", skewness)
    skewness = sum([(i - avg) ** 3 for i in arr]) / n / mean_square ** 3
    print("коэффициент асимметрии:", skewness)
    # характеризует меру высоты (вытянутости)
    kurtosi = sum([(i - avg) ** 4 for i in arr]) / n / mean_square ** 4 - 3
    print("коэффициент эксцесса:", kurtosi)

    scope = max(arr) - min(arr)
    print("размах:", scope)
    median = np.median(arr)
    print("медиана:", median)

    quartile = np.percentile(arr, [25, 75])  # квантиль 1/2 - медиана
    q1 = float(quartile[0])
    print("первый(нижний) квартиль:", q1)
    q2 = float(quartile[1])
    print("третий(верхний) квартиль:", q2)
    quantile = arr[int(n * (1 / 3) + 1)]
    print("выборочный квантиль порядка 1/3:", quantile)

    return var_arr_x, var_arr_count, avg, mean_square


def draw2_1(arr, var_arr_x, var_arr_count, avg, mean_square, distribution, ax):
    n = len(arr)

    ax.hist(arr, len(var_arr_x), label="гистограмма")
    # ax.bar(var_arr_x,var_arr_count)
    ax.plot(var_arr_x, var_arr_count, label="полигон частот")

    arr_distribution = get_arr_distribution(n, avg, mean_square, distribution)
    var_arr_x, var_arr_count = get_var_arr(arr_distribution)
    ax.plot(var_arr_x, var_arr_count, label=distribution)
    ax.set_title("вероятности")


def draw3_1(arr, var_arr_x, var_arr_count, avg, mean_square, distribution, ax):
    def _draw(_arr, _var_arr_x, _var_arr_count, _label):
        n = len(_arr)
        temp = [i / n for i in _var_arr_count]
        start = temp[0]
        for i in range(1, len(temp)):
            start += temp[i]
            temp[i] = start

        def func_empirical(x, _temp):
            result = 0
            if x < _var_arr_x[0]:
                pass
            elif x > _var_arr_x[-1]:
                result = 1
            else:
                for i in range(1, len(_var_arr_x)):
                    if _var_arr_x[i - 1] < x <= _var_arr_x[i]:
                        result = _temp[i]
                        break
            return result

        temp1 = [i for i in np.arange(0, max(_arr) + 1, 0.1)]
        ax.plot(temp1, [func_empirical(i, temp) for i in temp1], label=_label)

    _draw(arr, var_arr_x, var_arr_count, "эмпирическая")

    arr_distribution = get_arr_distribution(len(arr), avg, mean_square, distribution)
    var_arr_x, var_arr_count = get_var_arr(arr_distribution)
    _draw(arr, var_arr_x, var_arr_count, distribution)
    ax.set_title("функции распределения")


def draw4_1(arr, ax):
    ax.boxplot(arr)
    ax.set_title("ящик с усами (с размахом)")


if __name__ == '__main__':
    player = "Matt Bonner"
    variant = 8
    distributions = "gauss", "poisson"  # нормальное и Пуассона
    fig, ax = plt.subplots(figsize=(5, 4))

    arr1, arr2 = read_file(player)
    selection = 1
    arr, distribution = [arr1, arr2][selection - 1], distributions[selection - 1]

    var_arr_x, var_arr_count, avg, mean_square = func1(arr)
    # draw2_1(arr, var_arr_x, var_arr_count, avg, mean_square, distribution, ax)
    draw3_1(arr, var_arr_x, var_arr_count, avg, mean_square, distribution, ax)
    # draw4_1(arr, ax)

    ax.legend(loc='lower right')  # upper-lower, left-right
    plt.show()
    sys.exit(0)
