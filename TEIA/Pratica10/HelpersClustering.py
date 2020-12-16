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


class SingleLink():
    def __init__(self, data, distance=2):
        self.data = data
        self.distance = 2
        self.log = []

    def generate_distance_matrix(self):
        if not len(self.data):
            return []

        # Initialize distance matrix
        distances = [[None] * len(self.data) for _ in range(len(self.data))]
        num_columns = len(self.data[0])

        # Calculate distances
        for i in range(0, len(self.data)):
            for j in range(i+1, len(self.data)):
                x = self.data[i]
                y = self.data[j]
                distances[i][j]  = minkowski_distance(x, y, self.distance)

        return distances

    def find_min_distance(self, distances):
        # Find the minimum distance in matrix and return the indexes
        min_distance = x = y = None

        for i in range(0, len(distances)):
            for j in range(i+1, len(distances[i])):
                if distances[i][j] is None:
                    continue

                if min_distance is None or distances[i][j] < min_distance:
                    min_distance = distances[i][j]
                    x = i
                    y = j

        return x, y

    def update_distance_matrix(self, distances, pos_x, pos_y):
        for j in range(0, len(distances[pos_x])):
            if j == pos_y:
                continue

            min_pos = min(pos_x, j)
            max_pos = max(pos_x, j)

            # Get the minimum distance between the distance in pos_x, j and pos_y, j
            if distances[min_pos][max_pos] is not None:
                distances[min_pos][max_pos] = min(
                    distances[min_pos][max_pos],
                    distances[min(pos_y, j)][max(pos_y, j)]
                )

        # Set None to the unused column
        for j in range(0, len(distances[pos_y])):
            distances[min(pos_y, j)][max(pos_y, j)] = None

        return distances

    def update_log(self, groups):
        log_item = ''

        first = True
        for key, group in groups.items():
            if first:
                first = False
            else:
                log_item += ','

            log_item += '{'
            for i in range(0, len(group)):
                if i != 0:
                    log_item += ','
                log_item += f'{group[i]}'
            log_item += '}'

        self.log.append(log_item);

    def execute(self):
        distances = self.generate_distance_matrix()

        groups = { i: [i] for i in range(0, len(distances)) }
        idxToGroup = { i: i for i in range(0, len(distances)) }

        self.update_log(groups)

        while len(groups) != 1:
            x, y = self.find_min_distance(distances)

            # The main group is always the group with the lower index
            main_group = min(idxToGroup[x], idxToGroup[y])
            other_group = max(idxToGroup[x], idxToGroup[y])

            # Merge groups
            groups[main_group].extend(groups[other_group])
            del groups[other_group]
            idxToGroup[x] = idxToGroup[y] = main_group

            distances = self.update_distance_matrix(distances, min(x, y), max(x, y))
            self.update_log(groups)


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
