Para poder compilar esta practica pueden ser de dos maneras.
    1. Abrir la terminal dentro del folder de la practica y escribir 
        make
       para que pueda compilarlo, si no
    2. Abrir la terminal dentro del folder de la practica y escribir
        g++ Cambio.cpp Mochila.cpp main.cpp -o main
    
Una vez compilado el programa, podemos ejecutarlo en la terminal de la siguiente forma:
    ./main nombre_archivo.ext opcion valor_N
Donde la opcion puede tomar los siguientes valores:
    [1] Devolver cambio con programación voráz.
    [2] Devolver cambio con programación dinámica.
    [3] Problema de la mochila con programación voráz.
    [4] Problema de la mochila con programación dinámica.
Ejemplo:
    ./main set00.txt 1 100
    Donde 100 es el valor de cambio a dar
Tener en cuenta que el valor_N es lo mismo que el peso para la mochila. Ejemplo:
    ./main set03.txt 1 11
    Donde 11 es el peso de la mochila

Si es que quiere agregar un archivo, este debe tener la forma:
    moneda1
    moneda2
    ...
    monedaN
si se trata de un conjunto para trabajar con el problema de devolver cambio. Un ejemplo es el set00.txt y set01.txt.

Si es un conjunto para trabajar con la mochila, entonces se guarda de la siguiente forma:
    peso1 valor1
    peso2 valor2
        ...
    pesoN valorN
Esta dado por dos valores por linea, el primero es el peso y el sundo un valor, separados por un espacio y un salto de linea si es otro valor