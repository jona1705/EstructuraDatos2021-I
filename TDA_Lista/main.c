#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	
	Lista l1 = inicializar();
	desplegar(l1);
	
	l1 = insertar(l1, 4.5);
	l1 = insertar(l1, 7.8);
	l1 = insertar(l1, -5.3);
	desplegar(l1);
	
	l1 = insertar_en(l1, 1, 234.7);
	desplegar(l1);
	
	
	return 0;
}
