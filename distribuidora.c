#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]={ "Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
} Cliente;

float costoTotal(Producto P);

int main(void){

    Cliente * clientes;
    int cant_clientes, tama;
    char Buff[50];
    float total;
    srand(time(NULL));
    printf("Ingrese el número de clientes:\n");
    scanf("%d", &cant_clientes);
    clientes = (Cliente *) malloc(cant_clientes * sizeof(Cliente));
    for(int i=0;i<cant_clientes;i++){
        clientes[i].ClienteID = i+1;
        printf("Ingrese el nombre del cliente número %d:\n", i+1);
        scanf("%s", Buff);
        tama = strlen(Buff);
        clientes[i].NombreCliente = (char *) malloc(tama * sizeof(char)+1);
        strcpy(clientes[i].NombreCliente, Buff);
        clientes[i].CantidadProductosAPedir = 1 + rand()%5;
        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            clientes[i].Productos[j].ProductoID = j+1;
            clientes[i].Productos[j].Cantidad = 1 + rand()%10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand()%91;
        }
    }

    printf("---CLIENTES---\n\n\n");
    for(int i=0;i<cant_clientes;i++){
        total=0;
        printf("ID de cliente: %d\n", clientes[i].ClienteID);
        printf("\tNombre del cliente: %s\n", clientes[i].NombreCliente);
        printf("\tCantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            printf("\tID de producto %d:\n", clientes[i].Productos[j].ProductoID);
            printf("\t\tTipo de producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("\t\tCantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("\t\tPrecio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            total += costoTotal(clientes[i].Productos[j]);
        }
        printf("\n\nTotal a pagar del cliente: %.2f\n", total);
    }

    for(int i=0;i<cant_clientes;i++){
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

float costoTotal(Producto P){
    return (P.Cantidad * P.PrecioUnitario);
}

