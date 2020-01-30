# Graficar los datos de Insert sort y Bubble sort

import numpy as np
import matplotlib.pyplot as plt

it=np.loadtxt("InsertTime.txt",dtype=float)
bt=np.loadtxt("BubbleTime.txt",dtype=float)
cant=it[:,0]
datos={
        0:it[:,1:],
        1:bt[:,1:]
    }

fig,axes=plt.subplots(nrows=1,ncols=2)
for i,ax in enumerate(axes):
    ax.plot(cant,datos[i][:,0],label="Mejor caso")
    ax.plot(cant,datos[i][:,1],label="Caso promedio")
    ax.plot(cant,datos[i][:,2],label="Peor caso")

    ax.set_xlabel("Cantidad de numeros")
    ax.set_ylabel("Tiempo")

    ax.legend()

plt.show()