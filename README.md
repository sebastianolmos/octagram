# octagram
Libreria construida para el curso Geometria Computacional

## Tarea 2

Para esta tarea se trabajo con linux (con compilador gcc) para poder usar de buena manera el timer implementado (no funcionaba bien en windows)
Entonces los comandos son 

Para compilar la tarea:

    cmake .
    make

Para correr todos los tests

    sh runAlltests.sh

Para generar todos los puntos en el directorio samples/points

    sh generateAllPoints.sh

Para generar todos los tiempos, ejecutando los algoritmos con todos los puntos (ATENCION: si ejecuta los archivos de un millon de pnutos con el algoritmo de Gift Wrapping, la ejecucion durara aprox un día):

    sh runAllConvexHull.sh