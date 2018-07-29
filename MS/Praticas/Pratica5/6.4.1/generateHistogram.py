

import matplotlib.pyplot as plt
import numpy as np

x = np.loadtxt('data.txt',unpack=True)

bins = np.arange(0, 11, 1)

plt.hist(x, bins, density=True, histtype='step')
plt.xticks(np.arange(0, 11, 1))

plt.show()
