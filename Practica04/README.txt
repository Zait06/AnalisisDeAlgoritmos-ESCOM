Para poder compilar esta practica pueden ser de dos maneras.
    1. Abrir la terminal dentro del folder de la practica y escribir 
        make
       para que pueda compilarlo, si no
    2. Abrir la terminal dentro del folder de la practica y escribir
        g++ Lista.cpp MatrizVoraz.cpp MatrizDinamica.cpp -o main
    
Una vez compilado el programa, podemos ejecutarlo en la terminal de la siguiente forma:
    ./main opcion_algoritmo conjunto0i.txt      (Linux)
    main.exe opcion_algoritmo conjunto0i.txt    (Windows)
Donde la opcion_algoritmo puede tomar los siguientes valores:
    [1] Numero de operaciones a realizar con algoritmo voraz.
    [2] Numero de operaciones a realizar con programacion dinamica.

Conjunto0i.txt representa un archivo txt con las dimensiones de N matrices. Para
poder guardar la matriz, se escribe primero el numero de filas, segidas de un espacio donde irán
el numero de columnas de la matriz, y un interlineado si se desea guardar otra matriz. Ejemplo:
    1 2
    2 3
    3 4
De igual forma, y por conveniencia, se recomienda guardar los valores de las dimensiones para que
coincidan entre columnas y filas, es decir, si escribimos una matriz con dimensión (a b), la siguiente
matriz debe tener dimensiones (b c) y así con las demás.

Ejemplo de ejecución:
    ./main 2 conjunto01.txt
Es decir se ejecutará el algoritmo de programacion dinamica y usara las matrices del archivo
conjunto01.txt