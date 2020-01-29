cpdef insertSort(arr):
    cdef int i,j,aux
    cdef a=arr
    for i in range(1,len(a)):
        aux=a[i] 
        j=i-1
        while j>=0 and aux<arr[j]:
            a[j+1]=arr[j]
            j=j-1
        a[j+1]=aux
    return a

cpdef bubbleSort(arr):
    cdef a=arr
    cdef swapped=True
    cdef int aux
    while swapped:
        swapped=False
        for i in range(len(a)):
            if a[i-1]>a[i]:
                aux=a[i]
                a[i]=a[i+1]
                a[i+1]=aux
                swapped=True
        n=n-1
    return a