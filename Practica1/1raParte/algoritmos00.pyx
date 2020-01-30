import time

# Ordenamiento Insert Sort
cpdef insertSort(arr):
    cdef double ti=time.time()
    cdef int i,j,aux
    cdef a=arr
    for i in range(1,len(a)):
        j=i-1
        while j>=0 and a[j]>a[j+1]:
            a[j],a[j+1]=a[j+1],a[j] # swap
            j=j-1
    cdef double tf=time.time()-ti
    return a,tf

# Ordenamiento Bublle Sort
cpdef bubbleSort(arr):
    cdef a=arr
    cdef double ti=time.time()
    cdef swapped=True
    cdef int aux,n=len(arr)
    while swapped:
        swapped=False
        for i in range(1,n):
            if a[i-1]>a[i]:
                a[i-1],a[i]=a[i],a[i-1]  # swap
                swapped=True
        n=n-1
    cdef double tf=time.time()-ti
    return a,tf