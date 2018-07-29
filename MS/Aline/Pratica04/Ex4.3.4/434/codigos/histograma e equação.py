import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('dados.txt',unpack=True)

bins = np.arange(0.0, 2.1, 0.1)

plt.hist(data,bins,range=(0,9),normed=True,histtype='step')
plt.plot([0,1,2],[0,1,0],'r--', label='g(x)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.legend()
plt.axis([0.0,2.0,0.0,1.09])


plt.show()






