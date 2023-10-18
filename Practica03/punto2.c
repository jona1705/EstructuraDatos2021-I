#include <stdio.h>
#define N 5

// Creamos una estructura para
// almacenar puntos en 2D
struct punto {
    int x;
    int y;
};

int main(){
    // Declaramos un arreglo de N variables de tipo struct punto
    struct punto puntos[N];
    // Asignamos valores a la variables del arreglo puntos
    puntos[0].x = -3;
    puntos[0].y = 5;
    puntos[1].x = 7;
    puntos[1].y = 4;
    puntos[2].x = 5;
    puntos[2].y = -1;
    /** MODIFICACIONES **/
    puntos[3].x = 7;
    puntos[3].y = 9;
    puntos[4].x = -3;
    puntos[4].y = 8;
    // Imprimimos el contenido de la variables del arreglo puntos
    printf("P1 = (%d, %d)", puntos[0].x, puntos[0].y);
    printf("\nP2 = (%d, %d)", puntos[1].x, puntos[1].y);
    printf("\nP3 = (%d, %d)", puntos[2].x, puntos[2].y);
    /** MODIFICACIONES **/
    printf("\nP4 = (%d, %d)", puntos[3].x, puntos[3].y);
    printf("\nP5 = (%d, %d)\n\n", puntos[4].x, puntos[4].y);

    return 0;
}

