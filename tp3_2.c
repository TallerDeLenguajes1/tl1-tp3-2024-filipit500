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
    int opcion = 1;
    while(opcion == 1 || opcion == 2){
        printf("1: mostrar promedio anual\n");
        printf("2: mostrar mejor y peor mes\n");
        printf("3: salir\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion){
            case 1: promedioAnual(matriz); break;
            case 2: valorMaximo(matriz); break;
            case 3: printf("saliendo...\n"); break;
            default: printf("no se selecciono una opcion valida, saliendo...\n");
        }
    }
    return 0;
}

void cargarMostrarMatriz(int matriz[][MESES])
{
    int anio = 2024;
    for(int i = 0; i < ANIOS; i++){
        printf("------%d------\n",anio);
        for(int j = 0; j < MESES; j++){
            matriz[i][j] = rand () % 40001 + 10000;
            switch(j){
                case 0: printf("enero: %d\n",matriz[i][j]); break;
                case 1: printf("febrero: %d\n",matriz[i][j]); break;
                case 2: printf("marzo: %d\n",matriz[i][j]); break;
                case 3: printf("abril: %d\n",matriz[i][j]); break;
                case 4: printf("mayo: %d\n",matriz[i][j]); break;
                case 5: printf("junio: %d\n",matriz[i][j]); break;
                case 6: printf("julio: %d\n",matriz[i][j]); break;
                case 7: printf("agosto: %d\n",matriz[i][j]); break;
                case 8: printf("septiembre: %d\n",matriz[i][j]); break;
                case 9: printf("octubre: %d\n",matriz[i][j]); break;
                case 10: printf("noviembre: %d\n",matriz[i][j]); break;
                case 11: printf("diciembre: %d",matriz[i][j]); break;
            }
        }
        anio++;
        printf("\n");
    }
}


void promedioAnual(int matriz[][MESES])
{
    int anio = 2024;
    printf("******PROMEDIOS ANUALES******\n");
    for(int i = 0; i < ANIOS; i++){
        int promedio = 0;
        for(int j = 0; j < MESES; j++){
            promedio += matriz[i][j];
        }
        promedio /= MESES;
        printf("promedio anual %d: $%d\n",anio,promedio);
        anio++;
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

    switch(anioMenor){
        case 0: anioMenor = 2024; break;
        case 1: anioMenor = 2025; break;
        case 2: anioMenor = 2026; break;
        case 3: anioMenor = 2027; break;
        case 4: anioMenor = 2028; break;
    }

    switch(anioMayor){
        case 0: anioMayor = 2024; break;
        case 1: anioMayor = 2025; break;
        case 2: anioMayor = 2026; break;
        case 3: anioMayor = 2027; break;
        case 4: anioMayor = 2028; break;
    }

    printf("******MEJOR/PEOR MES******\n");
    switch(mesMayor){
    case 0: printf("enero de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 1: printf("febrero de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 2: printf("marzo de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 3: printf("abril de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 4: printf("mayo de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 5: printf("junio de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 6: printf("julio de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 7: printf("agosto de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 8: printf("septiembre de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 9: printf("octubre de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 10: printf("noviembre de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
    case 11: printf("diciembre de %d fue el mes de mayor produccion con %d ganancias\n", anioMayor, mayor); break;
}

switch(mesMenor){
    case 0: printf("enero de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 1: printf("febrero de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 2: printf("marzo de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 3: printf("abril de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 4: printf("mayo de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 5: printf("junio de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 6: printf("julio de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 7: printf("agosto de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 8: printf("septiembre de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 9: printf("octubre de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 10: printf("noviembre de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
    case 11: printf("diciembre de %d fue el mes de menor produccion con %d ganancias\n", anioMenor, menor); break;
}

}