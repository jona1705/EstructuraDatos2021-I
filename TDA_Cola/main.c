#include <stdio.h>
#include <float.h>
#include "cola.h"

int main(){
    // Inicializando instancias de Cola
	Cola c1 = init();
    Cola c2 = init();

    // Insertando elementos en la cola 1
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
    // Borrando elementos en la cola 1
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
    // Borrando elementos en la cola 2
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

    return 0;
}


