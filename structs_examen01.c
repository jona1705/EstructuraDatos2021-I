#include <stdio.h>
#include <stdlib.h>

/* 
	Clase: 18/09/2023
	Declaracion de Estructuras
*/

struct prueba{
	int a;
	int b;
	char c;
	char d;
};

int main(){
	struct prueba q1;
	struct prueba  * q2;
	struct prueba  * q3 = NULL;
	q1.a = 6;
	q1.b = 8;
	q1.c = 'i';
	q1.d = 'u';
	printf("q1.a=%d", q1.a);
	printf("\nq1.b=%d", q1.b);
	printf("\nq1.c=%c", q1.c);
	printf("\nq1.d=%c", q1.d);
	
	// Un apuntador a struct puede acceder a
	// un bloque existente en memoria
	q2 = &q1;
	q2->a = 7;
	q2->b = 17;
	q2->c = 't';
	q2->d = 'y';
	printf("\n\nq2->a=%d", q2->a);
	printf("\nq2->b=%d", q2->b);
	printf("\nq2->c=%c", q2->c);
	printf("\nq2->d=%c", q2->d);
	// Cuando q2 accede al bloque de q1
	// tambien modifica el contenido de q1
	printf("\n\nq1.a=%d", q1.a);
	printf("\nq1.b=%d", q1.b);
	printf("\nq1.c=%c", q1.c);
	printf("\nq1.d=%c", q1.d);
	
	// Un apuntador a struct puede acceder a un bloque
	// Creado con memoria dinamica
	q3 = (struct prueba *) malloc(sizeof(struct prueba));
	if(q3 == NULL) exit(0);
	q3->a = 8;
	q3->b = 15;
	q3->c = 'u';
	q3->d = 'w';
	printf("\n\nq3->a=%d", q3->a);
	printf("\nq3->b=%d", q3->b);
	printf("\nq3->c=%c", q3->c);
	printf("\nq3->d=%c", q3->d);
	free(q3);
}
