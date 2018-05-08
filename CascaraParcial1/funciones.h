#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codeProducto;
    char descripcion [50];
    int importe;
    int cantidad;
    int estado;
    int proveedorID;
}Producto;

typedef struct
{
    int codeProveedor;
    char descripcion [50];
    int estado;
    int proveedorID;
}Proveedor;
void inicializador (Proveedor vec [],int tam);
int buscarLibre (Proveedor vec[], int tam);
int buscarProveedor (Proveedor vec[], int tam, char descrip []);
int validarCHAR (char decrip []);
void agregarProveedor (Proveedor vec[], int tam);
void mostrarProveedor (Proveedor[], int tam);
int autoIncremento (Proveedor vec [], int tam);
#endif // FUNCIONES_H_INCLUDED
