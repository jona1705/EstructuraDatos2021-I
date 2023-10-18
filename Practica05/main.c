#include <stdio.h>
#include <float.h>
#include "cola.h"

int main(){
    // Inicializando instancia de Cola
	Cola c1 = init();
    // MODIFICACIONES ACTIVIDAD 2
    Cola c2 = init();
    Cola c3 = init();

    // Insertando elementos
	c1 = encolar(c1, 5.6);
	c1 = encolar(c1, 7.2);
	c1 = encolar(c1, 71.5);
	c1 = encolar(c1, 12.7);
    c1 = encolar(c1, 6.3);
    c1 = encolar(c1, 9.8);
    printf("\nElementos en la cola c1 despues de insertar: \n");
    desplegar(c1);
    if(frente(c1) != DBL_MIN){
		printf("\nElemento en el frente (cola 1): %.2lf", frente(c1));
	}
    if(final(c1) != DBL_MIN){
		printf("\nElemento en el final (cola 1): %.2lf", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d", size(c1));

    // Borrando elementos
    c1 = desencolar(c1);
    c1 = desencolar(c1);

    printf("\n\nElementos en la cola c1 despues de borrar: \n");
    desplegar(c1);
    if(frente(c1) != DBL_MIN){
		printf("\nElemento en el frente (cola 1): %.2lf", frente(c1));
	}
    if(final(c1) != DBL_MIN){
		printf("\nElemento en el final (cola 1): %.2lf", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d\n\n", size(c1));

    // MODIFICACIONES ACTIVIDAD 2
    // Insertando elementos en la cola 2
    c2 = encolar(c2, 9.7);
    c2 = encolar(c2, 2.7);
    c2 = encolar(c2, -3.5);
    c2 = encolar(c2, 9.2);
    c2 = encolar(c2, -7.3);
    c2 = encolar(c2, 17.9);
    c2 = encolar(c2, -9.5);
    c2 = encolar(c2, 9.1);
    c2 = encolar(c2, 4.2);
    c2 = encolar(c2, -12.7);
    c2 = encolar(c2, 10.6);
    c2 = encolar(c2, -3.6);
    printf("Elementos en la cola c2 despues de insertar: \n");
    desplegar(c2);
    if(frente(c2) != DBL_MIN){
		printf("\nElemento en el frente (cola 2): %.2lf", frente(c2));
	}
    if(final(c2) != DBL_MIN){
		printf("\nElemento en el final (cola 2): %.2lf", final(c2));
	}
	printf("\nNumero de Elementos en la cola 2: %d\n\n", size(c2));

    // MODIFICACIONES ACTIVIDAD 2
    // Borrando elementos
    c2 = desencolar(c2);
    c2 = desencolar(c2);
    c2 = desencolar(c2);
    c2 = desencolar(c2);
    c2 = desencolar(c2);
    printf("Elementos en la cola c2 despues de borrar: \n");
    desplegar(c2);
    if(frente(c2) != DBL_MIN){
		printf("\nElemento en el frente (cola 2): %.2lf", frente(c2));
	}
    if(final(c2) != DBL_MIN){
		printf("\nElemento en el final (cola 2): %.2lf", final(c2));
	}
	printf("\nNumero de Elementos en la cola 2: %d\n\n", size(c2));


    // MODIFICACIONES ACTIVIDAD 2
    // Insertando elementos en la cola 3
    c3 = encolar(c3, 7.8);
    c3 = encolar(c3, 0.5);
    c3 = encolar(c3, 7.3);
    c3 = encolar(c3, 4.6);
    c3 = encolar(c3, -2.1);
    c3 = encolar(c3, 4.3);
    c3 = encolar(c3, -5.8);
    c3 = encolar(c3, 12.7);
    c3 = encolar(c3, 0.2);
    c3 = encolar(c3, -17.6);
    c3 = encolar(c3, -4.8);
    c3 = encolar(c3, 11.4);
    c3 = encolar(c3, 13.2);
    c3 = encolar(c3, -4.9);
    c3 = encolar(c3, 15.3);
    printf("Elementos en la cola c3 despues de insertar: \n");
    desplegar(c3);
    if(frente(c3) != DBL_MIN){
		printf("\nElemento en el frente (cola 3): %.2lf", frente(c3));
	}
    if(final(c3) != DBL_MIN){
		printf("\nElemento en el final (cola 3): %.2lf", final(c3));
	}
	printf("\nNumero de Elementos en la cola 3: %d\n\n", size(c3));
    // MODIFICACIONES ACTIVIDAD 2
    // Borrando elementos
    c3 = desencolar(c3);
    c3 = desencolar(c3);
    c3 = desencolar(c3);
    c3 = desencolar(c3);
    c3 = desencolar(c3);
    printf("Elementos en la cola c3 despues de borrar: \n");
    desplegar(c3);
    if(frente(c3) != DBL_MIN){
		printf("\nElemento en el frente (cola 3): %.2lf", frente(c3));
	}
    if(final(c3) != DBL_MIN){
		printf("\nElemento en el final (cola 3): %.2lf", final(c3));
	}
	printf("\nNumero de Elementos en la cola 3: %d\n\n", size(c3));

    // MODIFICACION - ACTIVIDAD 3
    // Sumando los elementos de la cola 1
    printf("La suma de los elementos en la Cola 1: %.2lf", suma(c1));
    printf("\nLa suma de los elementos en la Cola 2: %.2lf", suma(c2));
    printf("\nLa suma de los elementos en la Cola 3: %.2lf\n\n", suma(c3));

    // MODIFICACION ACTIVIDAD 4
    // Verificando la cola 1
    printf("El promedio de elementos en la cola 1 es: %.2lf", promedio(c1));
    printf("\nEl elemento maximo en la cola 1 es: %.2lf", maximo(c1));
    printf("\nEl elemento minimo en la cola 1 es: %.2lf\n\n", minimo(c1));
    // Verificando la cola 2
    printf("El promedio de elementos en la cola 2 es: %.2lf", promedio(c2));
    printf("\nEl elemento maximo en la cola 2 es: %.2lf", maximo(c2));
    printf("\nEl elemento minimo en la cola 2 es: %.2lf\n\n", minimo(c2));
    // Verificando la cola 3
    printf("El promedio de elementos en la cola 3 es: %.2lf", promedio(c3));
    printf("\nEl elemento maximo en la cola 3 es: %.2lf", maximo(c3));
    printf("\nEl elemento minimo en la cola 3 es: %.2lf\n\n", minimo(c3));

    return 0;
}


