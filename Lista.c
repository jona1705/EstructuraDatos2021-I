#include <stdio.h>
#define MAX 100

/* 
	Clase: 08/09/2023
	Programa para gestionar una lista
	de elementos
*/

// Esta funcion inserta un elemento 
// al final de la Lista
int insertar(double arr[], int len, double x){
	if(len < MAX){
		arr[len++] = x;
	} else{
		printf("\n[] Lista Llena ...");
	}
	// Retornamos la cantidad de valores 
	// en el arreglo
	return len;
}

// Esta funcion inserta un elemento 
// en una posicion especifica de la Lista
int insertar_en(double arr[], int len, int pos, double x){
	if((pos>len) || (pos>MAX) || (pos<0)){
		printf("\n[ERROR] Indice fuera de rango ...\n");
	} else if(len == MAX){
		printf("\n[] Lista Vacia ...");
	} else{
		int i;
		for(i=len; i>=pos; i--){
			arr[i+1] = arr[i];
		}
		arr[pos] = x;
		len++;
	}
	
	return len;
}

// Esta funcion borra un elemento 
// al final de la Lista
int borrar(double arr[], int len){
	if(len == 0){
		printf("[] Lista Vacia ...\n");
	} else{
		len--;
	}
	return len;
}

// Esta funcion borra un elemento 
// en una posicion especifica de la Lista
int borrar_en(double arr[], int len, int pos){
	if((pos>len) || (pos>MAX) || (pos<0)){
		printf("[ERROR] Indice fuera de rango ...\n");
	} else if(len==0){
		printf("[] Lista Vacia ...\n");
	} else{
		int i;
		for(i=pos; i<len; i++){
			arr[i] = arr[i+1];
		}
		len--;
	}
	return len;
}

// Funcion que busca un valor
// usando el algoritmo de busqueda lineal
int buscar(double arr[], int len, double x){
	if(len != 0){
		// Busqueda lineal
		int i;
		for(i=0; i<len; i++){
			if(arr[i] == x) return i;
		}
	}
	return -1;
}

// Funcion auxiliar para intercambiar dos valore
// de la lista
void intercambiar(double * a, double * b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

// Funcion que ordena una lista
// usando el algoritmo de la burbuja
void ordenar(double arr[], int len){
	if(len != 0){
		// Algoritmo de la burbuja
		int paso, iteracion;
		for(paso=0; paso<len-1; paso++){
			for(iteracion=0; iteracion<len-1; iteracion++){
				if(arr[iteracion] > arr[iteracion+1]){
					intercambiar(&arr[iteracion], &arr[iteracion+1]);
				}
			}
		}
	}
}


// Funcion que imprime todos los elementos
// de la lista
void desplegar(double arr[], int len){
	if(len == 0){
		printf("\n[] Lista Vacia ...");
	} else{
		int i;
		for(i=0; i<len; i++){
			printf("%.2lf ", arr[i]);
		}	
	}
	printf("\n");
}

int main(){
	double lista[MAX];
    int tamLista = 0;
    // Insertando valores
	tamLista = insertar(lista, tamLista, 2.5);
	tamLista = insertar(lista, tamLista, 4.2);
	tamLista = insertar(lista, tamLista, -7.9);
	tamLista = insertar(lista, tamLista, 14.2);
	tamLista = insertar(lista, tamLista, 6.5);
	desplegar(lista, tamLista);
	// Insertar valores por posicion
	tamLista = insertar_en(lista, tamLista, 0, 12.5);
	tamLista = insertar_en(lista, tamLista, 3, 7.3);
	/*
		Usar esta linea para probar un indice fuera de
		rango
	tamLista = insertar_en(lista, tamLista, 10, 8.2);
	*/
	desplegar(lista, tamLista);
	
	// Borrar elementos al final
	tamLista = borrar(lista, tamLista);
	tamLista = borrar(lista, tamLista);
	desplegar(lista, tamLista);
	// Borrar valores por posicion
	tamLista = borrar_en(lista, tamLista, 0);
	tamLista = borrar_en(lista, tamLista, 2);
	/*
		Usar esta linea para probar un indice fuera de
		rango
	tamLista = borrar_en(lista, tamLista, 10);
	*/
	desplegar(lista, tamLista);
	
	// Buscando un elemento
	if(buscar(lista, tamLista, 8.9) != -1){
		printf("\nElemento se encuentra en la lista\n");
	} else{
		printf("\nElemento no se encuentra en la lista\n");
	}
	
	// Ordenando la lista
	printf("\n\nLista Ordenada: \n");
	ordenar(lista, tamLista);
	desplegar(lista, tamLista);
	
	return 0;
}
