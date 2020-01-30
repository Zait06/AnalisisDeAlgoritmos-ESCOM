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
        fm=np.loadtxt("./numeros/"+str(i)+"m.txt",dtype=int)            # Lee los datos de un txt
        fn=np.loadtxt("./numeros/"+str(i)+"n.txt",dtype=int)            # Lee los datos de un txt
        fp=np.loadtxt("./numeros/"+str(i)+"p.txt",dtype=int)            # Lee los datos de un txt
        # dataIS[j][0]=i
        # ord00,dataIS[j][1]=alg.insertSort(copy.copy(fm))           # Se hace copia del arreglo y se ordena
        # ord01,dataIS[j][2]=alg.insertSort(copy.copy(fn))           # Se hace copia del arreglo y se ordena
        # ord02,dataIS[j][3]=alg.insertSort(copy.copy(fp))           # Se hace copia del arreglo y se ordena
        # print("Listo {}".format(i))
        dataBS[j][0]=i
        ord00,dataBS[j][1]=alg.bubbleSort(copy.copy(fm))           # Se hace copia del arreglo y se ordena
        ord01,dataBS[j][2]=alg.bubbleSort(copy.copy(fn))           # Se hace copia del arreglo y se ordena
        ord02,dataBS[j][3]=alg.bubbleSort(copy.copy(fp))           # Se hace copia del arreglo y se ordena
        print("Listo {}".format(i))
        i=i+1000
        j=j+1

    # np.savetxt("InsertTime.txt",dataIS,fmt='%f')
    np.savetxt("BubbleTime.txt",dataBS,fmt='%f')
    print("\nTrabajo terminado\n")

    # ord00=alg.insertSort(copy.copy(ff))
    # print("Tiempo de caso promedio de Insert Sort:\t {:2.10f} seg.".format(ord00[1]))
    
    # ord01=alg.bubbleSort(copy.copy(ff))
    # print("Tiempo de caso promeido de Bubble Sort:\t {:2.10f} seg.".format(ord01[1]))