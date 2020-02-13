# Serie de Fibonacci
import numpy as np
import time

arr=(np.ones(1000,dtype='i8'))*(-1)

# Primera versión Fibonacci
cpdef fibonacci01(long long n):
    if n<2:
        return n
    else:
        return fibonacci01(n-1)+fibonacci01(n-2)

# Segunda versión Fibonacci
cpdef fibonacci02(long long n):
    cdef arreglo=np.zeros(n+1,dtype='i8')
    cdef int i
    if n<2:
        return n
    else:
        arreglo[0]=0;
        arreglo[1]=1;
        for i in range(2,n+1):
            arreglo[i]=arreglo[i-1]+arreglo[i-2]
        return arreglo[n]

# Tercera versión Fibonacci
cpdef fibonacci03(long long n):
    cdef int i
    if n<2:
        return n
    if arr[n-1]==-1:
        arr[n-1]=fibonacci03(n-1)
    if arr[n-2]==-1:
        arr[n-2]=fibonacci03(n-2)
    arr[n]=arr[n-1]+arr[n-2]
    return arr[n]