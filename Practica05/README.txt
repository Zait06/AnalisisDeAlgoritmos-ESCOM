Para poder compilar esta practica pueden ser de dos maneras.
    1. Abrir la terminal dentro del folder de la practica y escribir 
			make
       para que pueda compilarlo, si no
    2. Abrir la terminal dentro del folder de la practica y escribir
        g++ LCS.cpp -c
        g++ main.cpp LCS.o -o main
    
Una vez compilado el programa, podemos ejecutarlo en la terminal de la siguiente forma:
    ./main archivo_analizar.txt archivo_resultado.csv      (Linux)
    main[.exe] archivo_analizar.txt archivo_resultado.csv    (Windows)
Se recomienda que el archivo donde se va a guardar el resultado, sea CVS para poder ver de mejor forma el resultado.

Los archivos "archivo_analizar.txt" deben tener tres lineas de escritura, donde:
	Primer Linea: Cadena 1 de caracteres a analizar.
	Segunda Linea: Salto de linea.
	Tercer Linea: Cadena 2 a comparar.

Ejemplo de ejecución:
	./main Ejercicio1.txt Resultado1.csv