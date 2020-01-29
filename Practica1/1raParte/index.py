import numpy as np
import algoritmos00 as alg

ff=np.random.randint(1,1000,1000)
ord00=alg.insertSort(ff)
ord01=alg.bubbleSort(ff)
print("Tiempo de Insert Sort:\t {} seg.".format(ord00[1]))
print("Tiempo de Bubble Sort:\t {} seg.".format(ord01[1]))