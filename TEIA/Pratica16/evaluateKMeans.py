from HelpersClustering import KMeans, SimplifiedSilhouette, remove_column
from HelpersFile import ParseCsv, WriteFile
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)
parser.add_argument('--hasclass', '-hc', help="if file has class attribute", type=int, default=0)
parser.add_argument('--class_idx', '-c', help="pass the index of column that contains the class attribute (starting from 0)", type=int)

if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    if args.hasclass:
        data = remove_column(data, args.class_idx)

    result = []
    opts = [2, 3, 4]
    for opt in opts:
        kmeans = KMeans(data, opt)
        clusters = kmeans.execute()

        silhouette = SimplifiedSilhouette(clusters)
        result.append(f'K => {opt} / Silhouette => {silhouette.calculate()}')

    wfile = WriteFile(filename=f'silhouette.txt', join=False)
    wfile.write_data(result)
