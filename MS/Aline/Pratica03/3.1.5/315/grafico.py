import matplotlib.pyplot as plt
import numpy as np

y,x = np.loadtxt('averageDelay.txt', delimiter=',', unpack=True)
plt.scatter(x,y, color='red', marker='x', s=25)

plt.plot([1,70],[4.27,4.27], 'c-.', label='4.27')

plt.xlabel('Number of executions (n)')
plt.ylabel('Average delay (d)')
plt.legend()
plt.show()
