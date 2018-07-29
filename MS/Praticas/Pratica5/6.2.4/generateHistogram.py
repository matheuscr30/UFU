"""import matplotlib.pyplot as plt
import numpy as np

x = np.loadtxt('probabilities.txt', unpack=True)
y = np.loadtxt('pdf.txt',unpack=True)
print(y)
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]

plt.hist([x, y], 30, density=True, label=['relative frequencies', 'pdf'])
plt.legend(loc='upper right')
plt.show()
"""

import numpy as np
import matplotlib.pyplot as plt

N = 30
fig, ax = plt.subplots()
ind = np.arange(N)
width = 0.35

x = np.loadtxt('probabilities.txt', unpack=True)
rects1 = ax.bar(ind, x, width, color='r')

y = np.loadtxt('pdf.txt',unpack=True)
rects2 = ax.bar(ind + width, y, width, color='y')

ax.set_xticks(ind)
ax.set_xticklabels(list(range(1, 31)))

ax.legend((rects1[0], rects2[0]), ('relative frequencies', 'pdf'))

plt.show()
