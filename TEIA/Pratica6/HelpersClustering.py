import random
import copy

class KMeans():
    def __init__(self, data, groups, limit=100, distance=2):
        self.data = data
        self.groups = groups
        self.limit = limit
        self.distance = 2

    def choose_random_centroids(self):
        centroids_idx = random.sample(range(len(self.data)), self.groups)
        centroids_idx = [val-1 for val in centroids_idx]
        centroids = [self.data[idx] for idx in centroids_idx]
        return centroids

    def closest_centroid(self, x, centroids):
        min_distance = None
        min_cluster_id = None

        for centroid in centroids:
            dist = minkowski_distance(x, centroid['centroid'], self.distance)
            if dist is None: continue

            if min_distance is None or dist < min_distance:
                min_distance = dist
                min_cluster_id = centroid['cluster_id']

        return min_cluster_id

    def mean(self, data):
        if not len(data):
            return []

        sums = [0] * len(data[0])

        for row in data:
            for idx, col in enumerate(row):
                sums[idx] += float(col)

        means = [val/len(data) for val in sums]
        return means

    def execute(self):
        random_centroids = self.choose_random_centroids()

        centroids = [{'cluster_id': idx, 'centroid': random_centroids[idx]} for idx in range(0, len(random_centroids))]
        clusters = {centroid['cluster_id']: [] for centroid in centroids}
        prev_clusters = None

        iterations = 0
        while iterations < self.limit:
            for row_index, x in enumerate(self.data):
                min_distance = None
                min_cluster_id = None

                cluster_id = self.closest_centroid(x, centroids)
                clusters[cluster_id].append({
                    'row_index': row_index,
                    'data': x
                })

            if clusters == prev_clusters:
                break

            prev_clusters = copy.deepcopy(clusters)

            for centroid in centroids:
                cluster_id = centroid['cluster_id']
                data = [x['data'] for x in clusters[cluster_id]]
                centroid['centroid'] = self.mean(data)

            clusters = {centroid['cluster_id']: [] for centroid in centroids}
            iterations += 1

        return clusters


def minkowski_distance(x, y, r):
    if len(x) != len(y):
        return None

    sumOfDifferences = 0
    for i in range(0, len(x)):
        xValue = float(x[i])
        yValue = float(y[i])

        diff = (xValue - yValue)
        diff = diff if diff > 0 else diff * -1
        sumOfDifferences += (diff ** r)

    dist = (sumOfDifferences ** (1/r))
    return dist
