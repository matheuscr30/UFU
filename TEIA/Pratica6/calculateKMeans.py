from HelpersClustering import KMeans
from HelpersCsv import ParseCsv, WriteCsv
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)
parser.add_argument('--clusters', '-c', help="pass the number of clusters for the execution of k-means", type=int)

if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    kmeans = KMeans(data, args.clusters)
    clusters = kmeans.execute()

    row_clusters = {}
    for cluster_id, rows in clusters.items():
        for row in rows:
            row_clusters[row['row_index']] = cluster_id

    result = [['Instance Index', 'Cluster Id']]

    for i in range(0, len(data)):
        result.append([i,row_clusters[i]])

    wcsv = WriteCsv(filename='clusters.txt')
    wcsv.write_data(result)
