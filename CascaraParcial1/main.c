#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 500

int main()
{
    char seguir='s';
    int opcion=0;
    Proveedor gente [TAM];
    inicializador(gente,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar \n");
        printf("2- Modificar \n");
        printf("3- Borrar\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\n\nIndique opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarProveedor(gente,TAM);
                system("pause");
                //agregar
                break;
            case 2:
                system("cls");
                system("pause");
                //borrar
                break;
            case 3:
                system("cls");
                system("pause");
                //imprimir lista
                break;
            case 4:
                //grafico edades
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion que este dentro del menu");
                break;

        }
    }

    return 0;
}
