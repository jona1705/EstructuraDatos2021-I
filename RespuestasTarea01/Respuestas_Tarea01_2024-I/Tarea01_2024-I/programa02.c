#include <stdio.h>

char * newstrcpy(char * destino, const char * fuente){
	while(*fuente != '\0'){
		*destino = *fuente;
		destino++;
		fuente++;
	}
	return destino;
}

int newstrlen(char * s){
	int cont = 0;
	while(*s != '\0'){
		cont++;
		s++;
	}
	return cont;
}

int newstrcmp(const char * s1, const char * s2){
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1 > *s2) return 1;
		else if(*s1 < *s2) return -1;
		s1++;
		s2++;
	}
	return 0;
}

char * alternate(char * input){
	int cont = 0;
	char * base = input;
	while(*input != '\0'){
		// Convertimos a mayuscula usando la codificacion ASCII
		if((cont%2 == 0) && (*input>='a' && *input<='z')){
			*input -= 32;
		} else if((cont%2 != 0) && (*input>='A' && *input<='Z')){
			*input += 32;
		}
		input++;
		cont++;
	}
	return base;
}

int main(){
	char cadena1[20] = "FES Acatlan";
	char cadena2[20];
	// Copiando cadenas
	newstrcpy(cadena2, cadena1);
	printf("%s", cadena2);
	// Imprimiendo el numero de caracteres de una cadena
	printf("\nlen(cadena1) = %d", newstrlen(cadena1));
	// Comparando 2 cadenas
	int comparacion = newstrcmp("Hola", "HOla");
	if(comparacion == 0){
		printf("\nSon iguales");
	} else if(comparacion == 1){
		printf("\nCadena 1 mayor que la 2");
	} else{
		printf("\nCadena 2 mayor que la 1");
	}
	// Alternando caracteres
	char * nuevaCadena = alternate(cadena1);
	printf("\nNueva Cadena = %s", nuevaCadena);
	
	return 0;
}
