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
                vec[indice].codeProveedor = autoIncremento(vec,tam);

                printf("Se agrego exitosamente\n");
                }
     }
}
/*void mostrarPersonas (Proveedor vec[], int tam)
{
    int i;
    printf("  CODIGO         Descripcion\n\n");
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].estado==1)
        {
            ordenar(vec,tam);
            printf("  %d       [^\n]\n\n",vec[i].codeProveedor, vec[i].descripcion);
        }
    }

}*/
int autoIncremento (Proveedor vec [], int tam)
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







