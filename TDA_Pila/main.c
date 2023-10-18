#include <stdio.h>
#include <stdbool.h>
#include "pila.h"

int main(){
    // Inicializando instancias de pila
    Pila p1 = init();
    Pila p2 = init();

    // Insertando elementos en la pila 1
    p1 = push(p1, 3.4);
    p1 = push(p1, 9.1);
    p1 = push(p1, 12.4);
    p1 = push(p1, 8.5);
    p1 = push(p1, -3.7);
    p1 = push(p1, 6.5);
    printf("\nElementos en la pila p1 despues de insertar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila: %.2lf", peak(p1));
    // Borrando elementos en la pila 1
    p1 = pop(p1);
    p1 = pop(p1);
    p1 = pop(p1);
    printf("\nElementos en la pila p1 despues de borrar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila p1: %.2lf", peak(p1));

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
    // Borrando elementos en la pila 2
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    p2 = pop(p2);
    printf("\nElementos en la pila p2 despues de borrar: \n");
    desplegar(p2);
    printf("\nElemento en el tope de la pila p2: %.2lf", peak(p2));

    return 0;
}

