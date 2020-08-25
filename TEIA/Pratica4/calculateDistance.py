from HelpersCsv import ParseCsv, WriteCsv
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)
parser.add_argument('--distance', '-d', help="pass 1 for manhattan and 2 for euclidean", type=int)

def calculate_distance(data, r):
    if not len(data):
        return []

    # Initialize distance matrix
    distances = [[0] * len(data) for _ in range(len(data))]
    num_columns = len(data[0])

    for i in range(0, len(data)):
        for j in range(i+1, len(data)):
            sumOfDifferences = 0
            x = data[i]
            y = data[j]

            for col in range(0, num_columns):
                xValue = float(x[col])
                yValue = float(y[col])

                diff = (xValue - yValue)
                diff = diff if diff > 0 else diff * -1
                sumOfDifferences += (diff ** r)

            dist = (sumOfDifferences ** (1/r))

            distances[i][j] = distances[j][i] = dist

    return distances


if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    distances = calculate_distance(data, args.distance)

    wcsv = WriteCsv(filename='distances.txt')
    wcsv.write_data(distances)
