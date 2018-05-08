#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50
#define CANT 500

int main()
{
    char seguir='s';
    int opcion=0;
    Proveedor prove [TAM];
    Producto produ [CANT];
    inicializador(prove,TAM);

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
                    printf("1- Agregar PROVEEDOR \n");
                    printf("2- Agregar PRODUCTOR\n");

                    printf("\n\nIndique opcion:");
                    scanf("%d",&opcion);
                    system("cls");
                    switch(opcion)
                    {
                        case 1:
                            agregarProveedor(prove,TAM);
                            break;
                        case 2:
                        agregarProducto(produ, CANT);
                        break;
                    }
                    system("pause");
                //agregar
                    break;
            case 2:
                system("cls");
                mostrarProveedor(prove, TAM);
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
