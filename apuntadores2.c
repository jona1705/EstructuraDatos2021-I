#include <stdio.h>

/*
    21/08/2023
	Almacenamiento de variables, apuntadores
    y aritm�tica de apuntadores e impresion de valores

*/

int main(){
    double a[5] = {1.34, 2.56, 3.23, 4.54, 5.21};

    // Calculando el tamanio en bytes del arreglo a
    printf("%lu", sizeof(a)); // 40 bytes

    // p apunta a la dirección base de a
    double * p = a;

    // Imprime la direccion de a
    printf("\ndir(a) = %p", a);
    // Imprime la dirección de a usando p
    printf("\ndir(a) = %p", p);
    
    int i;
    // Imprimimos los valores de a usando el apuntador p
    printf("\nValores del arreglo: ");
    for(i = 0; i<5; i++){
        printf("\n%lf", *p);
        p++;
    }

    // El apuntador vuelve apuntar a la direccion base de a
    p = &a[0]; 

    // Multiplicamos cada valor por 5 desplazandonos
    // con el apuntador p
    printf("\n\nMultiplicando por 5: ");
    for(i = 0; i<5; i++){
        printf("\n%lf", (*p) * 5.0);
        p++;
    }

    printf("\n\n");

    return 0;
}
