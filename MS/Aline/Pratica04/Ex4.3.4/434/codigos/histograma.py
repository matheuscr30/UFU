import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('dados.txt',unpack=True)

bins = np.arange(0.0, 2.1, 0.1)

plt.hist(y, bins, normed=True, histtype='step')
plt.xticks(np.arange(0.0, 2.1, 0.1))

plt.xlabel('x')
plt.ylabel('f(x)')

plt.show()
