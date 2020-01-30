# Generar documentos de datos
import numpy as np

if __name__== "__main__":    
    i=1000
    while i<=10000:
        normal=np.random.randint(1,10000,i)
        np.savetxt(str(i)+"n.txt",normal,fmt='%d')

        mejor=np.arange(1,i)
        np.savetxt(str(i)+"m.txt",mejor,fmt='%d')

        peor=np.flip(mejor)
        np.savetxt(str(i)+"p.txt",peor,fmt='%d')

        i=i+1000
    
    print("Fin del programa")
    # print(np.shape(normal))

    # print("Leyendo...\n")
    # print(np.loadtxt("1000n.txt",dtype=int)   #Lee el archivo y los guarda en un array
    # print(peor)