# Programa inicial  
import sys
import copy
import numpy as np
import algoritmos00 as alg

if __name__== "__main__":
    dataIS=np.zeros((10,4),dtype=float)     # Arreglo de ceros 
    dataBS=np.zeros((10,4),dtype=float)

    print("Trabajando en el ordenamiento, espere por favor...\n")

    i=1000;j=0
    while i<=10000:
        # Lee los datos de un txt dependiendo el orden
        fm=np.loadtxt("./numeros/"+str(i)+"m.txt",dtype=int)            # Mejor caso
        fn=np.loadtxt("./numeros/"+str(i)+"n.txt",dtype=int)            # Caso promedio
        fp=np.loadtxt("./numeros/"+str(i)+"p.txt",dtype=int)            # Peor caso
        
        # Se hace copia del arreglo y se ordena por el metodo insert sort
        print("\n\tNumero de datos:\t{:3d}".format(i))
        dataIS[j][0]=i
        ord00,dataIS[j][1]=alg.insertSort(copy.copy(fm))            # Mejor caso
        ord01,dataIS[j][2]=alg.insertSort(copy.copy(fn))            # Caso promedio
        ord02,dataIS[j][3]=alg.insertSort(copy.copy(fp))            # Peor caso
        print("Tiempo del mejor caso de Insert Sort:\t {:2.10f} seg.".format(dataIS[j][1]))
        print("Tiempo de caso promedio de Insert Sort:\t {:2.10f} seg.".format(dataIS[j][2]))
        print("Tiempo del peor caso de Insert Sort:\t {:2.10f} seg.".format(dataIS[j][3]))
        
        # Se hace copia del arreglo y se ordena por el metodo insert sort
        dataBS[j][0]=i
        ord00,dataBS[j][1]=alg.bubbleSort(copy.copy(fm))           # Mejor caso
        ord01,dataBS[j][2]=alg.bubbleSort(copy.copy(fn))           # Caso promedio
        ord02,dataBS[j][3]=alg.bubbleSort(copy.copy(fp))           # Peor caso
        print("Tiempo del mejor caso de Bubble Sort:\t {:2.10f} seg.".format(dataBS[j][1]))
        print("Tiempo de caso promedio de Bubble Sort:\t {:2.10f} seg.".format(dataBS[j][2]))
        print("Tiempo del peor caso de Bubble Sort:\t {:2.10f} seg.".format(dataBS[j][3]))

        i=i+1000
        j=j+1

    np.savetxt("InsertTime.txt",dataIS,fmt='%f')
    np.savetxt("BubbleTime.txt",dataBS,fmt='%f')
    print("\nTrabajo terminado\n")