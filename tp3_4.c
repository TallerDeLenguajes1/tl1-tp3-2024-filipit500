#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} typedef Producto;


struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// CantidadProductosAPedir”
} typedef Cliente;

void cargarClientes(Cliente *Clientes, int cantidad);
void costoTotal(Cliente *Clientes, int cantidad);
void mostrarClientes(Cliente *Clientes,int cantidad);
void liberarMemoria(Cliente *clientes,int cantidad);

int main()
{
    srand(time(NULL));
    int cantidadClientes;
    //preguntamos la cantidad de clientes//
    printf("ingrese la cantidad de clientes:");
    fflush(stdin);
    scanf("%d",&cantidadClientes);
    //creamos el arreglo dinamico de clientess//
    Cliente *Clientes = (Cliente *)malloc(cantidadClientes*sizeof(Cliente));
    cargarClientes(Clientes,cantidadClientes);
    int opcion = 1;
    while(opcion == 1 || opcion == 2){
        printf("1: costo total de un producto\n");
        printf("2: mostrar Clientes\n");
        printf("3: salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: costoTotal(Clientes,cantidadClientes); break;
            case 2: mostrarClientes(Clientes,cantidadClientes); break;
            case 3: printf("saliendo...\n"); break;
            default: printf("no se eligio una opcion valida, saliendo...\n");
        }
    }
    liberarMemoria(Clientes,cantidadClientes);
    return 0;
}

void cargarClientes(Cliente *Clientes, int cantidad)
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    //CARGAMOS LOS CLIENTES//
    for(int i = 0; i < cantidad; i++){
        Clientes[i].ClienteID = i + 1;
        //usamos una cadena auxiliar para cargar el nombre//
        char buff[50];
        printf("nombre del cliente:");
        fflush(stdin);
        scanf("%s", buff);
        //reservamos la memoria para el nombre del cliente//
        Clientes[i].NombreCliente = (char*)malloc(strlen(buff) * sizeof(char) + 1);
        //copiamos el contenido de la cadena buff a el nombre del cliente//
        strcpy(Clientes[i].NombreCliente, buff);
        //generamos valores aleatorios del 1 al 5 para la cantidad de productos//
        Clientes[i].CantidadProductosAPedir = rand () % 5 + 1;
        //reservamos los productos//
        Clientes[i].Productos = (Producto *)malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto));
        //cargamos los productos//
        for(int j = 0; j < Clientes[i].CantidadProductosAPedir; j++){
            Clientes[i].Productos[j].ProductoID = j + 1;
            //generamos valores aleatorios del 1 al 10//
            Clientes[i].Productos[j].Cantidad = rand () % 10 +1;
            //generamos un numero aleatorio del 0 al 4 para el tipo de producto//
            int tipoProducto = rand () % 5;
            //reservamos memoria para el tipo de producto//
            Clientes[i].Productos[j].TipoProducto = (char *)malloc(strlen(TiposProductos[tipoProducto]) * sizeof(char) + 1);
            //copiamos la cadena//
            strcpy(Clientes[i].Productos[j].TipoProducto,TiposProductos[tipoProducto]);
            //generamos un valor aleatorio entre 0 y 100 para el precio unitario//
            Clientes[i].Productos[j].PrecioUnitario = (float)(rand() % 91 + 10);
        }
}
}


void costoTotal(Cliente *Clientes, int cantidad)
{
    int idCliente,idProducto,clienteValido = 0,productoValido = 0;
    float costo;
    for(int i = 0; i < cantidad; i++){
        printf("%d : ",Clientes[i].ClienteID);
        puts(Clientes[i].NombreCliente);
    }
    printf("ingrese el id del cliente:");
    fflush(stdin);
    scanf("%d",&idCliente);

    for(int i = 0; i < cantidad; i++){
        if(Clientes[i].ClienteID == idCliente){
            clienteValido = 1;
            for(int j = 0; j < Clientes[i].CantidadProductosAPedir; j++){
                printf("%d : ",Clientes[i].Productos[j].ProductoID);
                puts(Clientes[i].Productos[j].TipoProducto);
            }
            printf("ingrese el id del producto: ");
            fflush(stdin);
            scanf("%d",&idProducto);

            for(int j = 0; j < Clientes[i].CantidadProductosAPedir; j++){
                if(Clientes[i].Productos[j].ProductoID == idProducto){
                    productoValido = 1;
                    costo = Clientes[i].Productos[j].PrecioUnitario * Clientes[i].Productos[j].Cantidad;
                    printf("costo total: $%.2f\n",costo);
                }
            }
        }
    }
    if(clienteValido == 0){
        printf("no se ingreso un cliente valido\n");
    }
    if(productoValido == 0){
        printf("no se ingreso un producto valido\n");
    }
}
void mostrarClientes(Cliente *Clientes,int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        printf("------CLIENTE %d------\n",i+1);
        printf("id del cliente: %d\n",Clientes[i].ClienteID);
        printf("nombre del cliente: ");
        puts(Clientes[i].NombreCliente);
        printf("cantidad de productos: %d\n",Clientes[i].CantidadProductosAPedir);
        for(int j = 0; j < Clientes[i].CantidadProductosAPedir; j++){
            printf("-------PRODUCTO %d------\n",j+1);
            printf("id del producto: %d\n",Clientes[i].Productos[j].ProductoID);
            printf("cantidad: %d\n",Clientes[i].Productos[j].Cantidad);
            printf("tipo de producto: ");
            puts(Clientes[i].Productos[j].TipoProducto);
            printf("precio unitario: $%.2f\n",Clientes[i].Productos[j].PrecioUnitario);
        }
    }
}

void liberarMemoria(Cliente *clientes,int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        free(clientes[i].NombreCliente);
        for(int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            free(clientes[i].Productos[j].TipoProducto);
        }
        free(clientes[i].Productos);
    }
}