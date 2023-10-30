#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ** arregloCadenas = NULL; // Inicializamos un apuntador a un arreglo de cadenas
    int tamArreglo = 0;         // Inicializamos el tamaño del arreglo

    // Añadiendo cadenas al arreglo dinámico
    arregloCadenas = (char **) malloc(sizeof(char *));  // Asignando memoria para un apuntador a cadena
    if (arregloCadenas == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }

    // Añadir una cadena al arreglo
    arregloCadenas[tamArreglo] = (char *)malloc(strlen("CDMX") + 1);  // +1 para el término NULL
    if (arregloCadenas[tamArreglo] == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    strcpy(arregloCadenas[tamArreglo], "CDMX");
    tamArreglo++;

    // Añadir otra cadena al arreglo
    arregloCadenas = (char **)realloc(arregloCadenas, (tamArreglo + 1) * sizeof(char *));
    if (arregloCadenas == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    arregloCadenas[tamArreglo] = (char *)malloc(strlen("Veracruz") + 1);  // +1 para el término NULL
    if (arregloCadenas[tamArreglo] == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    strcpy(arregloCadenas[tamArreglo], "Veracruz");
    tamArreglo++;

    // Añadir otra cadena al arreglo
    arregloCadenas = (char **)realloc(arregloCadenas, (tamArreglo + 1) * sizeof(char *));
    if (arregloCadenas == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    arregloCadenas[tamArreglo] = (char *)malloc(strlen("Monterrey") + 1);  // +1 para el término NULL
    if (arregloCadenas[tamArreglo] == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    strcpy(arregloCadenas[tamArreglo], "Monterrey");
    tamArreglo++;

    // Añadir otra cadena al arreglo
    arregloCadenas = (char **)realloc(arregloCadenas, (tamArreglo + 1) * sizeof(char *));
    if (arregloCadenas == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    arregloCadenas[tamArreglo] = (char *)malloc(strlen("Jalisco") + 1);  // +1 para el término NULL
    if (arregloCadenas[tamArreglo] == NULL) {
        perror("Fallo asignacion de memoria");
        return 1;
    }
    strcpy(arregloCadenas[tamArreglo], "Jalisco");
    tamArreglo++;

    // Imprimir los arreglos
    printf("\n\nLas cadenas son: \n");
    for (int i = 0; i < tamArreglo; i++) {
        printf("%d: %s\n", i+1, arregloCadenas[i]);
    }

    // Liberando memoria
    for (int i = 0; i < tamArreglo; i++) {
        free(arregloCadenas[i]);
    }
    free(arregloCadenas);

    return 0;
}
