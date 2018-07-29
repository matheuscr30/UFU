import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('generateData/data.txt',unpack=True)

bins = np.arange(0.5, 20.0, 1.0)

plt.hist(y, bins, normed=True, histtype='step')
plt.xticks(np.arange(0.5, 20.0, 1.0))

plt.xlabel('x')
plt.ylabel('f(x)')

plt.show()
