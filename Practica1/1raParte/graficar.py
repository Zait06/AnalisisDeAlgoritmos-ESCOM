# Graficar los datos de Insert sort y Bubble sort

import numpy as np
import matplotlib.pyplot as plt

it=np.loadtxt("InsertTime.txt",dtype=float)
bt=np.loadtxt("BubbleTime.txt",dtype=float)

fig,axes=plt.subplots(nrows=1,ncols=2)
for ax in axes:
    ax.plot(it[0],it[1])
    ax.set_xlabel("Numero de variables")
    ax.set_ylabel("Tiempo")

plt.show()

# fig.savefig("InsertSort.jpg",dpi=200)
# fig.savefig("BubbleTime.jpg",dpi=200) 