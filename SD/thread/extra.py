from threading import Thread
import random
import string
import time

random_string = ''
turn = None
finalize = False

def generate_random_string():
	options = string.ascii_lowercase
	return ''.join(random.choice(options) for i in range(80))

class RingThread(Thread):
    def __init__(self, id):
        Thread.__init__(self)
        self.id = id

    def run(self):
        while True:
            global turn, random_string, finalize
            if finalize:
                break

            if turn == self.id:
                print()
                print(f'Thread {self.id} - Received Message: {random_string}')

                flag = False
                for i in range(0, len(random_string)):
                    if random_string[i].islower():
                        flag = True
                        aux_char = random_string[i].upper()
                        random_string = random_string[:i] + aux_char + random_string[i+1:]
                        break

                print(f'Thread {self.id} - Modified Message: {random_string}')

                if not flag:
                    print(f'In Thread {self.id} all characters are uppercase')
                    finalize = True

                aux_turn = (self.id+1)%30
                if (aux_turn == 0):
                    aux_turn = 30

                turn = aux_turn
                time.sleep(1)

if __name__ == '__main__':
    random_string = generate_random_string()

    turn = 1
    for i in range(1, 31):
        thread = RingThread(i)
        thread.start()
