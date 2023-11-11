#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo * siguiente;	
};

struct nodo * crearNodo(int dato){
	struct nodo * nuevo = (struct nodo *) malloc(sizeof(struct nodo));
	if(nuevo == NULL){
		exit(0);
	}
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	return nuevo;
}

// Funcion que pasa por referencia el nodo cabecera
void insertar_inicio(struct nodo ** cabecera, int dato){
	struct nodo * nuevo = crearNodo(dato);
	if(*cabecera == NULL){
		*cabecera = nuevo;
	} else{
		nuevo->siguiente = *cabecera;
		*cabecera = nuevo;
	}
}

void desplegar(struct nodo * cabecera){
	if(cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		struct nodo * temp = cabecera;
		while(temp != NULL){
			printf("%d->", temp->dato);
			temp = temp->siguiente;
		}
		printf("NULL\n");
	}
}

int main(){
	struct nodo * cabecera = NULL;
	//Pasando el nodo cabecera por referencia
	insertar_inicio(&cabecera, 5);
	insertar_inicio(&cabecera, 6);
	insertar_inicio(&cabecera, 8);
	desplegar(cabecera);
	
	return 0;
}
