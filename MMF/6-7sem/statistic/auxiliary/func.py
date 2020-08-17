import csv


def read_file(player):
    path = "resources/Data_1.csv"
    with open(path, "r", encoding="latin-1") as f:
        wines = list(csv.reader(f))
    arr = [(float(wines[i][19]), float(wines[i][18])) for i in range(1, len(wines)) if
           wines[i][5] == player]
    arr1 = [i[0] for i in arr if i[0] not in (0, 100)]
    arr2 = [i[1] for i in arr]
    return arr1, arr2
