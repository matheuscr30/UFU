import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('data.dat',unpack=True)

bins = np.arange(1, 11)

plt.hist(y, bins, histtype='bar', rwidth=0.8)
plt.xticks(np.arange(1, 11))

plt.show()
