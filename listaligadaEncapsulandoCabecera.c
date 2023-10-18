#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo * siguiente;
};

struct listaLigada{
    struct nodo * cabecera;
};

struct nodo * crearNodo(int);
struct listaLigada * crearLista();
void desplegar(struct listaLigada *);
void insertar_inicio(struct listaLigada *, int);
void insertar_final(struct listaLigada *, int);
void insertar_intermedio(struct listaLigada *, int, int);
void borrar_inicio(struct listaLigada *);
void borrar_final(struct listaLigada *);
void borrar_intermedio(struct listaLigada *, int);
int contar_nodos(struct listaLigada * cabecera);

int main(){

	// Desplegando nodos en la lista
	struct listaLigada * l1 = crearLista(); // l1 es una instancia de Lista Ligada
	// Probando las funciones implementadas
	printf("\nOperaciones de insercion: \n\n");
	// Insertando nodos al principio
	insertar_inicio(l1, 23);
	insertar_inicio(l1, 12);
	insertar_inicio(l1, 76);
	insertar_inicio(l1, 93);
	insertar_inicio(l1, 8);
	desplegar(l1);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos al final
	insertar_final(l1, 9);
	insertar_final(l1, 7);
	insertar_final(l1, -5);
	insertar_final(l1, 16);
	desplegar(l1);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos en una posicion intermedia
	insertar_intermedio(l1, 0, 14);
	insertar_intermedio(l1, 5, 25);
	insertar_intermedio(l1, 2, 17);
	desplegar(l1);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	
	/*printf("\n\nOperaciones de borrado: \n\n");
	// Borrando nodos al principio
	cabecera = borrar_inicio(cabecera);
	cabecera = borrar_inicio(cabecera);
	cabecera = borrar_inicio(cabecera);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Borrando nodos al final
	cabecera = borrar_final(cabecera);
	cabecera = borrar_final(cabecera);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Borrando nodos en una posicion intermedia
	cabecera = borrar_intermedio(cabecera, 1);
	cabecera = borrar_intermedio(cabecera, 4);
	cabecera = borrar_intermedio(cabecera, 0);
	desplegar(cabecera);*/
	
	return 0;
}

struct nodo * crearNodo(int x){
	struct nodo * nuevo = NULL;
	nuevo = (struct nodo *) malloc(sizeof(struct nodo));
	if(nuevo == NULL) exit(0);
	nuevo->dato = x;
	nuevo->siguiente = NULL;
	return nuevo;
}

struct listaLigada * crearLista(){
    struct listaLigada * nuevaLista = NULL;
    nuevaLista = (struct listaLigada *) malloc(sizeof(struct listaLigada));
    if(nuevaLista == NULL) return NULL;
    nuevaLista->cabecera = NULL;
    return nuevaLista;
}

void insertar_inicio(struct listaLigada * lista, int x){
	struct nodo * n = crearNodo(x);
	if(lista->cabecera == NULL){
		lista->cabecera = n;
	} else{
		n->siguiente = lista->cabecera;
		lista->cabecera = n;
	}
}

void insertar_final(struct listaLigada * lista, int x){
	struct nodo * n = crearNodo(x);
	if(lista->cabecera == NULL){
		lista->cabecera = n;
	} else{
		struct nodo * temp = lista->cabecera;
		while(temp->siguiente != NULL){
			temp = temp->siguiente;
		}
		temp->siguiente = n;
	}
}

void borrar_inicio(struct listaLigada * lista){
	if(lista->cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		struct nodo * aux = lista->cabecera;
		lista->cabecera = lista->cabecera->siguiente;
		free(aux);
	}
}

void borrar_final(struct listaLigada * lista){
	struct nodo * temp = NULL, * prev = NULL;
	if(lista->cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		temp = lista->cabecera;
		while(temp->siguiente != NULL){
			prev = temp;
			temp = temp->siguiente;
		}
		if(temp == lista->cabecera){
			// Si solo queda un nodo en la lista
			lista->cabecera = NULL;
		} else{
			prev->siguiente = NULL;
		}
		free(temp);
	}
}

int contar_nodos(struct listaLigada * lista){
	if(lista->cabecera == NULL){
		return 0;
	} else{
		int cont = 0;
		struct nodo * temp = lista->cabecera;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void insertar_intermedio(struct listaLigada * lista, int pos, int x){
    struct nodo * nuevo = crearNodo(x);
    // Se toma el 0 como posicion valida
    int noNodos = contar_nodos(lista);
    if(pos<-1 || pos>noNodos+1){
        printf("Posicion invalida\n");
    } else if(lista->cabecera == NULL) {
        lista->cabecera = nuevo;
    } else if(pos == 0){
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
    } else{
        struct nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){ // <-- Linea corregida
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void borrar_intermedio(struct listaLigada * lista, int pos){
    if(lista->cabecera == NULL) {
        printf("Lista Vacia!!\n");
    } else {
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos(lista);
        if(pos<-1 || pos>noNodos){
            printf("Posicion invalida\n");
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
                temp = lista->cabecera;
                lista->cabecera = lista->cabecera->siguiente;
                free(temp);
            } else{
                int i=0;
                temp = lista->cabecera;
                while(i<pos-1){ // <-- Linea corregida
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                struct nodo * borrado = temp->siguiente; // (pos)-th nodo
                temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                free(borrado);
            }
        }
    }
}

void desplegar(struct listaLigada * lista){
	struct nodo * temp = lista->cabecera;
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
