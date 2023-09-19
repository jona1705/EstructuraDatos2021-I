#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
	Clase: 18/09/2023
	Estructuras Anidadas
*/


/* 
	Una estructura anidada es una estructura dentro de
	otra estructura
*/
struct testing{
	double a;
	char arr[50];
};

/* 
	Una estructura se puede declarar dentro de otra estructura 
	de la misma manera que se declaran los miembros de una 
	estructura dentro de una estructura.
*/
struct prueba{
	int a;
	int b;
	char c;
	char d;
	struct testing e;
};

int main(){
	struct prueba q;
	printf("sizeof(q)=%lu", sizeof(q));
	printf("\nDesglosando los elementos de q: ");
	printf("\nsizeof(q.a)=%lu", sizeof(q.a));
	printf("\nsizeof(q.b)=%lu", sizeof(q.b));
	printf("\nsizeof(q.c)=%lu", sizeof(q.c));
	printf("\nsizeof(q.d)=%lu", sizeof(q.d));
	printf("\nsizeof(q.e)=%lu:", sizeof(q.e));
	printf("\n-- sizeof(q.e.a)=%lu", sizeof(q.e.a));
	printf("\n-- sizeof(q.e.arr)=%lu", sizeof(q.e.arr));
	// Accediendo a los elementos del arreglo interno
	q.e.a = 23.7;
	strcpy(q.e.arr, "Juan");
	printf("\n\nAccediendo a los elementos del arreglo anidado: ");
	printf("%.2lf, %s", q.e.a, q.e.arr);
}
