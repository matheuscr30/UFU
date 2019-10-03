from hashlib import sha256
from math import ceil
import numpy as np
import random
import time

class BloomFilter():
    def __init__(self, n, p):
        list_size = -1 * ((n * np.log(p)) / (np.log(2) ** 2))
        self.bits_vector = [0] * ceil(list_size)
        self.number_of_hashes = ceil(-2 * np.log2(p))
        self.n = n
        self.p = p

    def insert(self, k):
        for i in range(1, self.number_of_hashes+1):
            data = str(i) + str(k)
            t = self.generate_hash(data)
            self.bits_vector[ t % self.n ] = 1

    def verify(self, k):
        for i in range(1, self.number_of_hashes+1):
            data = str(i) + str(k)
            t = self.generate_hash(data)
            if self.bits_vector[ t % self.n ] == 0:
                return False
        return True

    def generate_hash(self, data):
        hash_ = sha256()
        hash_.update(bytes(data, encoding='utf8'))
        hash_ = hash_.digest()
        return int.from_bytes(hash_, 'big')

    def test(self, qtd_numbers, max_number):
        check_set = set()
        count_correct = 0
        count_false_positive = 0

        for x in range(qtd_numbers):
            num = random.randint(1, max_number)
            print(f'Generated Number: {num}')

            exists = bloom_filter.verify(num)
            if exists and num not in check_set:
                print('Its a false positive')
                count_false_positive += 1
            else:
                count_correct += 1

            check_set.add(num)
            bloom_filter.insert(num)

        print()
        print(f'Number of Correct Responses: {count_correct}')
        print(f'Number of False Positives: {count_false_positive}')
        print(f'False Positive Percentage: {count_false_positive / self.n}')

if __name__ == '__main__':
    qtd_itens = 100000
    max_number = 1000000
    false_positive_probability = 0.4

    bloom_filter = BloomFilter(qtd_itens, false_positive_probability)
    start_time_bloom_filter = time.time()
    bloom_filter.test(qtd_itens, max_number)
    end_time_bloom_filter = time.time() - start_time_bloom_filter

    start_time_list = time.time()
    number_list = []
    for i in range(qtd_itens):
        num = random.randint(1, max_number)
        _  = num in number_list
        number_list.append(num)
    end_time_list = time.time() - start_time_list

    start_time_dict = time.time()
    number_dict = {}
    for i in range(qtd_itens):
        num = random.randint(1, max_number)
        _  = num in number_dict
        number_dict[num] = True
    end_time_dict = time.time() - start_time_dict

    print()
    print(f'Time Spent by Bloom Filter: {end_time_bloom_filter}')
    print(f'Time Spent by List: {end_time_list}')
    print(f'Time Spent by Dict: {end_time_dict}')
