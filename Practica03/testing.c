
#include <stdio.h>
#include <stdlib.h>

// Un mimebro de una estructura
// puede ser de tipo apuntador
struct testing {
    int id;
    int * ptr;
    /** MODIFICACION **/
    int * arr;
};

int main(){
    // Declaramos una variable de tipo struct testing
    struct testing test1;
    // Declaramos una variable de tipo apuntador a struct testing
    struct testing * test2;
    /** MODIFICACION **/
    struct testing test3;

    // Trabajando con la variable test1
    test1.id = 100;
    // La forma básica de asignarle un valor a un apuntador
    // es tomar la referencia de un dato ya existente
    int x = 25;
    test1.ptr = &x; // El apuntador ptr apunta a la direccion de x

    // Trabajando con la variable test2
    // En este caso tenemos que asignarle un espacio de memoria para almacenar
    // datos
    test2 = (struct testing *) malloc(sizeof(struct testing));
    if(test2 == NULL) exit(0);
    // Asignando datos a la variable test2
    test2->id = 200;
    test2->ptr = &x;

    // Imprimiendo el contenido de test1 y test2
    printf("\nid=%d, ptr=%d", test1.id, *(test1.ptr));
    printf("\nid=%d, ptr=%d", test2->id, *(test2->ptr));

    /** MODIFICACION **/
    test3.id = 300;
    int e = 45;
    test3.ptr = &e;
    test3.arr = (int *) malloc(5 * sizeof(int));
    if(test3.arr == NULL) exit(0);

    // Llenando el arreglo arr
    int i;
    for(i=0; i<5; i++){
        test3.arr[i] = i+1;
    }

    // Imprimir contenido de la variable tesst3
    printf("\n\ntest3.id=%d", test3.id);
    printf("\ntest3.ptr=%d", *(test3.ptr));
    printf("\ntest3.arr=");
    for(i=0; i<5; i++){
        printf(" %d", test3.arr[i]);
    }
    printf("\n\n");


    // Liberando el contenido de la variable test2
    free(test2);
    /** MODIFICACION **/
    // Liberabdo el contenido de la variable arr
    free(test3.arr);

    return 0;
}

