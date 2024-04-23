#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadNombres;
    printf("ingrese la cantidad de nombres que desea cargar:");
    fflush(stdin);
    scanf("%d", &cantidadNombres);
    char **nombres = (char **)malloc(cantidadNombres * sizeof(char *));
    char buff[50];
    for(int i = 0; i < cantidadNombres; i++){
        printf("ingrese un nombre:");
        fflush(stdin);
        scanf("%s",buff);
        nombres[i] = (char *)malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(nombres[i],buff);
    }
    for(int i = 0; i < cantidadNombres; i++){
        printf("nombre: ");
        puts(nombres[i]);
    }
    
    for(int i = 0; i < cantidadNombres; i++){
        free(nombres[i]);
    }
    free(nombres);
    return 0;
}