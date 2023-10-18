#include <stdio.h>

int main(){
    // Declaramos una variable entera
    int x = 6;
    // Declaramos un apuntador que
    // almacena la dirección de memoria
    // de la variable x
    int * y = &x;
    // Imprimimos el contenido de x
    printf("\nx= %d", x);
    // Imprimimos el contenido de x usando la
    // variable apuntador y
    printf("\nx= %d", *y);
    // Imprimimos la dirección de x
    printf("\ndir(x)= %p", &x);
    // Imprimimos la dirección de x usando la
    // variable apuntador y
    printf("\ndir(x)= %p", y);

    // Modificaciones al archivo ejemplo1:

    // 1) Declare una variable z de tipo flotante que almacene el valor de 17.23
    float z = 17.23;

    // 2) Declare una variable w de tipo apuntador a flotante que almacene la dirección de la variable z
    float * w = &z;

    // 3) A partir de la variable apuntador w incremente el contenido de la variable z en 10 unidades
    *w = (*w) + 10.0;

    // 4) Imprima los siguientes valores usando las variables z y w:

        // a) Imprima el contenido de z
        printf("\nz= %.2f", z);

        // b) Imprima la dirección de z
        printf("\nz= %p", &z);

        // c) Imprima el contenido de z usando w
        printf("\nz= %.2f", *w);

        // d) Imprima la dirección de la variable w
        printf("\ndir(w)= %p", &w);


    return 0;

}