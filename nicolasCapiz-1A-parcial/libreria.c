#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "libreria.h"
#include "productos.h"

int menuPrincipal()
{
    char opcion[30];
    int numero;
    printf("-----------Proveedores-----------\n");
    printf("-1. Alta de producto            -\n");
    printf("-2. Modificar producto          -\n");
    printf("-3. Baja de producto            -\n");
    printf("-4. Informar                    -\n");
    printf("-5. Listar                      -\n");
    printf("-6. Salir                       -\n");
    printf("---------------------------------\n");
    printf("-Ingrese opcion:");
    scanf("%s", opcion);

    while (validarLetra(opcion)==1)
    {
        printf("Error.\nNo se admiten letras, porfavor ingrese un numero entre el 1 y el 6.\n");
        printf("Ingrese nuevamente una opcion: ");
        scanf("%s",opcion);
    }

    numero = atoi(opcion);
    return numero;
}

int cantidadValida()
{
    char opcion[30];
    int numero;
    printf("Ingrese la cantidad de productos: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Error, no se admiten letras.\nPorfavor ingrese un numero: ");
        scanf("%s",opcion);
    }
    numero = atoi(opcion);
             return numero;
}

int validarLetra(char opcion[])
{
    int flag = 0,longitud,i;
    longitud = strlen(opcion);
    for(i=0; i<longitud; i++)
    {
        if(!isdigit(opcion[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int subMenu1()
{
    int opcion;

    system("cls");
    printf("------------------------------------------Menu Informar-----------------------------------------\n");
    printf("-1.Informar:\n\n1. Total y promedio de los importes. Y cuantos productos superan ese promedio. -\n");
    printf("-2. Total y promedio de los importes. Y cuantos productos no superan ese promedio.             -\n");
    printf("-3. Cantidad de productos cuyo stock es menor o igual a 10.                                    -\n");
    printf("-4. Cantidad de productos cuyo stock es mayor a 10                                             -\n");
    printf("-5. Salir                                                                                      -\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenu2()
{
    int opcion;

    system("cls");
    printf("-----------------------------------Menu de Listado-----------------------\n");
    printf("-2. Listado de productos cuyo stock es menor o igual a 10               -\n");
    printf("-3. Listado de productos cuyo stock es mayor a 10                       -\n");
    printf("-4. Listado de productos cuyo importe no supera el promedio             -\n");
    printf("-5. Listado de productos cuyo importe supera el promedio                -\n");
    printf("-6. Listado de productos cuyo importe supera el promedio                -\n");
    printf("-7. Todos los productos de un proveedor                                 -\n");
    printf("-8. Productos de proveedor a buscar                                     -\n");
    printf("-9. Proveedor con mas productos                                         -\n");
    printf("-10. Proveedor con menos productos                                      -\n");
    printf("-13. Salir                                                              -\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

