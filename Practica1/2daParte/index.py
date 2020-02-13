import algoritmos00 as alg
import time

if __name__== "__main__":
    i=0
    print("\n\tAlgoritmo 1")
    while(i<=40):
        ti=time.time()
        res=alg.fibonacci01(i)
        print("n={}\tResultado:{}\tTiempo: {:2.10f} seg".format(i,res,time.time()-ti))
        i=i+5

    print("\n\tAlgoritmo 2")
    i=0
    while(i<=40):
        ti=time.time()
        res=alg.fibonacci02(i)
        print("n={}\tResultado:{}\tTiempo: {:2.10f} seg".format(i,res,time.time()-ti))
        i=i+5

    print("\n\tAlgoritmo 3")
    i=0
    while(i<=40):
        ti=time.time()
        res=alg.fibonacci03(i)
        print("n={}\tResultado:{}\tTiempo: {:2.10f} seg".format(i,res,time.time()-ti))
        i=i+5