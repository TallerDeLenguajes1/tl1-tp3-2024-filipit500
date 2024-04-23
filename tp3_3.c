#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **crearArreglo(int cantidad);
void mostrarNombres(char **nombres,int cantidad);
void liberarMemoria(char **nombres,int cantidad);

int main()
{
    char **nombres;
    int cantidadNombres;
    printf("ingrese la cantidad de nombres que desea cargar:");
    fflush(stdin);
    scanf("%d",&cantidadNombres);
    nombres = crearArreglo(cantidadNombres);
    mostrarNombres(nombres,cantidadNombres);
    liberarMemoria(nombres,cantidadNombres);
    return 0;
}

char **crearArreglo(int cantidad)
{
    char **nombres = (char**)malloc(cantidad*sizeof(char*));
    char buff[50];
    for(int i = 0; i < cantidad; i++){
        printf("ingrese un nombre:");
        fflush(stdin);
        scanf("%s",buff);
        nombres[i] = (char *)malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(nombres[i],buff);
    }
    return nombres;
}

void mostrarNombres(char **nombres,int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        printf("nombre: ");
        puts(nombres[i]);
    }
}

void liberarMemoria(char **nombres,int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        free(nombres[i]);
    }
    free(nombres);
}