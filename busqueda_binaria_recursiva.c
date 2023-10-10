#include <stdio.h>
#include <limits.h>

// Función recursiva para búsqueda binaria
int busquedaBinaria(int arreglo[], int inicio, int fin, int valor_buscado) {
    if (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Si el objetivo se encuentra en el elemento medio, lo hemos encontrado
        if (arreglo[medio] == valor_buscado)
            return medio;

        // Si el objetivo es menor que el elemento medio, buscar en la mitad izquierda
        if (arreglo[medio] > valor_buscado)
            return busquedaBinaria(arreglo, inicio, medio - 1, valor_buscado);

        // Si el objetivo es mayor que el elemento medio, buscar en la mitad derecha
        return busquedaBinaria(arreglo, medio + 1, fin, valor_buscado);
    }

    // Si no encontramos el objetivo, retornar -1 para indicar que no se encuentra en el arreglo
    return INT_MIN;
}

int main() {
    int arreglo[] = {2, 3, 4, 10, 40};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
    int buscado = 10;

    int resultado = busquedaBinaria(arreglo, 0, tamaño - 1, buscado);

    if (resultado != INT_MIN)
        printf("El elemento %d se encuentra en la posición %d\n", buscado, resultado);
    else
        printf("El elemento %d no se encuentra en el arreglo\n", buscado);

    return 0;
}
