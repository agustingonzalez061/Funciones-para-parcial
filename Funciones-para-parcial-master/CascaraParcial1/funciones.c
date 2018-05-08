#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
void inicializador (Proveedor vec [],int tam)
 {
     int i;
     for (i = 0 ; i< tam ; i++)
     {
         vec[i].estado = 0;
     }
 }
 int buscarLibre (Proveedor vec[], int tam)
 {
     int i;
     int indice = -1;
     for (i = 0; i < tam ; i++)
     {
         if (vec[i].estado == 0)
         {
             indice = i;
             break;
         }
     }
     return indice;
 }
 int buscarProveedor(Proveedor vec[], int tam, char descrip [])
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].estado == 1 && strcmp(vec[i].descripcion,descrip) == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int validarCHAR (char descrip [])
{
    int i;
    int letras;
    letras = strlen(descrip);
    while(letras > 50)
    {
        printf("La descripcion es demasiado largo");
        return 0;
    }
    for (i = 0; i < strlen(descrip) ; i++)
    {
        if (!(isalpha(descrip[i])))
        {
            printf("La descripcion no es valido.");
            return 0;
        }

    }

    return 1;
}
// FUNCIONES PARA PROVEEDOR
void agregarProveedor (Proveedor vec[], int tam)
{
    int indice;
    int esta;
    char descripcion [500];
    int descripcionVal;
    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("El sistema esta completo, si quiere agregar una persona tendra que eliminar primero a otra");
    }
    else
    {
        do
        {
            printf("\nIngrese descripcion:");
            fflush(stdin);
            scanf("%[^\n]",descripcion);
            descripcionVal = validarCHAR(descripcion);
        }while (descripcionVal == 0);


        esta = buscarProveedor(vec,tam,descripcion);
        if (esta != -1 )
        {
            printf("Esta Descripcion ya esta en el sistema\n La descripcion es:\n %s\n",vec[esta].descripcion);
        }
            else{

                strcpy(vec[indice].descripcion,descripcion);

                vec[indice].estado =1;
                vec[indice].codeProveedor = autoIncrementoProve(vec,tam);
                vec[indice].proveedorID = vec[indice].codeProveedor;

                printf("Se agrego exitosamente\n");
                }
     }
}
void mostrarProveedor(Proveedor vec[], int tam)
{
    int i;
    printf("  CODIGO    Descripcion\n\n");
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].estado==1)
        {
            printf("  %d     %s\n\n",vec[i].codeProveedor, vec[i].descripcion);
        }
    }

}
int autoIncrementoProve (Proveedor vec [], int tam)
{
    int i;
    int code = 1;
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].codeProveedor != code && vec[i].estado == 1)
        {
            return code;
        }
        else
        {
            code ++;
        }

    }
}
// FUNCIONES PARA PRODUCTO
int autoIncrementoProdu (Producto vec [], int tam)
{
    int i;
    int code = 1;
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].codeProducto != code && vec[i].estado == 1)
        {
            return code;
        }
        else
        {
            code ++;
        }

    }
}
 int buscarProducto (Producto vec[], int tam, char descrip [])
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].estado == 1 && strcmp(vec[i].descripcion,descrip) == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
int validarINT (char cantidad [])//operacion de carga de datos

{
    int i;
    int numero;
    for (i = 0; i < strlen(cantidad) ; i++)
    {
        if (!(isdigit(cantidad[i])))
        {
            printf("La cantidad no es valida");
            return 0;
        }

    }
    numero = atoi(cantidad);
    while( numero < 1)
    {
        printf("La cantidad debe ser mayor a 0");
        return 0;
    }
    return numero;
}
float validarFLOAT (char cantidad [])//operacion de carga de datos

{
    int i;
    int numero;
    for (i = 0; i < strlen(cantidad) ; i++)
    {
        if (!(isdigit(cantidad[i])))
        {
            printf("El importe no es valida");
            return 0;
        }

    }
    numero = atof(cantidad);
    while( numero < 1)
    {
        printf("El importe debe ser mayor a 0");
        return 0;
    }
    return numero;
}
int buscarCode (Proveedor vec[], int tam, int code)
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].estado == 1 && vec[i].codeProveedor == code)
        {
            return 1;
        }
        else
        {
            printf("No se encontro el codigo ingresado");
            return 0;
        }
    }

}
void agregarProducto (Producto vec[], int tam)
{
    int indice;
    int esta;
    char descripcion [500];
    int descripcionVal;
    char importe [20];
    float importeVal;
    char cantidad [10];
    int cantVal;
    int codeProdu;
    int codeVal;
    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("El sistema esta completo, si quiere agregar una persona tendra que eliminar primero a otra");
    }
    else
    {
        do
        {
            printf("\nIngrese descripcion:");
            fflush(stdin);
            scanf("%[^\n]",descripcion);
            descripcionVal = validarCHAR(descripcion);
        }while (descripcionVal == 0);


        esta = buscarProducto(vec,tam,descripcion);
        if (esta != -1 )
        {
            printf("Esta Descripcion ya esta en el sistema\n La descripcion es:\n %s\n",vec[esta].descripcion);
        }
            else{

                strcpy(vec[indice].descripcion,descripcion);
                do{
                    printf("\nIngrese importe:");
                    scanf("%s", importe);
                    importeVal = validarFLOAT(importe);
                }while (importeVal == 0);
                vec[indice].importe = importeVal;
                do{
                    printf("\nIngrese cantidad:");
                    scanf("%s", cantidad);
                    cantVal = validarINT(cantidad);
                }while (cantVal == 0);

                vec[indice].cantidad = cantVal;

                do
                {
                    printf("Ingrese codigo del productor");
                    scanf("%d", &codeProdu);
                    codeVal = buscarCode(vec, tam, codeProdu);

                }while (codeVal== 0);
                vec[indice].estado =1;
                vec[indice].codeProducto = autoIncrementoProdu(vec,tam);
                vec[indice].ProductoID = codeProdu;

                printf("Se agrego exitosamente\n");
                }
     }
}





