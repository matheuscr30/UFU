from pymongo import MongoClient
import numpy as np

client = MongoClient('localhost', 27017)
db = client.blockchain_db

def gini(arr):
    count = arr.size
    coefficient = 2 / count
    indexes = np.arange(1, count + 1)

    weights = []
    weighted_sum = 0
    total = 0
    for i in range(count):
        weighted_sum += indexes[i] * arr[i]
        total += arr[i]

    constant = (count + 1) / count
    return coefficient * weighted_sum / total - constant

def heuristicH1():
    addresses_to_clusters = {}
    addresses_btc_in = {}
    clusters = {}
    next_cluster = 1

    transactions = db.transactions.find()
    count = 0
    for transaction in transactions:
        count += 1
        if count % 50000 == 0:
            print(f'Transaction: {count}')

        if len(transaction['inputs']) > 0:
            actual_clusters = None

            # Find if there are transaction already mapped to clusters
            for input in transaction['inputs']:
                if input['address'] in addresses_to_clusters:
                    if actual_clusters is None:
                        actual_clusters = [addresses_to_clusters[input['address']]]
                    else:
                        actual_clusters.append(addresses_to_clusters[input['address']])

            # If they are unknow addresses, create a cluster
            if actual_clusters is None:
                addresses = []
                sum_btc_in = 0
                sum_btc_out = 0

                for input in transaction['inputs']:
                    addresses.append(input['address'])
                    addresses_to_clusters[input['address']] = next_cluster
                    addresses_btc_in[input['address']] = input['value']
                    sum_btc_in += input['value']

                for output in transaction['outputs']:
                    sum_btc_out += output['value']

                clusters[next_cluster] = {
                    "addresses": set(addresses),
                    "num_transactions": 1,
                    "btc_in": sum_btc_in,
                    "btc_out": sum_btc_out
                }
                next_cluster += 1
            # Merge clusters
            else:
                min_cluster = min(actual_clusters)

                sum_btc_in = 0
                sum_btc_out = 0

                # For the case that exists at least one unknow address between the others
                for input in transaction['inputs']:
                    clusters[min_cluster]['addresses'].add(input['address'])
                    addresses_to_clusters[input['address']] = min_cluster
                    sum_btc_in += input['value']

                    if input['address'] in addresses_btc_in:
                        addresses_btc_in[input['address']] += input['value']
                    else:
                        addresses_btc_in[input['address']] = input['value']

                for output in transaction['outputs']:
                    sum_btc_out += output['value']

                clusters[min_cluster]['num_transactions'] += 1
                clusters[min_cluster]['btc_in'] += sum_btc_in
                clusters[min_cluster]['btc_out'] += sum_btc_out

                if (len(actual_clusters) > 1):
                    for cluster in set(actual_clusters):
                        if cluster != min_cluster:
                            clusters[min_cluster]['num_transactions'] += clusters[cluster]['num_transactions']
                            clusters[min_cluster]['btc_in'] += clusters[cluster]['btc_in']
                            clusters[min_cluster]['btc_out'] += clusters[cluster]['btc_out']

                            addresses = list(clusters[cluster]['addresses'])
                            for address in addresses:
                                addresses_to_clusters[address] = min_cluster
                                clusters[min_cluster]['addresses'].add(address)
                            del clusters[cluster]

    count = 0
    for key, cluster in clusters.items():
        if count % 10000:
            print(f'Cluster: {count}')
        count += 1
        gini_arr = []
        for address in cluster['addresses']:
            gini_arr.append(addresses_btc_in[address])
        gini_arr.sort()

        gini_value = gini(np.array(gini_arr))
        clusters[key]['gini'] = gini_value

    return clusters, addresses_to_clusters

def heuristicH2(addresses_to_clustersH1):
    addresses_to_clustersH2 = {}
    number_of_transactions_per_address = {}
    clustersH2 = {}
    next_cluster = 1

    transactions = db.transactions.find()
    count = 0
    for transaction in transactions:
        count += 1
        if count % 50000 == 0:
            print(f'Transaction: {count}')

        for input in transaction['inputs']:
            if input['address'] in number_of_transactions_per_address:
                number_of_transactions_per_address[input['address']] += 1
            else:
                number_of_transactions_per_address[input['address']] = 1

        if len(transaction['outputs']) >= 2:
            input_addresses = [input['address'] for input in transaction['inputs']]
            qtd_first_time = 0
            first_time_address = None

            # Checking if is the only one that never appeared and its not an input address
            for output in transaction['outputs']:
                if output['address'] in input_addresses or output['address'] in addresses_to_clustersH2:
                    continue
                else:
                    first_time_address = output['address']
                    qtd_first_time += 1

            # If there is just one unknow address, its a change wallet
            if qtd_first_time == 1:
                # Get the cluster of H1 for the input address
                clusterH1 = addresses_to_clustersH1[input_addresses[0]]

                if clusterH1 not in clustersH2:
                    clustersH2[clusterH1] = set([first_time_address])
                else:
                    clustersH2[clusterH1].add(first_time_address)
                addresses_to_clustersH2[first_time_address] = clusterH1

    return clustersH2

def stats_clusters(clusters):
    print(f'There are {len(clusters.keys())} clusters')

    result = {}
    for cluster in clusters:
        size_cluster = len(clusters[cluster]['addresses'])
        if size_cluster in result:
            result[size_cluster] += 1
        else:
            result[size_cluster] = 1

    print("Top 10 Biggest Clusters")
    count = 0
    for key, value in sorted(result.items(), reverse=True):
        count += 1
        if (count > 5):
            break
        print(f'Cluster size: {key} /  Qtd Clusters: {value}')

def save_clusters_h1(clusters):
    db.clusters.drop()

    print('Saving Clusters')
    count = 0
    for cluster in clusters:
        count += 1
        if count % 50000 == 0:
            print(f'Cluster: {count}')
        json_cluster = clusters[cluster]
        json_cluster['addresses'] = list(json_cluster['addresses'])
        db.clusters.insert_one(json_cluster)

if __name__ == '__main__':
    print('Choose one option:')
    print('1 - Execute heuristic 1')
    print('2 - Execute both')
    option = int(input('> '))

    if option == 1 or option == 2:
        clustersH1, addresses_to_clustersH1 = heuristicH1()
        print()
        print('For H1:')
        stats_clusters(clustersH1)
        save_clusters_h1(clustersH1)

        if option == 2:
            clustersH2 = heuristicH2(addresses_to_clustersH1)
            print()
            print('For H2:')
            stats_clusters(clustersH2)
