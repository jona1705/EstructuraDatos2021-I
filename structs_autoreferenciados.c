#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* 
	Clase: 08/09/2023
	Estructuras Auto-referenciadas
	(Introduccion a las Listas Ligadas)
*/

struct X{
	int id;
	struct X * ptr;
};

// Función para mostrar los nodos de la lista
void desplegar(struct X * cabecera) {
    struct X * actual = cabecera;
    while (actual != NULL) {
        printf("%d -> ", actual->id);
        actual = actual->ptr;
    }
    printf("NULL\n");
}

int main(){
	struct X * n1 = NULL;
	struct X * n2 = NULL;
	struct X * n3 = NULL;
	// Tomar memoria para n1
	n1 = (struct X *) malloc(sizeof(struct X));
	assert(n1);
	n1->id = 4;
	// Tomar memoria para n2
	n2 = (struct X *) malloc(sizeof(struct X));
	assert(n2);
	n2->id = 9; 
	// Tomar memoria para n1
	n3 = (struct X *) malloc(sizeof(struct X));
	assert(n3);
	n3->id = 12;
	
	// Formando la lista Ligada: 
	// El nodo n1 apunta al nodo n2
	n1->ptr = n2; 
	// El nodo n2 apunta al nodo n3
	n2->ptr = n3;
	// El nodo n3 apunta a NULL fin de la lista ligada
	n3->ptr = NULL;
	
	// Desplegando nodos de la lista
	desplegar(n1);
	
	free(n1);
	free(n2);
	free(n3);
}
