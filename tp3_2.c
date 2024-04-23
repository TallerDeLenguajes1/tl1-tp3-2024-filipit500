#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANIOS 5
#define MESES 12

void cargarMostrarMatriz(int matriz[][MESES]);
void promedioAnual(int matriz[][MESES]);
void valorMaximo(int matriz[][MESES]);

int main()
{
    srand(time(NULL));
    int matriz[ANIOS][MESES];
    cargarMostrarMatriz(matriz);
    promedioAnual(matriz);
    valorMaximo(matriz);
    return 0;
}

void cargarMostrarMatriz(int matriz[][MESES])
{
    for(int i = 0; i < ANIOS; i++){
        for(int j = 0; j < MESES; j++){
            matriz[i][j] = rand () % 40001 + 10000;
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }
}


void promedioAnual(int matriz[][MESES])
{
    for(int i = 0; i < ANIOS; i++){
        int promedio = 0;
        for(int j = 0; j < MESES; j++){
            promedio += matriz[i][j];
        }
        promedio /= MESES;
        printf("promedio anual: $%d\n",promedio);
    }
}

void valorMaximo(int matriz[][MESES])
{
    int menor = 100000,mayor= 0,mesMenor,mesMayor,anioMenor,anioMayor;
    for(int i = 0; i < ANIOS; i++){
        for(int j = 0; j < MESES; j++){
            if(matriz[i][j] <= menor){
                menor = matriz[i][j];
                anioMenor = i;
                mesMenor = j;
            }
            if(matriz[i][j] >=mayor){
                mayor = matriz[i][j];
                anioMayor = i;
                mesMayor = j;
            }
        }
    }

    printf("anio menor: %d \n mes menor: %d\n",anioMenor,mesMenor);
    printf("anio mayor: %d \n mes mayor: %d\n",anioMayor,mesMayor);
}