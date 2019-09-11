import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('generateData/data.txt',unpack=True)

bins = np.arange(0.075, 3.075, 0.150)

plt.hist(y, bins, normed=True, histtype='step')
plt.xticks(np.arange(0.075, 3.075, 0.150))

plt.xlabel('x')
plt.ylabel('f(x)')

plt.show()
