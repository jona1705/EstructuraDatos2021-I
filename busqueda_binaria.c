#include <stdio.h>
#include <limits.h>

// Función para realizar una búsqueda binaria en un arreglo ordenado
int busquedaBinaria(int arreglo[], int n, int valor_buscado) {
    int izquierdo = 0;
    int derecho = n - 1;
    
    while (izquierdo <= derecho) {
        // Calcular el punto medio del rango actual
        int medio = izquierdo + (derecho - izquierdo) / 2;

        if (arreglo[medio] == valor_buscado) {
            // Si el valor en el punto medio es igual al valor buscado, lo hemos encontrado
            return medio;
        }
        
        if (arreglo[medio] > valor_buscado) {
            // Si el valor en el punto medio es mayor que el valor buscado, descartamos la mitad derecha
            derecho = medio - 1;
        } else {
            // Si el valor en el punto medio es menor que el valor buscado, descartamos la mitad izquierda
            izquierdo = medio + 1;
        }
    }
    
    // Si llegamos aquí, el elemento no se encontró en el arreglo
    return INT_MIN; 
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int buscado = 7;

    int indice = busquedaBinaria(arreglo, n, buscado);

    if (indice != INT_MIN) {
        printf("El elemento %d se encuentra en el índice %d.\n", buscado, indice);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", buscado);
    }

    return 0;
}
