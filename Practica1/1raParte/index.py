import sys
import copy
import numpy as np
import algoritmos00 as alg

if __name__== "__main__":
    nombre=sys.argv[1]
    ff=np.loadtxt("./numeros/"+nombre+"n.txt",dtype=int)
    print("Trabajando en el ordenamiento, espere por favor...\n")
    
    ord00=alg.insertSort(copy.copy(ff))
    ord01=alg.insertSort(copy.copy(ff))

    print("Tiempo de caso promedio de Insert Sort:\t {:2.10f} seg.".format(ord00[1]))
    print("Tiempo de caso promeido de Bubble Sort:\t {:2.10f} seg.".format(ord01[1]))