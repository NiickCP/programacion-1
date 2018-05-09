
#define MAX_QTY 200
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#include "funciones.h"
void modificaProducto(EProducto vec[], int tam){
    EProducto nuevoDatoProducto;
    int code;
    int esta;
    char confirma;
    int salir = 0;

    system("cls");
    printf("---Modifica Producto---\n\n");

   printf("Ingrese codigo: ");
        scanf("%d", &code);

        esta = buscarProducto(vec, tam, code);

        if(esta == -1)
        {
            printf("\nEl codigo %d no se encuentra en el sistema\n\n", code);

        }
        else{

                mostrarEmpleado(vec[esta]);

        do{
            printf("\nConfirma modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            do{
                switch(menuModifica()){
                    case 1:
                        printf("Ingrese el nuevo importe: ");
                        scanf("%d" , &nuevoDatoProducto.importe);
                        vec[esta].importe = nuevoDatoProducto.importe;
                        break;
                    case 2:
                        printf("Ingrese el nuevo nombre del producto: ");
                        fflush(stdin);
                        gets(nuevoDatoProducto.descripcion);
                        strcpy(vec[esta].descripcion , nuevoDatoProducto.descripcion);
                        break;
                    case 3:
                        printf("Ingrese la nueva cantidad: ");
                        scanf("%d" , &nuevoDatoProducto.stock);
                        vec[esta].stock = nuevoDatoProducto.stock;
                        break;
                    case 7:
                        salir = 1;
                        break;
                }

            }while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
        }
        else{
            printf("\nSe ha cancelado la modificacion\n\n");
        }

        }
}

int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Producto---\n\n");
    printf("1-Importe\n");
    printf("2-Descripcion\n");
    printf("3-Cantidad\n");
    printf("7-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void adminProveedor(EProveedor proveedorArray[])
{
    // variables auxiliares
    char nameAux[51];
    char lastNameAux[51];
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

                freePlaceIndex = findProveedorEmptyPlace(proveedorArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                proveedorIdAux = getValidInt("Ingrese el codigo del proveedor: ","El codigo del proveedor debe ser numerico\n", 1, 500);
                if(findProveedorById(proveedorArray,MAX_QTY,proveedorIdAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getValidString("Ingrese el nombre del proveedor: ","El nombre debe estar compuesto solo por letras\n", nameAux);

                setProveedor(proveedorArray,freePlaceIndex,proveedorIdAux,nameAux);

                break;

            case 2: // BAJA proveedor

                proveedorIdAux = getValidInt("Ingrese el codigo del proveedor: ","El codigo del proveedor debe ser numerico\n", 1, 500);
                foundIndex = findProveedorById(proveedorArray,MAX_QTY,proveedorIdAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                proveedorArray[foundIndex].status = 0;
                break;

            case 3: // LISTAR
                system("@cls||clear");
                showProveedorArray(proveedorArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;


         }
    }
}

void adminProducto(producto productoArray[])
{
    // variables auxiliares
    char titleAux[51];

    int proveedorIdAux;
    int codeAux;
    int stockAux;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    while(option != 6)
    {
         system("@cls||clear");
         printf("\n------------  ABM Productos ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE LIBRO

                freePlaceIndex = findProductoEmptyPlace(productoArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                codeAux = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser numerico\n", 1, 15000);
                if(findProductoByCode(productoArray,MAX_QTY,codeAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                proveedorIdAux =  getValidInt("Ingrese el ID del proveedor del producto: ","El ID del proveedor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de productos: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titlo debe estar compuesto solo por letras\n", titleAux);

                setProducto(productoArray,freePlaceIndex,codeAux,titleAux,proveedorIdAux,stockAux);

                break;

            case 2: // BAJA Producto

                codeAux = getValidInt("Ingrese el codigo deñ producto a dar de baja: ","El codigo del producto debe ser numerico\n", 1, 15000);
                foundIndex = findProductoByCode(productoArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                productoArray[foundIndex].status = 0;
                break;

            case 3: // MODIFICAR producto

                codeAux = getValidInt("Ingrese el codigo del producto a modificar: ","El codigo del producto debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(productoArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }


                proveedorIdAux =  getValidInt("Ingrese el ID del proveedor del producto: ","El ID del autor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de productos: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titulo debe estar compuesto solo por letras\n", titleAux);

                setProducto(productoArray,foundIndex,codeAux,titleAux,proveedorIdAux,stockAux);

                break;

            case 4: // LISTAR
                system("@cls||clear");
                showProductoArray(productoArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;

            case 5: // ORDENAR
                             break;


         }
                getChar("\n\nOrdenados. ENTER (para continuar)");
orderProductoArrayByTitle(productoArray,MAX_QTY);
    }
}

/**
 * \brief Inicializa el status en un array de productos
 * \param productoArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProductoStatus(EProducto productoArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        productoArray[i].status = value;
    }
}
/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param productoArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProductoByCode(EProd productoArray[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(productoArray[i].code == code && productoArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param productoArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findProductoEmptyPlace(EProducto productoArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
         if(productoArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}
/**
 * \brief Busca el precio promedio
 * \param productoArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay bookos activos (-1) y si lo hay el precio de ese booko
 *
 */
void orderProductoArrayByTitle(EProducto productoArray[],int arrayLenght)
{
    EProducto productoAux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(productoArray[i].status == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(productoArray[j].status == 0)
            {
                continue;
            }
            if(strcmp(productoArray[j].title,productoArray[i].title)<0)
            {
                productoAux = productoArray[j];
                productoArray[j] = productoArray[i];
                productoArray[i] = productoAux;
            }
            else if(strcmp(productoArray[j].title,productoArray[i].title) == 0)
            {
                if(productoArray[i].code > productoArray[j].code)
                {
                    productoAux = productoArray[j];
                    productoArray[j] = productoArray[i];
                    productoArray[i] = productoAux;
                }
            }
        }
    }
}

/**
 * \brief Carga los valores del libro
 * \param productoArray Es el array de libros
 * \param freePlaceIndex Indica la posicion a setear
 * \param codeAux Codigo del libro
 * \param titleAux Titulo del libro
 * \param authorIdAux Id del autor
 * \param stockIdAux Cantidad de ejemplaes disponibles
 * \return -
 *
 */
void setBook(EProducto productoArray[],int freePlaceIndex, int codeAux,char titleAux[], int proveedorIdAux,int stockAux)
{

    productoArray[freePlaceIndex].proveedorId = proveedorIdAux;
    strcpy(productoArray[freePlaceIndex].title,titleAux);
    productoArray[freePlaceIndex].stock = stockAux;
    productoArray[freePlaceIndex].code = codeAux;
    productoArray[freePlaceIndex].status = 1;
}

/**
 * \brief Muestra los libros activos por pantalla
 * \param productoArray Es el array de libros
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showProductorArray(EProducto productoArray[],int arrayLenght)
{
    int i;
    printf("\n| CODIGO  |                      TITULO              | AUTOR | STOCK |");
    for(i=0;i < arrayLenght; i++)
    {
        if(productoArray[i].status != 0)
        {
            printf("\n| %6d  | %-40s | %5d | %5d |",productoArray[i].code,productoArray[i].title,productoArray[i].authorId,productoArray[i].stock);
        }
    }

}
/**
 * \brief Inicializa el status en un array de autores
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProveedorStatus(EProveedor proveedorArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        proveedorArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un autor mediante su codigo
 * \param proveedorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProveedorById(EProveedor proveedorArray[],int arrayLenght,int proveedorIdAux)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(proveedorArray[i].proveedorId == proveedorIdAux && proveedorArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Carga los valores del autor
 * \param proveedorArray Es el array de autores
 * \param freePlaceIndex Indica la posicion a setear
 * \param proveedorIdAux Id del autor
 * \param nameAux Nombre del autor
 * \param lastNameAux Apellido del autor
 * \return -
 *
 */
void setProveedor(EProveedor proveedorArray[],int freePlaceIndex, int proveedorIdAux,char nameAux[],char lastNameAux[])
{

    proveedorArray[freePlaceIndex].proveedorId = proveedorIdAux;
    strcpy(proveedorArray[freePlaceIndex].name,nameAux);
    strcpy(proveedorArray[freePlaceIndex].lastName,lastNameAux);
    proveedorArray[freePlaceIndex].status = 1;

}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param proveedorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findProveedorEmptyPlace(EProveedor proveedorArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(proveedorArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Muestra los autores activos por pantalla
 * \param proveedorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showProveedorArray(EProveedor proveedorArray[],int arrayLenght)
{
    int i;
    printf("\n| CODIGO  |      NOMBRE      |    APELLIDO     ");
    for(i=0;i < arrayLenght; i++)
    {
        if(proveedorArray[i].status != 0)
        {
            printf("\n| %6d  | %-15s  | %-15s",proveedorArray[i].proveedorId,proveedorArray[i].name);
        }
    }

}
/*
 * \brief Muestra los libros activos por pantalla indicando el apellido del Autor
 * \param productoArray Es el array de libros
 * \param arrayLenght Indica la logitud del array libros
 * \param proveedorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array autores
 * \return -
 */
void showProductoProveedorArray(EProducto productoArray[],int arrayLenght,EProveedor proveedorArray[],int proveedorArrayLenght)
{
    int i;
    char auxProveedor[51];
    int proveedorIdAux;
    printf("\n| CODIGO  |                    TITULO            |     AUTOR       | STOCK |");
    for(i=0;i < arrayLenght; i++)
    {
        if(productoArray[i].status != 0)
        {
            proveedorIdAux = findProveedorById(proveedorArray,proveedorArrayLenght,productoArray[i].proveedorId);
            if( proveedorIdAux != -1)
            {
                strcpy(auxProveedor,proveedorArray[proveedorIdAux].lastName);
            }
            else
            {
                sprintf(auxProveedor, "? (Id:%d)", productoArray[i].proveedorId);
            }
            printf("\n| %6d  | %-36s | %15s | %5d |",productoArray[i].code,productoArray[i].title,auxProveedor,productoArray[i].stock);
        }
    }
