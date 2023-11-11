#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo * siguiente;	
};

struct listaLigada{
	// Encapsulamos el nodo cabecera
	struct nodo * cabecera;
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

struct listaLigada * crearLista(){
	struct listaLigada * lista = (struct listaLigada *) malloc(sizeof(struct listaLigada));
	if(lista == NULL){
		exit(0);
	}
	lista->cabecera = NULL;
	return lista;
}

void insertar_inicio(struct listaLigada * l1, int dato){
	struct nodo * nuevo = crearNodo(dato);
	if(l1->cabecera == NULL){
		l1->cabecera = nuevo;
	} else{
		nuevo->siguiente = l1->cabecera;
		l1->cabecera = nuevo;
	}
}

void insertar_final(struct listaLigada * l1, int dato){
	struct nodo * nuevo = crearNodo(dato);
	if(l1->cabecera == NULL){
		l1->cabecera = nuevo;
	} else{
		struct nodo * temp = l1->cabecera;
		while(temp->siguiente != NULL){
			temp = temp->siguiente;
		}
		temp->siguiente = nuevo;
	}
}

void borrar_inicio(struct listaLigada * l1){
	if(l1->cabecera == NULL){
		return;
	} else{
		struct nodo * temp = l1->cabecera;
		if(l1->cabecera->siguiente == NULL){
			// Solo queda un nodo en la lista
			l1->cabecera = NULL;
		} else{
			// Hay mas nodos en la lista
			l1->cabecera = l1->cabecera->siguiente;
		}
		free(temp);
	}
}

void borrar_final(struct listaLigada * l1){
	if(l1->cabecera == NULL){
		return;
	} else{
		struct nodo * temp = l1->cabecera;
		struct nodo * prev = NULL;
		while(temp->siguiente != NULL){
			prev = temp;
			temp = temp->siguiente;
		}
		if(temp == l1->cabecera){ // Linea corregida
			// Solo queda un nodo en la lista
			l1->cabecera = NULL;
		} else{
			// Hay mas nodos en la lista
			prev->siguiente = NULL;
		}
		free(temp);
	}
}

void desplegar(struct listaLigada * l1){
	if(l1->cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		struct nodo * temp = l1->cabecera;
		while(temp != NULL){
			printf("%d->", temp->dato);
			temp = temp->siguiente;
		}
		printf("NULL\n");
	}
}

int main(){	
	struct listaLigada * lista = crearLista();
	insertar_inicio(lista, 5);
	insertar_inicio(lista, 6);
	insertar_inicio(lista, 8);
	insertar_inicio(lista, 14);
	desplegar(lista);
	insertar_final(lista, 9);
	insertar_final(lista, 12);
	insertar_final(lista, 7);
	insertar_final(lista, 10);
	desplegar(lista);
	borrar_inicio(lista);
	borrar_inicio(lista);
	desplegar(lista);
	borrar_final(lista);
	borrar_final(lista);
	desplegar(lista);
	
	return 0;
}
