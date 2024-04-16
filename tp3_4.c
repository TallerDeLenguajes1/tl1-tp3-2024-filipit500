#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} typedef cliente;

void cargarClientes(cliente *clientesVector,int cantidad);
void cargarProductos(Producto *productos, int cantidad);
void mostrarClientes(cliente *Clientes, int cantidad);
void cadaCliente(cliente *clientes,int cantidad);
int main()
{
    srand(time(NULL));
    int cantidadClientes;
    printf("ingrese la cantidad de clientes que desea cargar:");
    fflush(stdin);
    scanf("%d",&cantidadClientes);
    cliente *ClientesVector = malloc(cantidadClientes * sizeof(cliente));
    cargarClientes(ClientesVector,cantidadClientes);
    mostrarClientes(ClientesVector,cantidadClientes);
}

void cargarClientes(cliente *clientesVector, int cantidad)
{
    int id = 1000;
    char nombre[50];
    for(int i = 0; i < cantidad; i++){
        clientesVector[i].ClienteID = id;
        printf("nombre del cliente:");
        fflush(stdin);
        gets(nombre);
        clientesVector[i].NombreCliente = malloc((strlen(nombre)+1) * sizeof(char));
        strcpy(clientesVector[i].NombreCliente,nombre);
        clientesVector[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientesVector[i].Productos = malloc(clientesVector[i].CantidadProductosAPedir * sizeof(Producto));
        cargarProductos(clientesVector[i].Productos,clientesVector[i].CantidadProductosAPedir);
    }
}

void cargarProductos(Producto *productos, int cantidad)
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int id = 345;
    
    for(int i = 0; i < cantidad; i++){
        int producto = rand () % 5;
        char buff[30];
        strcpy(buff,TiposProductos[producto]);
        productos[i].ProductoID = id;
        productos[i].Cantidad = rand() % 10 +1;
        productos[i].TipoProducto = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(productos[i].TipoProducto,buff);
        productos[i].PrecioUnitario = rand() % 91 + 10;
        id++;
    }
}

void mostrarClientes(cliente *Clientes, int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        float total = 0;
        printf("*******CLIENTE******\n");
        printf("nombre del cliente: ");
        puts(Clientes[i].NombreCliente);
        printf("id: %d\n",Clientes[i].ClienteID);
        printf("cantidad de productos: %d\n",Clientes[i].CantidadProductosAPedir);
        for(int j = 0; j < Clientes[i].CantidadProductosAPedir; j++){
            printf("******PRODUCTO %d******\n",j+1);
            printf("nombre: ");
            puts(Clientes[i].Productos[j].TipoProducto);
            printf("id del producto: %d\n",Clientes[i].Productos[j].ProductoID);
            printf("cantidad: %d\n",Clientes[i].Productos[j].Cantidad);
            printf("precio unitario: $%.2f\n",Clientes[i].Productos[j].PrecioUnitario);
            total += Clientes[i].Productos[j].PrecioUnitario;
        }
            printf("total a pagar: $%.2f\n",total);
    }
}

