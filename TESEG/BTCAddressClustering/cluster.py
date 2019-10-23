from pymongo import MongoClient

client = MongoClient('localhost', 27017)
db = client.blockchain_db
db_transactions = db.transactions

def heuristicH1():
    addresses_to_clusters = {}
    clusters = {}
    next_cluster = 1

    transactions = db_transactions.find()
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
                for input in transaction['inputs']:
                    addresses.append(input['address'])
                    addresses_to_clusters[input['address']] = next_cluster

                clusters[next_cluster] = set(addresses)
                next_cluster += 1
            # Merge clusters
            else:
                min_cluster = min(actual_clusters)

                for input in transaction['inputs']:
                    clusters[min_cluster].add(input['address'])
                    addresses_to_clusters[input['address']] = min_cluster

                if (len(actual_clusters) > 1):
                    for cluster in set(actual_clusters):
                        if cluster != min_cluster:
                            addresses = list(clusters[cluster])
                            for address in addresses:
                                addresses_to_clusters[address] = min_cluster
                                clusters[min_cluster].add(address)
                            del clusters[cluster]
    return clusters, addresses_to_clusters

def heuristicH2(addresses_to_clustersH1):
    addresses_to_clustersH2 = {}
    number_of_transactions_per_address = {}
    clustersH2 = {}
    next_cluster = 1

    transactions = db_transactions.find()
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
        size_cluster = len(clusters[cluster])
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

if __name__ == '__main__':
    clustersH1, addresses_to_clustersH1 = heuristicH1()
    print()
    print('For H1:')
    stats_clusters(clustersH1)

    clustersH2 = heuristicH2(addresses_to_clustersH1)
    print()
    print('For H2:')
    stats_clusters(clustersH2)