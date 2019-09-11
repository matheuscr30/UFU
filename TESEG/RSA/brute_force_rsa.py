import string
import time

def brute_force(c, e, n):
	start_time = time.time()

	for p in range(2, n):
		guess = (p ** e) % n
		if guess == c:
			end_time = time.time() - start_time
			return p, end_time
	return -1

if __name__ == '__main__':
	input_file = open("rsa.txt", "r")

	while True:
		line = input_file.readline()
		if not line:
			break

		if line[0] == 'e':
			# Parse the first line to get 'e' and 'n'
			values = line.replace('= ', '=').replace('  ', ' ').replace('\n', '').split(' ')
			e = int(values[0][2:])
			n = int(values[1][2:])

			# Parse the second line to get the ciphered value
			cipher_line = input_file.readline()
			cipher = int(cipher_line.replace('= ', '=').replace('\n', '')[8:])

			p, end_time = brute_force(cipher, e, n)

			print(f'For (c, e, n) = ({cipher}, {e}, {n})')
			print(f'P = {p} found in {p-1} iterations in {end_time} seconds')
			print()
		elif line[0] == '-':
			continue
