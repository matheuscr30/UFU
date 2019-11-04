from blockchain import blockexplorer
from pymongo import MongoClient
import time

client = MongoClient('localhost', 27017)
db = client.blockchain_db

if __name__ == '__main__':
    accounts = {}
    transactions_limit = 1000000

    db.transactions.drop()

    height = blockexplorer.get_latest_block().height
    count_transactions = 0
    while count_transactions < transactions_limit:
        blocks = blockexplorer.get_block_height(height)
        for block in blocks:
            print(f'Height: {block.height}')
            for transaction in block.transactions:
                print(f'Transaction: {count_transactions+1}')
                json_transaction = transaction.__dict__
                json_transaction['inputs'] = [input.__dict__ for input in json_transaction['inputs'] if hasattr(input, 'address')]
                json_transaction['outputs'] = [output.__dict__ for output in json_transaction['outputs'] if output.address is not None]
                db.transactions.insert_one(json_transaction)
                count_transactions += 1
        height -= 1
        time.sleep(0.7)
