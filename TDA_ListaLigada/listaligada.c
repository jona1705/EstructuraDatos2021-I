#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

Nodo * crearNodo(int x){
	Nodo * nuevo = NULL;
	nuevo = (Nodo *) malloc(sizeof(Nodo));
	if(nuevo == NULL) exit(0);
	nuevo->dato = x;
	nuevo->siguiente = NULL;
	return nuevo;
}

Nodo * insertar_inicio(Nodo * cabecera, int x){
	Nodo * n = crearNodo(x);
	if(cabecera == NULL){
		cabecera = n;
	} else{
		n->siguiente = cabecera;
		cabecera = n;
	}
	return cabecera;
}

Nodo * insertar_final(Nodo * cabecera, int x){
	Nodo * n = crearNodo(x);
	if(cabecera == NULL){
		cabecera = n;
	} else{
		Nodo * temp = cabecera;
		while(temp->siguiente != NULL){
			temp = temp->siguiente;
		}
		temp->siguiente = n;
	}
	return cabecera;
}

Nodo * borrar_inicio(Nodo * cabecera){
	if(cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		Nodo * aux = cabecera;
		cabecera = cabecera->siguiente;
		free(aux);
	}
	return cabecera;
}

Nodo * borrar_final(Nodo * cabecera){
	Nodo * temp = NULL, * prev = NULL;
	if(cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		temp = cabecera;
		while(temp->siguiente != NULL){
			prev = temp;
			temp = temp->siguiente;
		}
		if(temp == cabecera){
			// Si solo queda un nodo en la lista
			cabecera = NULL;
		} else{
			prev->siguiente = NULL;
		}
		free(temp);
	}
	return cabecera;
}

int contar_nodos(Nodo * cabecera){
	if(cabecera == NULL){
		return 0;
	} else{
		int cont = 0;
		Nodo * temp = cabecera;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void desplegar(Nodo * cabecera){
	Nodo * temp = cabecera;
	if(temp == NULL){
		printf("Lista Vacia");
	} else{
		while(temp != NULL){
			printf("%d->",temp->dato);
			temp = temp->siguiente;
		}
		printf("NULL\n");
	}
}
