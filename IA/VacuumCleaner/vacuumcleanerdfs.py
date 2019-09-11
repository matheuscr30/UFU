import random

numLines = 0
numColumns = 0
boards = []
visited = []

xs = [1, -1, 0, 0]
ys = [0, 0, 1, -1]

def createBoards():
	global boards

	for i in range(0, numLines):
		line = []
		for j in range(0, numColumns):
			line.append(random.randint(0, 1))
		boards.append(line)

	"""
	for i in range(0, numLines):
		for j in range(0, numColumns):
			print(boards[i][j], end=" ")
		print()
	"""

def start_clean(line, column):
	visited.append((line, column))
	dfs(line, column)

def print_boards():
	for i in range(0, len(boards)):
		for j in range(0, len(boards[i])):
			print(boards[i][j], end=" ")
		print()

def dfs(line, column):
	global visited

	if boards[line][column] == 1:
		boards[line][column] = 'X'
		print("Cleaning line {} column {}".format(line, column))
		print_boards()
		boards[line][column] = 0
	else:
		boards[line][column] = 'X'
		print("line {} column {} already cleaned".format(line, column))
		print_boards()
		boards[line][column] = 0

	for i in range(0, 4):
		newLine = line + xs[i]
		newColumn = column + ys[i]

		if newLine < 0 or newLine >= numLines or newColumn < 0 or newColumn >= numColumns:
			continue

		if (newLine, newColumn) not in visited:
			visited.append((newLine, newColumn))
			dfs(newLine, newColumn)

if __name__ == "__main__":
	numLines = int(input("Digite o numero de linhas: "))
	numColumns = int(input("Digite o numero de colunas: "))
	createBoards()

	initialLine = random.randint(0, numLines-1)
	initialColumn = random.randint(0, numColumns - 1)
	print("Vacuum Cleaner starts at {} {}".format(initialLine, initialColumn))

	start_clean(initialLine, initialColumn)
