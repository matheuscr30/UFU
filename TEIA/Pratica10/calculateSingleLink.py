from HelpersClustering import SingleLink
from HelpersFile import ParseCsv, WriteFile
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)

if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    single_link = SingleLink(data)
    single_link.execute()

    wfile = WriteFile(filename='levels.txt', join=False)
    wfile.write_data(single_link.log)
