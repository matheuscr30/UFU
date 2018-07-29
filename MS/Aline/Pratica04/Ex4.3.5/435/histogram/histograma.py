import matplotlib.pyplot as plt
import numpy as np

dados = np.loadtxt('resultadoPROP.txt',unpack=True)

plt.hist(dados, len(dados), histtype='step',normed=True)
plt.xlabel('x')
plt.ylabel('f(x)')

plt.show()
