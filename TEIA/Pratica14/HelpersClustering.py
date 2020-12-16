from math import log
import random
import copy

class Purity():
    def __init__(self, clusters, data, class_idx):
        self.clusters = clusters
        self.data = data
        self.class_idx = class_idx
        self.res = [self.get_headers()]

    def get_headers(self):
        """ Get Headers for csv """
        headers = ['Clusters']
        self.classes = []

        for row in self.data:
            if row[self.class_idx] not in self.classes:
                self.classes.append(row[self.class_idx])

        for xclass in self.classes:
            headers.append(xclass)

        headers.append('Entropy')
        headers.append('Purity')
        return headers

    def get_entropy_purity(self, probabilities):
        """ Calculate entropy and purity """
        entropy = 0
        purity = 0

        for xclass, prob in probabilities.items():
            if prob > purity:
                purity = prob

            entropy += prob * log(prob, 2)

        entropy = abs(entropy)
        return entropy, purity

    def calculate(self):
        total_classes_count = [0] * len(self.classes)
        total_entropy = 0
        total_purity = 0

        total_count_clusters = 0
        for cluster, rows in self.clusters.items():
            total_count_clusters += len(rows)

        for cluster, rows in self.clusters.items():
            probabilities = {}
            classes_count = {}
            res_line = [cluster]

            """ Count the classes for one cluster """
            for row in rows:
                row_class = self.data[row['row_index']][self.class_idx]
                classes_count[row_class] = classes_count.get(row_class, 0) + 1

            """ Calculate the probabilities for classes """
            for idx, xclass in enumerate(self.classes):
                if xclass in classes_count:
                    count = classes_count[xclass]
                    total_classes_count[idx] += count
                    probabilities[xclass] = float(count / len(rows))
                    res_line.append(count)
                else:
                    res_line.append(0)

            entropy, purity = self.get_entropy_purity(probabilities)

            res_line.append(entropy)
            res_line.append(purity)
            self.res.append(res_line)

            total_entropy += ((len(rows) / total_count_clusters) * entropy)
            total_purity += ((len(rows) / total_count_clusters) * purity)

        final_line = ['Total']
        final_line.extend(total_classes_count)
        final_line.extend([total_entropy, total_purity])
        self.res.append(final_line)
        return self.res


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


def remove_column(data, idx):
    new_data = copy.deepcopy(data)

    for row in new_data:
        del row[-1]

    return new_data
