#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo * siguiente;
};

struct nodo * crearNodo(int);
void desplegar(struct nodo *);
void insertar_inicio(struct nodo **, int);
void insertar_final(struct nodo **, int);
void insertar_intermedio(struct nodo **, int, int);
void borrar_inicio(struct nodo **);
void borrar_final(struct nodo **);
void borrar_intermedio(struct nodo **, int);
int contar_nodos(struct nodo * cabecera);

int main(){
	struct nodo * n1 = NULL;
	struct nodo * n2 = NULL;
	struct nodo * n3 = NULL;
	// Tomar memoria
	/*n1 = (struct nodo *) malloc(sizeof(struct nodo));
	if(n1 == NULL) exit(0);
	n2 = (struct nodo *) malloc(sizeof(struct nodo));
	if(n2 == NULL) exit(0);
	n3 = (struct nodo *) malloc(sizeof(struct nodo));
	if(n3 == NULL) exit(0);
	// Accediendo a los elementos del struct
	n1->dato = 5;
	n2->dato = 8;
	n3->dato = 7;
	n1->siguiente = n2;
	n2->siguiente = n3;
	n3->siguiente = NULL;*/
	n1 = crearNodo(5);
	n2 = crearNodo(8);
	n3 = crearNodo(7);
	n1->siguiente = n2;
	n2->siguiente = n3;
	n3->siguiente = NULL;
	// Desplegando nodos en la lista
	struct nodo * cabecera = n1;
	desplegar(cabecera);
	// Probando las funciones implementadas
	printf("\nOperaciones de insercion: \n\n");
	// Insertando nodos al principio
	insertar_inicio(&cabecera, 23);
	insertar_inicio(&cabecera, 12);
	insertar_inicio(&cabecera, 76);
	insertar_inicio(&cabecera, 93);
	insertar_inicio(&cabecera, 8);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Insertando nodos al final
	insertar_final(&cabecera, 9);
	insertar_final(&cabecera, 7);
	insertar_final(&cabecera, -5);
	insertar_final(&cabecera, 16);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Insertando nodos en una posicion intermedia
	insertar_intermedio(&cabecera, 0, 14);
    insertar_intermedio(&cabecera, 5, 25);
	insertar_intermedio(&cabecera, 2, 17);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	
	printf("\n\nOperaciones de borrado: \n\n");
	// Borrando nodos al principio
	borrar_inicio(&cabecera);
	borrar_inicio(&cabecera);
	borrar_inicio(&cabecera);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Borrando nodos al final
	borrar_final(&cabecera);
	borrar_final(&cabecera);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Borrando nodos en una posicion intermedia
	borrar_intermedio(&cabecera, 1);
	borrar_intermedio(&cabecera, 4);
	borrar_intermedio(&cabecera, 0);
	desplegar(cabecera);
    printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	
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

void insertar_inicio(struct nodo ** cabecera, int x){
	struct nodo * n = crearNodo(x);
	if(*cabecera == NULL){
		*cabecera = n;
	} else{
		n->siguiente = *cabecera;
		*cabecera = n;
	}
}

void insertar_final(struct nodo ** cabecera, int x){
	struct nodo * n = crearNodo(x);
	if(*cabecera == NULL){
		*cabecera = n;
	} else{
		struct nodo * temp = *cabecera;
		while(temp->siguiente != NULL){
			temp = temp->siguiente;
		}
		temp->siguiente = n;
	}
}

void borrar_inicio(struct nodo ** cabecera){
	if(*cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		struct nodo * aux = *cabecera;
		*cabecera = (*cabecera)->siguiente;
		free(aux);
	}
}

void borrar_final(struct nodo ** cabecera){
	struct nodo * temp = NULL, * prev = NULL;
	if(*cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		temp = *cabecera;
		while(temp->siguiente != NULL){
			prev = temp;
			temp = temp->siguiente;
		}
		if(temp == *cabecera){
			// Si solo queda un nodo en la lista
			*cabecera = NULL;
		} else{
			prev->siguiente = NULL;
		}
		free(temp);
	}
}

int contar_nodos(struct nodo * cabecera){
	if(cabecera == NULL){
		return 0;
	} else{
		int cont = 0;
		struct nodo * temp = cabecera;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void insertar_intermedio(struct nodo ** cabecera, int pos, int x){
    struct nodo * nuevo = crearNodo(x);
    // Se toma el 0 como posicion valida
    int noNodos = contar_nodos(*cabecera);
    if(pos<-1 || pos>noNodos+1){
        printf("Posicion invalida\n");
    } else if(*cabecera == NULL) {
        *cabecera = nuevo;
    } else if(pos == 0){
        nuevo->siguiente = *cabecera;
        *cabecera = nuevo;
    } else{
        struct nodo * temp = *cabecera;
        int i=0;
        while(i<pos-1){ // <-- Linea corregida
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void borrar_intermedio(struct nodo ** cabecera, int pos){
    if(*cabecera == NULL) {
        printf("Lista Vacia!!\n");
    } else {
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos(*cabecera);
        if(pos<-1 || pos>noNodos){
            printf("Posicion invalida\n");
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
                temp = *cabecera;
                *cabecera = (*cabecera)->siguiente;
                free(temp);
            } else{
                int i=0;
                temp = *cabecera;
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

void desplegar(struct nodo * cabecera){
	struct nodo * temp = cabecera;
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
