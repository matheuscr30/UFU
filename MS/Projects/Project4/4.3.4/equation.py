import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('generateData/data.txt',unpack=True)

bins = np.arange(0.05, 2.050, 0.1)

plt.hist(y, bins, normed=True, histtype='step')
plt.xticks(np.arange(0.05, 2.050, 0.1))

plt.plot([0,1,2],[0,1,0], 'g', label='g(x)')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()

plt.show()
