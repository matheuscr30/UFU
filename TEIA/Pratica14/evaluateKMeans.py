from HelpersClustering import KMeans, Purity, remove_column
from HelpersFile import ParseCsv, WriteFile
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)
parser.add_argument('--class_idx', '-c', help="pass the index of column that contains the class attribute (starting from 0)", type=int)

if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    data_without_class = remove_column(data, args.class_idx)
    result = []

    opts = [2, 3, 4]
    for opt in opts:
        kmeans = KMeans(data_without_class, opt)
        clusters = kmeans.execute()

        purity = Purity(clusters, data, args.class_idx)
        res_table = purity.calculate()

        wfile = WriteFile(filename=f'puritiesk{opt}.csv', join=True)
        wfile.write_data(res_table)
