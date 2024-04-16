#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

void cargarMatriz(float matriz[][COLUMNAS]);
void mostrarMatriz(float matriz[][COLUMNAS]);
void promedioPorAnio(float matriz[][COLUMNAS]);
void mejorPeorMes(float matriz[][COLUMNAS]);

int main()
{
srand(time(NULL));
float matriz[FILAS][COLUMNAS];
cargarMatriz(matriz);
int opcion = 1;
    while(opcion == 1 || opcion == 2 || opcion == 3){
        printf("1: mostrar anios\n"); 
        printf("2: promedio anual de ganancias\n"); 
        printf("3: mejor mes\n");  
        printf("eliga una opcion:");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: mostrarMatriz(matriz); break;
            case 2: promedioPorAnio(matriz); break;
            case 3: mejorPeorMes(matriz); break;
            case 4: printf("saliendo...\n"); break;
        }
    }
    return 0;
}

void cargarMatriz(float matriz[][COLUMNAS])
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 12; j++){
            matriz[i][j] = rand() % 40001 + 10000; //10000 al 50000//
        }
    }
}

void mostrarMatriz(float matriz[][COLUMNAS])
{
    int anio = 2024;
     for(int i = 0; i < 5; i++){
        printf("******%d******\n",anio);
        for(int j = 0; j < 12; j++){
            switch(j){
                case 0: printf("enero: $%.2f\n",matriz[i][j]); break;
                case 1: printf("febrero: $%.2f\n",matriz[i][j]); break;
                case 2: printf("marzo: $%.2f\n",matriz[i][j]); break;
                case 3: printf("abril: $%.2f\n",matriz[i][j]); break;
                case 4: printf("mayo: $%.2f\n",matriz[i][j]); break;
                case 5: printf("junio: $%.2f\n",matriz[i][j]); break;
                case 6: printf("julio: $%.2f\n",matriz[i][j]); break;
                case 7: printf("agosto: $%.2f\n",matriz[i][j]); break;
                case 8: printf("septiembre: $%.2f\n",matriz[i][j]); break;
                case 9: printf("octubre: $%.2f\n",matriz[i][j]); break;
                case 10: printf("noviembre: $%.2f\n",matriz[i][j]); break;
                case 11: printf("diciembre: $%.2f\n",matriz[i][j]); break;
            }
        }
        anio++;
    }
}

void promedioPorAnio(float matriz[][COLUMNAS])
{
    float promedio = 0;
    int anio = 2024;
    for(int i = 0; i < 5; i++){
        printf("******%d******\n",anio);
        for(int j = 0; j < 12; j++){
            promedio += matriz[i][j];
        }
        promedio /= 12;
        printf("promedio: $%.2f\n",promedio);
        promedio = 0;
        anio++;
    }
}

void mejorPeorMes(float matriz[][COLUMNAS])
{
    float menor = 999, mayor = 0;
    int mesMenor,mesMayor,anioMayor,anioMenor;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 12; j++){
            if(matriz[i][j] > mayor){
                mayor = matriz[i][j];
                mesMayor = j;
                anioMayor = i;
            }
            else if(matriz[i][j] < menor){
                menor = matriz[i][j];
                mesMenor = j;
                anioMenor = i;
            }
        }
    }

    switch(anioMayor){
        case 0: anioMayor = 2024; break;
        case 1: anioMayor = 2025; break;
        case 2: anioMayor = 2026; break;
        case 3: anioMayor = 2027; break;
        case 4: anioMayor = 2028; break;
    }

      switch(anioMenor){
        case 0: anioMenor = 2024; break;
        case 1: anioMenor= 2025; break;
        case 2: anioMenor= 2026; break;
        case 3: anioMenor= 2027; break;
        case 4: anioMenor= 2028; break;
    }

    switch(mesMayor){
        case 0: printf("%d: enero fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 1: printf("%d: febrero fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 2: printf("%d: marzo fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 3: printf("%d: abril fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 4: printf("%d: mayo fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 5: printf("%d: junio fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 6: printf("%d:julio fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 7: printf("%d: agosto fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 8: printf("%d: septiembre fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 9: printf("%d: octubre fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 10: printf("%d: noviembre fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
        case 11: printf("%d: diciembre fue el mes con mas ganancias con $%.2f\n",anioMayor,mayor); break;
    }
    switch(mesMenor){
        case 0: printf("%d: enero fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 1: printf("%d: febrero fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 2: printf("%d: marzo fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 3: printf("%d: abril fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 4: printf("%d: mayo fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 5: printf("%d: junio fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 6: printf("%d: julio fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 7: printf("%d: agosto fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 8: printf("%d: septiembre fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 9: printf("%d: octubre fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 10: printf("%d: noviembre fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
        case 11: printf("%d: diciembre fue el mes con menos ganancias con $%.2f\n",anioMenor,menor); break;
}}