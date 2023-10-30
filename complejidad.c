#include <stdio.h>

/*
    funcion(int n){
        // Estimar el numero de operaciones -> T(n)
    }

    // Notacion Oh-grande (Big-Oh)
    O(1) - Constante
    O(log n) - Logaritmico
    O(n) - Lineal
    O(n * log n) - N Logaritmico
    O(n^2) - Cuadratico
    O(n^3) - Cubico
    O(2^n) - Exponencial
    O(n!) - Factorial

*/
int main(){
    // Considerar el numero de operaciones que se llevan a cabo
    printf("\nHola"); // Constante O(1)

    int n;
    int i, j;
    for(i=0; i<n; i++){ // Lineal O(n)
        printf("\nHola"); 
    }

    for(i=0; i<n; i++){     // Cuadratica O(n^2)
        for(j=0; j<n; j++){  
            printf("\nHola"); 
        }
    }
    // # numero de operaciones = n*n = n^2

    i = 1;
    while(i<n){  // O(log n)
        //algo O(1);
        i *= 2;
    }
    // 2, 4, 8, 16, ... n

    // 2^1, 2^2, 2^3, 2^4, .... 
    // Llegando a la k-esia iteracion
    // 2^K >= N 
    // despejando K entonces:
    // K = log N
}

