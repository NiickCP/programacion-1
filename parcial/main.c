#define MAX_QTY 200
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#include "funciones.h"
int main()
{
void adminProducto (producto productoArray[]);
void adminProveedor(proveedor productoArray[]);

int main()
{
    // arrays de producto
    producto productoArray[MAX_QTY];
    setProductoStatus(productoArray,MAX_QTY,0);
    //________________________________________________

    // arrays de producto
    proveedor productoArray[MAX_QTY];
    setProveedorStatus(productoArray,MAX_QTY,0);
    //________________________________________________


    // Alta de datos para testing
    setProducto(productoArray,1,1,"What you need before you can learn C",1,777);
    setProducto(productoArray,2,2,"Using a Compiler",2,33);
    setProducto(productoArray,3,3,"A Taste of C",3,98);
    setProducto(productoArray,4,4,"Why Learn C",1,876);

    setProveedor(productoArray,1,1,"Brian");
    setProveedor(productoArray,2,2,"Dennis");
    setProveedor(productoArray,3,3,"Linus");
    setProveedor(productoArray,4,4,"Richard2");
        //________________________________________________

    int option = 0;

    while(option != 4)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ABM Productos \n2 - ABM Proveedores \n3 - Listar productos\n4 - SALIR\n\n\n");
        switch(option)
        {
            case 1: // ABM LIBROS
                adminProducto(productoArray);
                break;
            case 2: // ABM AUTORES
                adminProveedor(productoArray);
                break;
            case 3: // LISTAR
                system("@cls||clear");
                showBookAuthorArray(productoArray,MAX_QTY,productoArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");

                break;

        }
    }
    return 0;
}
void adminProveedor(proveedor productoArray[])
{
    // variables auxiliares
    char nameAux[51];
    int proveedorIdAux;
    //________________________________________________
    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    while(option != 4)
    {
         system("@cls||clear");
         printf("\n------------  ABM Proveedores ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - LISTAR\n4 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE proveedor

                freePlaceIndex = findProveedorEmptyPlace(productoArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                proveedorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                if(findProveedorById(productoArray,MAX_QTY,proveedorIdAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getValidString("Ingrese el nombre del autor: ","El nombre debe estar compuesto solo por letras\n", nameAux);

                setProveedor(productoArray,freePlaceIndex,proveedorIdAux,nameAux,lastNameAux);

                break;

            case 2: // BAJA proveedor

                proveedorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                foundIndex = findAuthorById(productoArray,MAX_QTY,proveedorIdAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                productoArray[foundIndex].status = 0;
                break;

            case 3: // LISTAR
                system("@cls||clear");
                showAuthorArray(productoArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;


         }
    }
}
}
