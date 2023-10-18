#include <stdio.h>

// Creamos una estructura para
// almacenar puntos en 2D
struct punto {
    int x;
    int y;
};

// Creamos una estructura para 
// representar un ractangulo en 
// un plano cartesiano
struct rectangulo{
    struct punto p1;
    struct punto p2;
    struct punto p3;
    struct punto p4;
};

int main(){
    // Declaramos una variable de tipo rectangulo
    struct rectangulo rect1;
    /**  Variables nuevas **/
    struct rectangulo rect2, rect3; 
    
    // Asignamos valores a la variable p1:
    // Coordenadas del primer punto
    rect1.p1.x = 0;
    rect1.p1.y = 0;
    // Coordenadas del segundo punto
    rect1.p2.x = 4;
    rect1.p2.y = 0;
    // Coordenadas del tercer punto
    rect1.p3.x = 4;
    rect1.p3.y = 3;
    // Coordenadas del cuarto punto
    rect1.p4.x = 3;
    rect1.p4.y = 0;

    // Imprimiendo las coordenadas del rectangulo
    printf(" P1 = (%d, %d)\n P2 = (%d, %d)\n P3 = (%d, %d)\n P4 = (%d, %d)", 
    rect1.p1.x, rect1.p1.y, rect1.p2.x, rect1.p2.y, rect1.p3.x, rect1.p3.y, 
    rect1.p4.x, rect1.p4.y);

    /***   MODIFICACIONES ***/

    // Asignamos valores a la variable p2:
    // Coordenadas del primer punto
    rect2.p1.x = 2;
    rect2.p1.y = 3;
    // Coordenadas del segundo punto
    rect2.p2.x = 4;
    rect2.p2.y = 3;
    // Coordenadas del tercer punto
    rect2.p3.x = 4;
    rect2.p3.y = 7;
    // Coordenadas del cuarto punto
    rect2.p4.x = 2;
    rect2.p4.y = 7;

    // Imprimiendo las coordenadas del rectangulo rect2
    printf("\n\n P1 = (%d, %d)\n P2 = (%d, %d)\n P3 = (%d, %d)\n P4 = (%d, %d)", 
    rect2.p1.x, rect2.p1.y, rect2.p2.x, rect2.p2.y, rect2.p3.x, rect2.p3.y, 
    rect2.p4.x, rect2.p4.y);

    // Asignamos valores a la variable p3:
    // Coordenadas del primer punto
    rect3.p1.x = 2;
    rect3.p1.y = 4;
    // Coordenadas del segundo punto
    rect3.p2.x = 6;
    rect3.p2.y = 4;
    // Coordenadas del tercer punto
    rect3.p3.x = 6;
    rect3.p3.y = 2;
    // Coordenadas del cuarto punto
    rect3.p4.x = 2;
    rect3.p4.y = 2;

    // Imprimiendo las coordenadas del rectangulo rect3
    printf("\n\n P1 = (%d, %d)\n P2 = (%d, %d)\n P3 = (%d, %d)\n P4 = (%d, %d)\n\n", 
    rect3.p1.x, rect3.p1.y, rect3.p2.x, rect3.p2.y, rect3.p3.x, rect3.p3.y, 
    rect3.p4.x, rect3.p4.y);

    return 0;
}
