#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo * siguiente;
};

struct nodo * crearNodo(int);
void desplegar(struct nodo *);
struct nodo * insertar_inicio(struct nodo *, int);
struct nodo * insertar_final(struct nodo *, int);
struct nodo * insertar_intermedio(struct nodo *, int, int);
struct nodo * borrar_inicio(struct nodo *);
struct nodo * borrar_final(struct nodo *);
struct nodo * borrar_intermedio(struct nodo *, int);
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
	// n1->n2->n3->NULL
	
	// Desplegando nodos en la lista
	struct nodo * cabecera = n1;
	desplegar(cabecera);
	// Probando las funciones implementadas
	printf("\nOperaciones de insercion: \n\n");
	// Insertando nodos al principio
	cabecera = insertar_inicio(cabecera, 23);
	cabecera = insertar_inicio(cabecera, 12);
	cabecera = insertar_inicio(cabecera, 76);
	cabecera = insertar_inicio(cabecera, 93);
	cabecera = insertar_inicio(cabecera, 8);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Insertando nodos al final
	cabecera = insertar_final(cabecera, 9);
	cabecera = insertar_final(cabecera, 7);
	cabecera = insertar_final(cabecera, -5);
	cabecera = insertar_final(cabecera, 16);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	// Insertando nodos en una posicion intermedia
	cabecera = insertar_intermedio(cabecera, 0, 14);
	cabecera = insertar_intermedio(cabecera, 5, 25);
	cabecera = insertar_intermedio(cabecera, 2, 17);
	desplegar(cabecera);
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(cabecera));
	
	printf("\n\nOperaciones de borrado: \n\n");
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

struct nodo * insertar_inicio(struct nodo * cabecera, int x){
	struct nodo * nuevo = crearNodo(x);
	if(cabecera == NULL){
		cabecera = nuevo;
		// q = p; --> &q != &p
	} else{
		nuevo->siguiente = cabecera;
		cabecera = nuevo;
	}
	return cabecera;
}

struct nodo * insertar_final(struct nodo * cabecera, int x){
	struct nodo * nuevo = crearNodo(x);
	if(cabecera == NULL){
		cabecera = nuevo;
	} else{
		struct nodo * temp = cabecera;
		while(temp->siguiente != NULL){
			temp = temp->siguiente;
		}
		temp->siguiente = nuevo;
	}
	return cabecera;
}

struct nodo * insertar_intermedio(struct nodo * cabecera, int pos, int x){
    struct nodo * nuevo = crearNodo(x);
    // Se toma el 0 como posicion valida
    int noNodos = contar_nodos(cabecera);
    if(pos<0 || pos>noNodos){
    	// Rango: [0, pos]
        printf("Posicion invalida\n");
        return;
    } else if(pos == 0){
    	// Insertamos un nodo en la primer posicion
    	if(cabecera == NULL) {
    		// Si la lista esta vacia
    		// es primer nodo en la lista
        	cabecera = nuevo;
    	} else{
    		// Si hay mas nodos el nuevo nodo pasa
    		// a ser el primero
    		nuevo->siguiente = cabecera;
        	cabecera = nuevo;
		}    
    } else{
        struct nodo * temp = cabecera;
        int i=0;
        while(i<pos-1){ // <-- Linea corregida
        	// Recorremos la lista hasta el (pos-1)-th nodo
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        if(temp->siguiente == NULL){
        	// Si el (pos-1)-th nodo es el ultimo
        	// El nuevo nodo sera el ultimo
        	temp->siguiente = nuevo;
		} else{
			// El nodo se inserta en una posicion intermedia
			nuevo->siguiente = temp->siguiente;
        	temp->siguiente = nuevo;
		}    
    }
    
    return cabecera;
}

struct nodo * borrar_inicio(struct nodo * cabecera){
	if(cabecera == NULL){
		printf("\nLista Vacia");
	} else{
		struct nodo * aux = cabecera;
		cabecera = cabecera->siguiente;
		free(aux);
	}
	return cabecera;
}

struct nodo * borrar_final(struct nodo * cabecera){
	struct nodo * temp = NULL, * prev = NULL;
	if(cabecera == NULL){
		printf("\nLista Vacia");
		return;
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

struct nodo * borrar_intermedio(struct nodo * cabecera, int pos){
    if(cabecera == NULL) {
        printf("Lista Vacia!!\n");
        return;
    } else {
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos(cabecera);
        if(pos<0 || pos>noNodos-1){
        	// Rango: [0, pos-1]
            printf("Posicion invalida\n");
            return;
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
            	// Borramos el primer nodo en la lista
                temp = cabecera;
                if(temp->siguiente == NULL){
                	// Si solo queda un nodo en la lista
                	cabecera = NULL;
				} else{
					// Si hay mas nodos el nodo cabecera
					// ser� el segundo
					cabecera = cabecera->siguiente;
				}
                free(temp);
            } else{
                int i=0;
                temp = cabecera;
                while(i<pos-1){ // <-- Linea corregida
                	// Recorremos la lista hasta el (pos-1)-th nodo
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                struct nodo * borrado = temp->siguiente; // (pos)-th nodo
                if(borrado->siguiente == NULL){
                	// Si borramos el ultimo nodo
                	// el nodo previo sera el ultimo
                	temp->siguiente = NULL; // El nodo (pos-1)-th en su parte sig apunta a NULL 
				} else{
					// El nodo previo pasa a apuntar al nodo
					// que sigue al nodo a ser borrado
					temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
				}
                free(borrado);
            }
        }
    }
    
    return cabecera;
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
