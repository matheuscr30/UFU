import matplotlib.pyplot as plt
import numpy as np

sizes = ['360', '3600', '36000', '360000']
seeds = ['12345', '124564', '242453', '3413124', '98786465']

y = np.loadtxt('pdf.txt',unpack=True)
bins = np.arange(0.0, 15.0, 1.0)
fig = plt.figure()

for i in range(0, len(sizes)):
    for j in range(0, len(seeds)):
        plt.clf()

        aux = sizes[i] + '/values' + sizes[i] + '_' + seeds[j] + '.txt'
        x = np.loadtxt(aux, unpack=True)

        plt.hist([x, y], bins, density=True, label=['relative frequencies', 'pdf'])
        plt.legend(loc='upper right')

        fig.savefig(sizes[i] + '/histogram' + sizes[i] + '_' + seeds[j] + '.png')
