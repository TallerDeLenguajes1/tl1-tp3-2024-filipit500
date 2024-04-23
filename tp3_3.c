#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PALABRAS 5

int main()
{
    char **nombres = (char **)malloc(PALABRAS * sizeof(char *));
    char buff[50];
    for(int i = 0; i < PALABRAS; i++){
        printf("ingrese un nombre:");
        fflush(stdin);
        scanf("%s",buff);
        nombres[i] = (char *)malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(nombres[i],buff);
    }
    for(int i = 0; i < PALABRAS; i++){
        printf("nombre: ");
        puts(nombres[i]);
    }
    
    for(int i = 0; i < PALABRAS; i++){
        free(nombres[i]);
    }
    free(nombres);
    return 0;
    
}