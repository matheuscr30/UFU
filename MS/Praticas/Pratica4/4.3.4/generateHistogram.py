import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('generateData/data.txt',unpack=True)

bins = np.arange(0.05, 2.050, 0.1)

plt.hist(y, bins, normed=True, histtype='step')
plt.xticks(np.arange(0.05, 2.050, 0.1))

plt.xlabel('x')
plt.ylabel('f(x)')

plt.show()
