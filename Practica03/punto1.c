
#include <stdio.h>

// Creamos una estructura para
// almacenar puntos en 2D
struct punto {
    int x;
    int y;
};

int main(){
    // Declaramos una variable de tipo struct punto
    struct punto punto1;
    /** MODIFICACIONES **/
    struct punto punto2;
    struct punto punto3;

    // Asignamos valores a la variable punto1
    punto1.x = 2;
    punto1.y = 7;
    // Imprimimos el contenido de la variable punto1
    printf("P1 = (%d, %d)", punto1.x, punto1.y);

    /** MODIFICACIONES **/ 

    // Asignamos valores a la variable punto2
    punto2.x = 6;
    punto2.y = 9;
    // Imprimimos el contenido de la variable punto1
    printf("P3 = (%d, %d)", punto2.x, punto2.y);

    // Asignamos valores a la variable punto2
    punto3.x = 14;
    punto3.y = -5;
    // Imprimimos el contenido de la variable punto1
    printf("P3 = (%d, %d)", punto3.x, punto3.y);

    return 0;
}

