import matplotlib.pyplot as plt
import numpy as np

r, w, d, s, l, q, x = np.loadtxt('steady-states.txt', delimiter=',', unpack=True)

print('average interarrival time (r) = %.2f' % np.mean(r))
print('average wait ............ (w) = %.2f' % np.mean(w))
print('average delay ........... (d) = %.2f' % np.mean(d))
print('average service time .... (s) = %.2f' % np.mean(s))
print('average # in the node ... (l) = %.2f' % np.mean(l))
print('average # in the queue .. (q) = %.2f' % np.mean(q))
print('utilization ............. (x) = %.2f' % np.mean(x))

