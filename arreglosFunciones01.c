#include <stdio.h>

/*
    Clase: 23/08/2023
    Primera forma de pasar un arreglo bidimensional
    a una funcion
*/

/*
    FORMA 1 
    Los parametros de una función se empiezan a leer
    a partir del parámetro que está a la derecha de ña
    declaración de la función, es decir primero leeríamos
    m, luego n y finalmente mat[m][n] */

void imprimir(int m, int n, int mat[m][n]){
        int i, j;
        for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}




/* FORMA 3 : Usando un apuntador a un arreglo
void imprimir(int m, int n, int * p){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            // Usando la formula de direccionamiento
            printf("%d ", *(p + i*n + j));
        }
        printf("\n");
    }
}*/

int main(){
    //int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int a[2][3] = {1, 2, 3, 4, 5, 6};
    printf("\n");

    //   Forma 1
    // Llamamos a al función y pasamos el nombre del
    // arreglo como parámetro
    // a representa la dirección base del arreglo bidimensional
    imprimir(2, 3, a);

    return 0;
}