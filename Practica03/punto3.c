#include <stdio.h>
#include <math.h>
#define N 5

// Creamos una estructura para
// almacenar puntos en 2D
struct punto {
    int x;
    int y;
};

// Declaramos una función que recibe como argumentos dos
// variables de tipo struct punto
float distancia(struct punto p1, struct punto p2){
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}


int main(){
    // Declaramos un arreglo de N variables de tipo struct punto
    // Tome nota de que es posible inicializar el arreglo puntos en una
    // sola línea
    struct punto puntos[N] = {{-3, 5}, {7, 4}, {5, -1}, {4, 6}, {8, 9}};

    // Calculando la distancia del punto 1 al punto 2
    printf("\nLa distancia del punto P1 = (%d, %d) al punto P2 = (%d, %d) es: %.2f",
    puntos[0].x, puntos[0].y, puntos[1].x, puntos[1].y, distancia(puntos[0], puntos[1]));

    /***   MODIFICACIONES ***/

    // Calculando la distancia del punto 2 al punto 3
    printf("\nLa distancia del punto P2 = (%d, %d) al punto P3 = (%d, %d) es: %.2f",
    puntos[1].x, puntos[1].y, puntos[2].x, puntos[2].y, distancia(puntos[1], puntos[2]));

    // Calculando la distancia del punto 4 al punto 5
    printf("\nLa distancia del punto P4 = (%d, %d) al punto P5 = (%d, %d) es: %.2f\n",
    puntos[3].x, puntos[3].y, puntos[4].x, puntos[4].y, distancia(puntos[3], puntos[4]));

    return 0;
}

