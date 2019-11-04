from bson.objectid import ObjectId
from pymongo import MongoClient
from bs4 import BeautifulSoup
from sklearn import tree
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
        print(e)
        print(tx_id)
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
    def __init__(self):
        """ Get 30% of clusters for training and 70% for predict """
        total_clusters = db.clusters.count_documents({})
        self.clusters_for_training = int(total_clusters/3)
        self.clusters_for_predict = total_clusters - self.clusters_for_training

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

        if db.clusters.count_documents(query) == 0:
            set_train_clusters(self.clusters_for_training)

        train_clusters = []
        labels = []

        for cluster in db.clusters.find(query):
            train_clusters.append([
                cluster['num_transactions'],
                len(cluster['addresses']),
                cluster['btc_in'],
                cluster['btc_out']
            ])
            labels.append(cluster['is_exchange'])

        self.model = tree.DecisionTreeClassifier()
        self.model = self.model.fit(train_clusters, labels)

    def save_model(self):
        with open('model/model.pkl', 'wb') as model_file:
            pickle.dump(self.model, model_file)

    def predict(self):
        query = {"is_exchange": { "$exists": False} }

        predict_clusters = []

        count = 0
        for cluster in db.clusters.find(query):
            if count == 477:
                print(cluster['addresses'][0])
            count += 1
            predict_clusters.append([
                cluster['num_transactions'],
                len(cluster['addresses']),
                cluster['btc_in'],
                cluster['btc_out']
            ])

        values = self.model.predict(predict_clusters)
        cou = 0
        for item in values:
            if item == True:
                cou += 1
        print(cou)
        pos = list(values).index(True)
        print(pos)
        print(predict_clusters[pos])
        # print(values)

if __name__ == '__main__':
    """ Get 30% of clusters for training and 70% for predict """
    total_clusters = db.clusters.count_documents({})
    print(total_clusters)
    clusters_for_training = int(total_clusters/3)
    clusters_for_predict = total_clusters - clusters_for_training

    DTC = DecisionTreeClassifier()
    DTC.predict()
    # set_train_clusters(clusters_for_training)

#28821
