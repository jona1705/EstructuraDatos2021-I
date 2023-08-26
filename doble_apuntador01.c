#include <stdio.h>

/*
    Clase: 23/08/2023
    Pasando un apuntador como parámetro a una función
*/

void f1(int * p){
    printf("%d ", *p);
}

void f2(int ** p){
    printf("%d ", **p);
}

int main(){
    int x = 3;
    int * p = &x;
    /* 
        Si pasamos un apuntador como parámetro
        a una función que recibe un apuntador
        se crea una copia de ese apuntador
        (p pasa por valor)
    */
    f1(p); // p pasa por valor

    /* 
        Si pasamos un apuntador como parámetro
        a una función que recibe un doble apuntador
        estamos pasando la dirección de p
        (p pasa por referencia)
    */
    f2(&p); // p pasa por referencia

    return 0;
}