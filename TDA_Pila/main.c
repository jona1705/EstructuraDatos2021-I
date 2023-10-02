#include <stdio.h>
#include <stdbool.h>
#include "pila.h"

int main(){
    // Inicializando la variable pila
    Pila p1 = init();
    // MODIFICACIONES ACTIVIDAD 2
    Pila p2 = init();
    Pila p3 = init();
    // MODIFICACION ACTIVIDAD 3
    Pila p4 = init();

    // Insertando elementos
    p1 = push(p1, 3.4);
    p1 = push(p1, 9.1);
    p1 = push(p1, 12.4);
    p1 = push(p1, 8.5);
    p1 = push(p1, -3.7);
    p1 = push(p1, 6.5);
    printf("\nElementos en la pila p1 despues de insertar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila: %.2lf", peak(p1));
    // Borrando elementos
    p1 = pop(p1);
    p1 = pop(p1);
    p1 = pop(p1);
    printf("\nElementos en la pila p1 despues de borrar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila p1: %.2lf", peak(p1));

    // MODIFICACIONES ACTIVIDAD 2
    // Insertando elementos en la pila 2
    p2 = push(p2, 9.7);
    p2 = push(p2, 2.7);
    p2 = push(p2, -3.5);
    p2 = push(p2, 9.2);
    p2 = push(p2, -7.3);
    p2 = push(p2, 9.1);
    p2 = push(p2, 4.2);
    p2 = push(p2, -12.7);
    p2 = push(p2, 10.6);
    p2 = push(p2, -3.6);
    printf("\n\nElementos en la pila p2 despues de insertar: \n");
    desplegar(p2);
    printf("\nElemento en el tope de la pila p2: %.2lf", peak(p2));
    // MODIFICACIONES ACTIVIDAD 2
    // Borrando elementos
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    printf("\nElementos en la pila p2 despues de borrar: \n");
    desplegar(p2);
    printf("\nElemento en el tope de la pila p2: %.2lf", peak(p2));

    // MODIFICACIONES ACTIVIDAD 2
    // Insertando elementos en la pila 3
    p3 = push(p3, 7.8);
    p3 = push(p3, 0.5);
    p3 = push(p3, 7.3);
    p3 = push(p3, 4.6);
    p3 = push(p3, -2.1);
    p3 = push(p3, 4.3);
    p3 = push(p3, -17.6);
    p3 = push(p3, -4.8);
    p3 = push(p3, 11.4);
    p3 = push(p3, 13.2);
    p3 = push(p3, -4.9);
    p3 = push(p3, 15.3);
    printf("\n\nElementos en la pila p3 despues de insertar: \n");
    desplegar(p3);
    printf("\nElemento en el tope de la pila p3: %.2lf", peak(p3));
    // MODIFICACIONES ACTIVIDAD 2
    // Borrando elementos
    p3 = pop(p3);
    p3 = pop(p3);
    p3 = pop(p3);
    p3 = pop(p3);
    p3 = pop(p3);
    printf("\nElementos en la pila p3 despues de borrar: \n");
    desplegar(p3);
    printf("\nElemento en el tope de la pila p2: %.2lf", peak(p3));

    // MODIFICACION - ACTIVIDAD 3
    // Comparando pila 1 con pila 2
    if(sonIguales(p1, p2) == true){
        printf("\n\nLas pilas 1 y 2 son iguales ...");
    } else{
        printf("\n\nLas pilas 1 y 2 son diferentes ...");
    }

    // Creando una cuarta pila igual a la primera
    // Insertando elementos
    p4 = push(p4, 3.4);
    p4 = push(p4, 9.1);
    p4 = push(p4, 12.4);
    p4 = push(p4, 8.5);
    p4 = push(p4, -3.7);
    p4 = push(p4, 6.5);
    // Borrando elementos
    p4 = pop(p4);
    p4 = pop(p4);
    p4 = pop(p4);
    // MODIFICACION - ACTIVIDAD 3
    // Comparando pila 1 con pila 2
    if(sonIguales(p1, p4) == true){
        printf("\n\nLas pilas 1 y 4 son iguales ...");
    } else{
        printf("\n\nLas pilas 1 y 4 son diferentes ...");
    }

    // MODIFICACION ACTIVIDAD 4
    // Verificando la pila 1
    printf("\n\nEl promedio de elementos en la pila 1 es: %.2lf", promedio(p1));
    printf("\nEl elemento maximo en la pila 1 es: %.2lf", maximo(p1));
    printf("\nEl elemento minimo en la pila 1 es: %.2lf\n\n", minimo(p1));

    return 0;
}

