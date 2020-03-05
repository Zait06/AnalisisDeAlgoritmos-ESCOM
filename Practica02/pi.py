import sys
import numpy as np
import pandas as pd
from scipy import stats
import matplotlib.pyplot as plt

np.random.seed(1984)


def mc_pi_aprox(N=10000):
    plt.figure(figsize=(6,6))
    x, y = np.random.uniform(-1, 1, size=(2, N))
    print(x, y)
    interior = (x**2 + y**2) <= 1.0
    print(interior)
    pi = interior.sum() * 4 / N
    error = abs((pi - np.pi) / pi) * 100
    exterior = np.invert(interior)
    plt.plot(x[interior], y[interior], 'b.')
    print(x[interior], y[interior])
    
    print('=====>', x[exterior], y[exterior])
    plt.plot(x[exterior], y[exterior], 'r.')
    print(x[0], x[10])
    plt.plot(0, 0, label='$\hat \pi$ = {:4.4f}\nerror = {:4.4f}%'.format(pi,error), alpha=0)
    plt.axis('square')
    plt.legend(frameon=True, framealpha=0.9, fontsize=14)
    plt.show()

mc_pi_aprox(int(sys.argv[1]))

