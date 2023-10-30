#include <stdio.h>
#include <string.h>

/* 
    Este archivo muestra las funciones para manipular cadenas
    más importantes que existen en lenguaje c
*/

int main(){
    // Declarando un arreglo de caracteres
    char saludo[] = "Hola Mundo";
    char cadenaDestino[20];
    /*
        strlen: Esta función se utiliza para calcular la longitud de una cadena. 
        Retorna el número de caracteres en la cadena sin incluir el caracter nulo al final.
    */
    printf("\nNumero de caracteres de la cadena saludo: %lu", strlen(saludo));
    /* 
        strcpy: Se usa para copiar una cadena en otra. Copia los caracteres de 
        una cadena origen en una cadena destino.
    */
   strcpy(cadenaDestino, saludo);
   printf("\n\nContenido en la cadena_destino: %s", cadenaDestino);
   /*
        strcat: Permite concatenar (agregar) una cadena al final de otra. 
        Agrega los caracteres de una cadena al final de otra.
   */
    char cadena1[30] = "Ciudad de";
    char cadena2[30] = " Mexico";
    strcat(cadena1, cadena2); 
    printf("\n\nContenido en la cadena1: %s", cadena1); // Ciudad de Mexico
    /*
        strcmp: Compara dos cadenas y retorna un valor entero que indica si son iguales o 
        cuál es mayor o menor en orden lexicográfico.
        Valor de Retorno            Descripción:
                 0                  Si las cadenas son iguales
                >0                  Cuando el primer caracter que no coincide en la cadena1 
                                    es más grande (de acuerdo al codigo ASCII) que el corres
                                    pondiente caracter en la cadena2
                <0                  Cuando el primer caracter que no coincide en la cadena1 
                                    es más pequeño (de acuerdo al codigo ASCII) que el corres
                                    pondiente caracter en la cadena2
    */
    char str01[] = "Hola Mundo";
    char str02[] = "hola mundo";
    if(strcmp(str01, str02) == 0){
        printf("\n\nLa cadena str01 es igual a str02");
    } else if(strcmp(str01, str02) > 0){
        printf("\n\nLa cadena str01 es \"mayor\" que str02");
    } else{
        printf("\n\nLa cadena str01 es \"menor\" que str02");
    }
    /* 
        strchr: Busca un caracter en una cadena y retorna un apuntador/puntero a la primera 
        ocurrencia de ese caracter.
    */
    char cad01[] = "Buscando palabra en una cadena";
    char caracter = 'p';
    char * resultado = strchr(cad01, caracter);
    if (resultado != NULL) {
        printf("\n\nEl caracter '%c' se encontró en la cadena en la posición %ld.\n", caracter, resultado - cad01);
    } else {
        printf("\n\nEl caracter '%c' no se encontró en la cadena.\n", caracter);
    }
    /*
        strstr: Busca una subcadena en una cadena y retorna un apuntador/puntero a la 
        primera ocurrencia de la subcadena.
    */
    char str[] = "Este es un ejemplo de cadena";
    char sub[] = "ejemplo";
    resultado = strstr(str, sub);
    if (resultado != NULL) {
        printf("\n\nSubcadena encontrada en indice %ld.\n", resultado - str);
    } else {
        printf("\n\nSubcadena no encontrada\n");
    }

    /*
        strtok: Divide una cadena en tokens basados en un delimitador.
    */
    char sentencia[] = "Esta es una simple sentencia";
    char * token = strtok(sentencia, " ");
    while (token != NULL) {
        printf("strtok(): %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}

