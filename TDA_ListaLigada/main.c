#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

int main(int argc, char *argv[]) {
	Nodo * n1 = NULL;
	Nodo * n2 = NULL;
	Nodo * n3 = NULL;
	n1 = crearNodo(5);
	n2 = crearNodo(8);
	n3 = crearNodo(7);
	n1->siguiente = n2;
	n2->siguiente = n3;
	n3->siguiente = NULL;
	// Desplegando nodos en la lista
	Nodo * cabecera = n1;
	desplegar(cabecera);
	// Probando las funciones implementadas
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

	return 0;
}
