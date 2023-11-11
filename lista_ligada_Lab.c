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

// Funcion que retorna el nodo cabecera actualizado
struct nodo * insertar_inicio(struct nodo * cabecera, int dato){
	struct nodo * nuevo = crearNodo(dato);
	if(cabecera == NULL){
		cabecera = nuevo;
	} else{
		nuevo->siguiente = cabecera;
		cabecera = nuevo;
	}
	return cabecera;
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
	// Retornando el contenido del nodo cabecera
	cabecera = insertar_inicio(cabecera, 5);
	cabecera = insertar_inicio(cabecera, 6);
	cabecera = insertar_inicio(cabecera, 8);
	desplegar(cabecera);
	
	return 0;
}
