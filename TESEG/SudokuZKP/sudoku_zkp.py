from random import sample, randint, choice
from hashlib import sha256
import string

class Sudoku():
    def __init__(self, _board=None):
        if _board:
            self.board = _board
        else:
            self.board = []

    def create_board(self):
        self.board = []
        first_line = sample(range(1, 10), 9)

        # Generate the random numbers in board
        for i in range(9):
            aux = []
            for j in range(9):
                pos = (3 * (i % 3) + i // 3 + j) % 9
                aux.append(first_line[pos])
            self.board.append(aux)

        # Randomize rols and cols
        rows  = [ r for g in sample(range(3), 3) for r in sample(range(g * 3, (g + 1) * 3), 3)]
        cols  = [ c for g in sample(range(3), 3) for c in sample(range(g * 3, (g + 1) * 3), 3)]
        self.board = [[ self.board[r][c] for c in cols] for r in rows]

        # Display just 26 numbers to puzzle
        show_position = set()
        while True:
            if len(show_position) == 26:
                break

            x = randint(0, 8)
            y = randint(0, 8)

            show_position.add((x, y))

        for i in range(9):
            for j in range(9):
                if (i, j) not in show_position:
                    self.board[i][j] = 0

    def print_board(self, board):
        for i in range(9):
            for j in range(9):
                print(board[i][j], end=' ')
            print()

    def solve_sudoku(self, i=0, j=0):
        i, j = self.find_next_cell_to_fill(i, j)
        if i == -1:
                return True
        for e in range(1, 10):
            if self.is_valid(i, j, e):
                self.board[i][j] = e
                if self.solve_sudoku(i, j):
                    return True
                # Undo the current cell for backtracking
                self.board[i][j] = 0
        return False

    def find_next_cell_to_fill(self, i, j):
        for x in range(i, 9):
            for y in range(j, 9):
                if self.board[x][y] == 0:
                    return x, y
        for x in range(0, 9):
            for y in range(0, 9):
                if self.board[x][y] == 0:
                    return x, y
        return -1, -1

    def is_valid(self, i, j, e):
        rowOk = all([e != self.board[i][x] for x in range(9)])
        if rowOk:
            columnOk = all([e != self.board[x][j] for x in range(9)])
            if columnOk:
                # Finding the top left x,y co-ordinates of the section containing the i,j cell
                secTopX, secTopY = 3 *(i//3), 3 *(j//3)
                for x in range(secTopX, secTopX+3):
                    for y in range(secTopY, secTopY+3):
                        if self.board[x][y] == e:
                            return False
                return True
        return False

    def generate_hash(self, data, nonce):
        data = str(data) + str(nonce)

        hash_ = sha256()
        hash_.update(bytes(data, encoding='utf8'))
        hash_ = hash_.hexdigest()
        return hash_

    def get_row(self, board, row):
        return board[row]

    def get_column(self, board, column):
        cols = [board[i][column] for i in range(9)]
        return cols

    def get_square(self, board, square):
        nums = []
        x1 = (square % 3) * 3
        y1 = (square % 3) * 3

        for i in range(x1, x1+3):
            for j in range(y1, y1+3):
                nums.append(board[i][j])

        return nums

class Verifier(Sudoku):
    def __init__(self):
        super().__init__()
        self.prover = None

    def add_prover(self, _prover):
        self.prover = _prover

    def verify_data(self, hashed_row, permuted_row, nonce_row):
        for i in range(0, len(hashed_row)):
            hash_ = self.generate_hash(permuted_row[i], nonce_row[i])
            if hash_ != hashed_row[i]:
                return False

        return True

    def verify_prover(self, correctness_probability):
        ''' Choices: 0 -> row, 1 -> col, 2 -> subsquare'''

        actual_probability = 0
        count = 0

        while actual_probability < correctness_probability:
            # Permute and calculate the hash
            prover.permute_board()
            prover.hash_board()

            print(f'Permutation: {count}')
            prover.print_board(prover.permuted_board)
            print()

            # Choose between row, col or square area
            choice = randint(0, 2)
            select_num = randint(0, 8)

            if choice == 0:
                print(f'Chosen row: {select_num}')
                hashed_row = self.prover.get_row(self.prover.hashed_board, select_num)
                permuted_row = self.prover.get_row(self.prover.permuted_board, select_num)
                nonce_row = self.prover.get_row(self.prover.nonce_board, select_num)
            elif choice == 1:
                print(f'Chosen column: {select_num}')
                hashed_row = self.prover.get_column(self.prover.hashed_board, select_num)
                permuted_row = self.prover.get_column(self.prover.permuted_board, select_num)
                nonce_row = self.prover.get_column(self.prover.nonce_board, select_num)
            else:
                print(f'Chosen square: {select_num}')
                hashed_row = self.prover.get_square(self.prover.hashed_board, select_num)
                permuted_row = self.prover.get_square(self.prover.permuted_board, select_num)
                nonce_row = self.prover.get_square(self.prover.nonce_board, select_num)

            if not self.verify_data(hashed_row, permuted_row, nonce_row):
                print('False case')
                return False, -1
            print('Case Verified')
            print()

            count += 1
            actual_probability = 1 - ((1 - (1/27)) ** count)
        return True, count

class Prover(Sudoku):
    def __init__(self, board=None):
        super().__init__(board)
        self.permuted_board = []
        self.hashed_board = []
        self.nonce_board = []

    def generate_nonce(self):
    	# Generate random string with lowercase, uppercase and special characters
    	options = string.ascii_letters + string.digits
    	return ''.join(choice(options) for i in range(5))

    def permute_board(self):
        # Add the constant and use mod 9 to permute
        self.permuted_board = [row[:] for row in self.board]
        num = randint(1, 9)
        for i in range(0, 9):
            for j in range(0, 9):
                res = ((self.board[i][j] + num) % 9) + 1
                self.permuted_board[i][j] = res

    def hash_board(self):
        self.hashed_board = [row[:] for row in self.permuted_board]
        self.nonce_board = [row[:] for row in self.permuted_board]

        for i in range(9):
            for j in range(9):
                nonce = self.generate_nonce()
                hash_ = self.generate_hash(self.permuted_board[i][j], nonce)
                self.hashed_board[i][j] = hash_
                self.nonce_board[i][j] = nonce

if __name__ == '__main__':
    correctness_probability = 0.7

    verifier = Verifier()
    verifier.create_board()

    print('Sudoku Puzzle')
    verifier.print_board(verifier.board)
    print()

    prover = Prover(verifier.board)
    prover.solve_sudoku()

    print('Sudoku Solution by Prover')
    prover.print_board(prover.board)
    print()

    verifier.add_prover(prover)
    flag, count = verifier.verify_prover(correctness_probability)
    if flag:
        print(f'With a correctness probability of {correctness_probability * 100}%')
        print(f'It was necessary {count} iterations')
        print('Provider is telling the truth')
    else:
        print('Provider is a liar')
