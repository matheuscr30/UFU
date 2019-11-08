from bson.objectid import ObjectId
from pymongo import MongoClient, ASCENDING
import matplotlib.pyplot as plt
from bs4 import BeautifulSoup
from sklearn import tree
import numpy as np
import requests
import pickle
import os

client = MongoClient('localhost', 27017)
db = client.blockchain_db

def is_from_exchange(tx_id):
    try:
        url = f'https://www.walletexplorer.com/?q={tx_id}'
        page = requests.get(url)
        soup = BeautifulSoup(page.content, 'html.parser')
        note = soup.findAll('p', {'class': 'note'})[0].get_text()
        words_array = note.split(' ')
        exchange_name = words_array[2][:-1]

        # If the name is in format [tx], its not from exchange
        if exchange_name[0] == '[':
            return False, None
        return True, exchange_name
    except Exception as e:
        return False, None

def set_train_clusters(clusters_for_training):
    count = 0
    query = {"is_exchange": { "$exists": False}}
    for cluster in db.clusters.find(query).limit(clusters_for_training):
        print(f'Cluster {count}')
        is_exchange, exchange_name = is_from_exchange(cluster['addresses'][0])
        db.clusters.update_one({ '_id': ObjectId(cluster['_id']) }, {
            '$set': {
                'is_exchange': is_exchange
            }
        })
        count += 1

class DecisionTreeClassifier:
    def __init__(self, clusters_for_training=100, no_train=False):
        self.clusters_for_training = clusters_for_training
        self.no_train = no_train

        if os.path.exists('model/model.pkl'):
            self.load_model()
        else:
            self.train_model()
            self.save_model()

    def load_model(self):
        model_file = open('model/model.pkl', 'rb')
        self.model = pickle.load(model_file)

    def train_model(self):
        query = {"is_exchange": { "$exists": True, "$ne": None }}

        if not self.no_train:
            set_train_clusters(self.clusters_for_training)

        train_clusters = []
        labels = []

        qtd_train_clusters = db.clusters.count_documents(query) / 2
        print(f'Qtd Clusters: {int(qtd_train_clusters)}')

        for cluster in db.clusters.find(query).sort("_id", 1).limit(int(qtd_train_clusters)):
            train_clusters.append([
                cluster['num_transactions'],
                len(cluster['addresses']),
                cluster['btc_in'],
                cluster['btc_out'],
                cluster['gini']
            ])
            labels.append(cluster['is_exchange'])

        self.model = tree.DecisionTreeClassifier()
        self.model = self.model.fit(train_clusters, labels)

    def save_model(self):
        with open('model/model.pkl', 'wb') as model_file:
            pickle.dump(self.model, model_file)

    def predict(self):
        query = {"is_exchange": { "$exists": True, "$ne": None }}

        predict_clusters = []
        answers_clusters = {}

        qtd_predict_clusters = db.clusters.count_documents(query) / 2
        print(f'Qtd Predict Clusters: {int(qtd_predict_clusters)}')

        count = 0
        for cluster in db.clusters.find(query).sort("_id", -1).limit(int(qtd_predict_clusters)):
            predict_clusters.append([
                cluster['num_transactions'],
                len(cluster['addresses']),
                cluster['btc_in'],
                cluster['btc_out'],
                cluster['gini']
            ])
            answers_clusters[count] = cluster['is_exchange']
            count += 1

        values = self.model.predict(predict_clusters)

        miss = 0
        succeeded = 0

        is_exchange_true_succeeded = 0
        is_exchange_true_miss = 0

        index = 0
        for is_exchange_predicted in values:
            if is_exchange_predicted:
                if answers_clusters[index]:
                    is_exchange_true_succeeded += 1
                else:
                    is_exchange_true_miss += 1

            if is_exchange_predicted == answers_clusters[index]:
                succeeded += 1
            else:
                miss += 1
            index += 1

        print(f'Succeeded Predictions: {succeeded} - {succeeded*100/qtd_predict_clusters}')
        print(f'Failed Predictions: {miss} - {miss*100/qtd_predict_clusters}')
        print()
        print(f'Succeeded when prediction is true: {is_exchange_true_succeeded} {is_exchange_true_succeeded*100/(is_exchange_true_miss+is_exchange_true_succeeded)}')
        print(f'Miss when prediction is true: {is_exchange_true_miss} {is_exchange_true_miss*100/(is_exchange_true_miss+is_exchange_true_succeeded)}')

if __name__ == '__main__':
    DTC = DecisionTreeClassifier(20000, no_train=True)
    DTC.predict()
