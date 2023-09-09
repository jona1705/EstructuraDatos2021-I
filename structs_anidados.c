#include <stdio.h>
#include <string.h>

/* 
	Clase: 08/09/2023
	Estructuras Anidadas
*/

typedef struct padre{
	int x;
	char cadena[50];
} Padre;

typedef struct hijo{
	int y;
	Padre p;
} Hijo;

int main(){
	Padre p1;
	Hijo h1;
	// Usando la variable p1
	p1.x = 5;
	strcpy(p1.cadena, "Hola");
	printf("%d %s", p1.x, p1.cadena);
	// Usando la variable h1
	h1.y = 5;
	h1.p.x = 6;
	strcpy(h1.p.cadena, "Bienvenido");
	printf("\n%d %d %s", h1.y, h1.p.x, h1.p.cadena);
	
	
}
