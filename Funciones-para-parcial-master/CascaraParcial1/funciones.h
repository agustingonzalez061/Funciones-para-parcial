#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codeProveedor;
    char descripcion [50];
    int estado;
    int proveedorID;
}Proveedor;


typedef struct
{
    int codeProducto;
    char descripcion [50];
    float importe;
    int cantidad;
    int estado;
    int ProductoID;
    Proveedor prove;
}Producto;


void inicializador (Proveedor vec [],int tam);
int buscarLibre (Proveedor vec[], int tam);
int buscarProveedor (Proveedor vec[], int tam, char descrip []);
int validarCHAR (char decrip []);
void agregarProveedor (Proveedor vec[], int tam);
void mostrarProveedor (Proveedor[], int tam);
void agregarProducto (Producto vec[], int tam);
float validarFLOAT (char cantidad []);
int buscarProducto (Producto vec[], int tam, char descrip []);
int validarINT (char cantidad []);
int autoIncrementoProve (Proveedor vec [], int tam);
int autoIncrementoProdu (Producto vec [], int tam);
#endif // FUNCIONES_H_INCLUDED
