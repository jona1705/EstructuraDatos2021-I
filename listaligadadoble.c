#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct nodo{
	int dato;
	struct nodo * siguiente;
    struct nodo * anterior;
};

struct listaLigada{
    struct nodo * cabecera;
};

struct nodo * crearNodo(int);
struct listaLigada * crearLista();
void desplegarAdelante(struct listaLigada *);
void desplegarAtras(struct listaLigada *);
void insertar_inicio(struct listaLigada *, int);
void insertar_final(struct listaLigada *, int);
void insertar_intermedio(struct listaLigada *, int, int);
void borrar_inicio(struct listaLigada *);
void borrar_final(struct listaLigada *);
void borrar_intermedio(struct listaLigada *, int);
int contar_nodos(struct listaLigada *);
int frente(struct listaLigada *);
int final(struct listaLigada *);

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
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos al final
	insertar_final(l1, 9);
	insertar_final(l1, 7);
	insertar_final(l1, -5);
	insertar_final(l1, 16);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos en una posicion intermedia
	insertar_intermedio(l1, 0, 14);
	insertar_intermedio(l1, 5, 25);
	insertar_intermedio(l1, 2, 17);
    insertar_intermedio(l1, 12, 39);
    desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	
	printf("\n\nOperaciones de borrado: \n\n");
	// Borrando nodos al principio
	borrar_inicio(l1);
	borrar_inicio(l1);
	borrar_inicio(l1);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Borrando nodos al final
	borrar_final(l1);
	borrar_final(l1);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Borrando nodos en una posicion intermedia
	borrar_intermedio(l1, 1);
	borrar_intermedio(l1, 4);
	borrar_intermedio(l1, 0);
    borrar_intermedio(l1, 4);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Nodo al frente de la lista: %d\n", frente(l1));
    }
    if(final(l1) != INT_MIN){
        printf("Nodo al final de la lista: %d\n", final(l1));
    }
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	
	return 0;
}

struct nodo * crearNodo(int x){
	struct nodo * nuevo = NULL;
	nuevo = (struct nodo *) malloc(sizeof(struct nodo));
	if(nuevo == NULL) exit(0);
	nuevo->dato = x;
	nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
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
	struct nodo * nuevo = crearNodo(x);
	if(lista->cabecera == NULL){
        // Si la lista esta vacia apenas
        // insertamos el primer nodo
		lista->cabecera = nuevo;
	} else{
        // Si ya hay mas nodos en la lista
        // entonces el nuevo nodo será el primero
		nuevo->siguiente = lista->cabecera;
        lista->cabecera->anterior = nuevo;
		lista->cabecera = nuevo;
	}
}

void insertar_final(struct listaLigada * lista, int x){
	struct nodo * nuevo = crearNodo(x);
	if(lista->cabecera == NULL){
        // Si la lista esta vacia apenas
        // insertamos el primer nodo
		lista->cabecera = nuevo;
	} else{
        // Si ya hay mas nodos en la lista
		struct nodo * temp = lista->cabecera;
		while(temp->siguiente != NULL){
            // Recorremos la lista hasta llegar
            // al ultimo nodo
			temp = temp->siguiente;
		}
        // La parte siguiente del nodo que actualmente
        // es el último apunta al nuevo nodo
		temp->siguiente = nuevo;
        // La parte anterior del nuevo nodo apunta al nodo
        // que era el ultimo
        nuevo->anterior = temp;
	}
}

void insertar_intermedio(struct listaLigada * lista, int pos, int x){
    struct nodo * nuevo = crearNodo(x);
    // Se toma el 0 como posicion valida
    int noNodos = contar_nodos(lista);
    if(pos<0 || pos>noNodos){
        // Rango valido: [0, pos]
        printf("Posicion invalida\n");
    } else if(pos == 0){
        if(lista->cabecera == NULL){
            lista->cabecera = nuevo;
        } else{
            nuevo->siguiente = lista->cabecera;
            lista->cabecera->anterior = nuevo;
            lista->cabecera = nuevo;
        }    
    } else{
        struct nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){ // <-- Linea corregida
            // Recorremos la lista hasta la posicion
            // anterior a la cual vamos a insertar el nodo
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        if(temp->siguiente == NULL){
            // El nuevo nodo se inserta al final
            temp->siguiente = nuevo;
            nuevo->anterior = temp;
        } else{
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
            nuevo->anterior = temp;
            nuevo->siguiente->anterior = nuevo;
        }    
    }
}

void borrar_inicio(struct listaLigada * lista){
	if(lista->cabecera == NULL){
        // No borramos nada si la lista
        // esta vacia
		printf("\nLista Vacia");
	} else{
        // Si la lista no esta vacia ahora
        // el segundo nodo de la lista pasa a ser 
        // el primero y borramos el nodo anterior
		struct nodo * aux = lista->cabecera;
		lista->cabecera = lista->cabecera->siguiente;
        lista->cabecera->anterior = NULL;
		free(aux);
	}
}

void borrar_final(struct listaLigada * lista){
	struct nodo * temp = NULL, * prev = NULL;
	if(lista->cabecera == NULL){
        // No borramos nada si la lista
        // esta vacia
		printf("\nLista Vacia");
	} else{
		temp = lista->cabecera;
		while(temp->siguiente != NULL){
            // Recorremos la lista hasta llegar al 
            // ultimo nodo (temp) y tambien almacenamos
            // el penultimo nodo (prev)
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

void borrar_intermedio(struct listaLigada * lista, int pos){
    if(lista->cabecera == NULL) {
        // La lista esta vacia no borramos nada
        printf("Lista Vacia!!\n");
    } else {
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos(lista);
        if(pos<0 || pos>noNodos-1){
            // Rango valido: [0, pos-1]
            printf("Posicion invalida\n");
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
                temp = lista->cabecera;
                if(temp->siguiente == NULL){
                    // Solo queda un nodo en la lista
                    lista->cabecera = NULL;
                } else{
                    // Hay mas nodos en la lista
                    lista->cabecera = lista->cabecera->siguiente;
                    lista->cabecera->anterior = NULL;
                }
                free(temp);
            } else{
                int i=0;
                temp = lista->cabecera;
                while(i<pos-1){ // <-- Linea corregida
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                struct nodo * borrado = temp->siguiente; // (pos)-th nodo
                if(borrado->siguiente == NULL){
                    borrado->anterior->siguiente = NULL;
                } else{    
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                    borrado->siguiente->anterior = temp;
                }
                free(borrado);
            }
        }
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

void desplegarAdelante(struct listaLigada * lista){
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

void desplegarAtras(struct listaLigada * lista){
	struct nodo * temp = lista->cabecera;
	if(temp == NULL){
		printf("Lista Vacia");
	} else{
        while(temp->siguiente != NULL){
            // Nos desplazamos hasta el último nodo
            temp = temp->siguiente;
        }

		while(temp != NULL){
			printf("%d->",temp->dato);
			temp = temp->anterior;
		}
		printf("NULL\n");
	}
}

int frente(struct listaLigada * lista){
    if(lista->cabecera == NULL){
        return INT_MIN;
    } else{
        return lista->cabecera->dato;
    }
}

int final(struct listaLigada * lista){
    if(lista->cabecera == NULL){
        return INT_MIN;
    } else{
        // Recorremos la lista hasta el ultimo
        // nodo
        struct nodo * temp = lista->cabecera;
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        return temp->dato;
    }
}
