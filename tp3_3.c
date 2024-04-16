#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PALABRAS 5
void mostrarPalabras(char **nombres);
void cargarPalabras(char **nombres);
void liberarMemoria(char **nombres);
int main()
{
    char **nombres = malloc(PALABRAS * sizeof(char *));
    cargarPalabras(nombres);
    mostrarPalabras(nombres);
    liberarMemoria(nombres);
    return 0;

}

void cargarPalabras(char **nombres)
{
    char *buff = malloc(100 * sizeof(char));
    for(int i = 0; i < PALABRAS; i++){
        printf("ingrese la palabra:");
        gets(buff);
        nombres[i] = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombres[i],buff);
    }
    free(buff);
}
void mostrarPalabras(char **nombres)
{
    for(int i = 0; i < 5; i++){
        puts(nombres[i]);
    }
}
void liberarMemoria(char **nombres)
{
    for(int i = 0; i < PALABRAS; i++){
        free(nombres[i]);
    }
    free(nombres);
}