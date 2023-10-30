#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

    /*
        memcpy: Copia n caracteres de la cadena fuente a la cadena destino
    */
    char origen[] = "Hola, mundo";
    char destino[20];

    /*
        strlen(origen) + 1
        sizeof(origen)
    */

    memcpy(destino, origen, strlen(origen) + 1);
    printf("Origen: %s\n", origen);
    printf("Destino: %s\n", destino);

    /* 
        strcpy() vs memcpy():

        strcpy (String copy):
        - strcpy se utiliza para copiar cadenas terminadas en nulo de 
        un arreglo de caracteres a otro.
        - Está diseñada específicamente para trabajar con cadenas.
        - Deja de copiar cuando encuentra un caracter nulo ('\0'), que 
        marca el final de la cadena.
        - Se usa comúnmente para copiar cadenas de estilo C 
        (arreglo de caracteres) y es parte de la librería estándar de C.
        NOTA: Debemos tener cuidado al utilizar strcpy, ya que no 
        comprueba si hay desbordamiento de búfer y puede provocar 
        vulnerabilidades de seguridad si se utiliza incorrectamente.

        memcpy (Memory copy):
        - memcpy es una función de propósito más general que se utiliza para 
        copiar un bloque de memoria de una ubicación a otra.
        - No depende de que los datos tengan terminación nula o incluso de 
        que sean texto.
        - Se necesita un apuntador/puntero de origen, un apuntador/puntero de 
        destino y la cantidad de bytes para copiar.
        - No le importa el contenido de los datos; simplemente copia un 
        número específico de bytes.
    */

    /* 
        memcpy se puede usar para copiar otras estructuras
    */
    int arreglo_origen[] = {1, 2, 3, 4, 5};
    int arreglo_destino[5];

    memcpy(arreglo_destino, arreglo_origen, sizeof(arreglo_origen));
    printf("\nImprimiendo arreglo: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arreglo_destino[i]);
    }
    printf("\n");

    struct Persona {
        char nombre[20];
        int edad;
    };

    printf("\nImprimiendo estructura: \n");
    struct Persona persona1 = {"Alicia", 30};
    struct Persona persona2;

    memcpy(&persona2, &persona1, sizeof(struct Persona));

    printf("Persona Copiada:\nNombre: %s, Edad: %d\n", persona2.nombre, persona2.edad);

    /* ¿Qué sucede cuando necesitamos asignar memoria para una cadena ?*/
    char * str03 = "FES Acatlán"; // Cadena de solo lectura
    // char str[] = "FES Acatlán"; // Si se puede modificar

    size_t len = strlen(str03) + 1;
    char * nueva_cadena = (char *) malloc(len);
    if(nueva_cadena == NULL) exit(0);
    strcpy(nueva_cadena, str03);
    printf("\nLa nueva cadena es: %s\n", nueva_cadena);
    free(nueva_cadena);

    /*
    
    strdup no es una función de librería C estándar, pero es una función 
    comúnmente utilizada en muchos entornos de programación C. Se utiliza 
    para duplicar una cadena, creando una nueva copia de una cadena 
    terminada en nulo. La función strdup asigna dinámicamente memoria 
    para la nueva cadena usando malloc, copia el contenido de la cadena 
    original en la memoria recién asignada y retorna un apuntador/puntero 
    a la nueva cadena.
    */

    char * cad_duplicada = strdup(str03);
    printf("\nLa cadena duplicada es: %s\n", cad_duplicada);
    free(cad_duplicada);


    return 0;
}

