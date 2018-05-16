#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "libreria.h"
#include "productos.h"

void hardcodeProv(EProveedor lista[])
{
    EProveedor nuevaLista;

    strcpy(nuevaLista.descripcion, "Proveedor1");
    nuevaLista.idProv = 1;
    lista[0] = nuevaLista;

    strcpy(nuevaLista.descripcion, "Proveedor2");
    nuevaLista.idProv = 2;
    lista[1] = nuevaLista;

    strcpy(nuevaLista.descripcion, "Proveedor3");
    nuevaLista.idProv = 3;
    lista[2] = nuevaLista;

    strcpy(nuevaLista.descripcion, "Proveedor4");
    nuevaLista.idProv = 4;
    lista[3] = nuevaLista;

    strcpy(nuevaLista.descripcion, "Proveedor5");
    nuevaLista.idProv = 5;
    lista[4] = nuevaLista;
}

void inicializarVariables(EProducto vec[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        vec[i].idProd = 0;
        vec[i].estado = 0;
    }
}

int buscarLibre(EProducto lista[], int tam)
{
    int flag = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

int buscarId(EProducto lista[], int tam, int Id)
{
    int flag = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].idProd == Id && lista[i].estado == 1)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

void mostrar(EProducto lista, EProveedor proveedores)
{
    printf("%d\t%s\t\t%d\t\t%.2f\t%s\n", lista.idProd, lista.descripcion, lista.cantidad, lista.importe, proveedores.descripcion);
}

int mostrarTodos(EProducto lista[], int tam1, EProveedor proveedores[], int tam2)
{
    int flag = -1, flagNEO = 1, i, j;

    EProducto aux;

    while(flagNEO == 1)
    {
        flagNEO = 0;
        for(j=1; j<tam1; j++)
        {
            if(lista[j].importe > lista[j - 1].importe)
            {
                aux = lista[j];
                lista[j] = lista[j - 1];
                lista[j - 1] = aux;
                flagNEO = 1;
            }
            if(lista[j].importe == lista[j - 1].importe)
            {
                if(strcmp(lista[j].descripcion, lista[j-1].descripcion) < 0)
                {
                    aux = lista[j];
                    lista[j] = lista[j - 1];
                    lista[j - 1] = aux;
                    flagNEO = 1;
                }

            }
        }
    }

    system("cls");
    printf("Id\tProducto\tCantidad\tImporte\tProveedor\n\n");

    for(i=0; i<tam1; i++)
    {
        for(j=0; j<tam2; j++)
        {
            if(lista[i].idProv == proveedores[j].idProv && lista[i].estado == 1)
            {
                mostrar(lista[i], proveedores[j]);
                flag = 1;
            }
        }
    }
    printf("\n\n\n\n\n");
    if(flag != 1)
    {
        system("cls");
        printf("No hay productos para mostrar.\n");
    }
    system("pause");

    return flag;

}

void alta(EProducto lista[], int tam, int Id, EProveedor proveedores[])
{
    EProducto nuevalista;
    int libre;

    libre = buscarLibre(lista, tam);

    if(libre == -1)
    {
        system("cls");
        printf("No hay espacio para cargar.");
    }
    else
    {
        system("cls");
        printf("---------------ALTA---------------\n");

        mostrarProveedores(proveedores, 5);
        printf("\nIngrese Id de proveedor al cual agregarle el producto: ");
        scanf("%d", &nuevalista.idProv);
        while(nuevalista.idProv > 5)
        {
            printf("\nIngrese Id de proveedor al cual agregarle el producto: ");
            scanf("%d", &nuevalista.idProv);
        }

        nuevalista.idProd = Id;
        printf("Ingrese descripcion del producto: ");
        fflush(stdin);
        scanf("%[^\n]", nuevalista.descripcion);
        while(strlen(nuevalista.descripcion) > 50)
        {
            system("cls");
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            scanf("%[^\n]", nuevalista.descripcion);
        }

        nuevalista.cantidad = cantidadValida();
        while(nuevalista.cantidad < 0)
        {
            printf("Reingrese cantidad: ");
            scanf("%d", &nuevalista.cantidad);
        }

        printf("Ingrese importe: ");
        scanf("%f", &nuevalista.importe);

        nuevalista.estado = 1;

        system("cls");
        printf("Producto agregado!\n");
        system("pause");
    }
    lista[libre] = nuevalista;
}

void modificacion(EProducto lista[], int tam, EProveedor proveedores[])
{
    int Id;
    char respuesta = 'n';
    int esta, opcion, flagEsta;

    if((flagEsta = mostrarTodos(lista, tam, proveedores, 5)) == 1)
    {
        printf("\nIngrese Id a buscar: ");
        scanf("%d", &Id);
        esta = buscarId(lista, tam, Id);
        if(esta != -1)
        {
            system("cls");
            mostrar(lista[esta], proveedores[esta]);
            printf("\nDesea modificar este producto? s/n");
            fflush(stdin);
            respuesta = getch();
            if(respuesta == 's')
            {
                system("cls");
                printf("-----Modificacion de Producto-----\n");
                printf("-1-Descripcion                   -\n");
                printf("-2-Importe                       -\n");
                printf("-3-Cantidad                      -\n");
                printf("----------------------------------");
                printf("\nIngrese opcion: ");
                scanf("%d", &opcion);
                switch(opcion)
                {
                case 1:
                    printf("\nIngrese descripcion: ");
                    fflush(stdin);
                    scanf("%[^\n]", lista[esta].descripcion);
                    printf("\nModificacion exitosa.\n");
                    system("pause");
                    break;
                case 2:
                    printf("\nIngrese importe: ");
                    fflush(stdin);
                    scanf("%f", &lista[esta].importe);
                    printf("\nModificacion exitosa.\n");
                    system("pause");
                    break;
                case 3:
                    printf("\nIngrese cantidad: ");
                    scanf("%d", &lista[esta].cantidad);
                    printf("\nModificacion exitosa.\n");
                    system("pause");
                    break;
                }

            }
            else
            {
                printf("\nOpcion cancelada.\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("no existe el Id.\n");
            system("pause");
        }
    }
}

void baja(EProducto lista[], int tam, EProveedor proveedores[])
{
    int Id;
    char respuesta = 'n';
    int esta, flagEsta = 0;

    if((flagEsta = mostrarTodos(lista, tam, proveedores, 5)) == 1)
    {
        printf("\nIngrese Id a buscar: ");
        scanf("%d", &Id);
        esta = buscarId(lista, tam, Id);
        if(esta != -1)
        {
            system("cls");
            mostrar(lista[esta], proveedores[esta]);
            printf("\nConfirmar baja? s/n");
            fflush(stdin);
            respuesta = getch();
            if(respuesta == 's')
            {
                lista[esta].estado = 0;
                system("cls");
                printf("\n\nBaja con exito.\n");
                system("pause");
            }
            else
            {
                printf("\nOpcion cancelada.\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("no existe el Id.\n");
            system("pause");
        }
    }
}

void mostrarProveedor(EProveedor lista)
{
    printf("-%d\t%s               -\n", lista.idProv,lista.descripcion);
}

void mostrarProveedores(EProveedor lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarProveedor(lista[i]);
    }
}

int cantidadStockMas10(int cantidad, EProducto lista[], int tam)
{
    int contStock = 0, i;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].cantidad > cantidad && lista[i].estado == 1)
        {
            contStock++;
        }
    }

    return contStock;
}

int cantidadStockMenos10(int cantidad, EProducto lista[], int tam)
{
    int contStock = 0, i;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].cantidad <= cantidad && lista[i].estado == 1)
        {
            contStock++;
        }
    }

    return contStock;
}

void mostrarProductosMas10(EProducto lista[])
{
    int contador;

    contador = cantidadStockMas10(10, lista, 50);

    system("cls");
    printf("Cantidad de productos cuyo stock es mayor a 10: (%d)\n\n", contador);
    fflush(stdin);
    system("pause");
}

void mostrarProductosMenos10(EProducto lista[])
{
    int contador;

    contador = cantidadStockMenos10(10, lista, 50);

    system("cls");
    printf("Cantidad de productos cuyo stock es menor o igual a 10: (%d)\n\n", contador);
    fflush(stdin);
    system("pause");
}

int cantidadTotalProductos(EProducto lista[], int tam)
{
    int i, contador = 0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            contador++;
        }
    }

    return contador;
}

float acumulador(EProducto lista[], int tam)
{
    int i;
    float acumuladorImp = 0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            acumuladorImp = acumuladorImp + lista[i].importe;
        }
    }

    return acumuladorImp;
}

float promedio(EProducto lista[], int tam)
{
    int contador = 0;
    float promedio, acumuladorImp = 0;

    acumuladorImp = acumulador(lista, tam);
    contador = cantidadTotalProductos(lista, tam);
    promedio =  acumuladorImp / contador;

    return promedio;
}

int cantidadProductosSuperanProm(EProducto lista[], int tam)
{
    int i, contador = 0;
    float promedioImp;
    promedioImp = promedio(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].importe >= promedioImp && lista[i].estado == 1)
        {
            contador++;
        }
    }

    return contador;

}

int cantidadProductosNoSuperanProm(EProducto lista[], int tam)
{
    int i, contador = 0;
    float promedioImp;
    promedioImp = promedio(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].importe < promedioImp && lista[i].estado == 1)
        {
            contador++;
        }
    }

    return contador;
}

void mostrarCantidadProductosSuperanProm(EProducto lista[], int tam)
{
    int contador = 0, contMayor = 0;
    float total, promedioImp;

    total = acumulador(lista, tam);
    contador = cantidadTotalProductos(lista, 50);
    promedioImp = total/contador;
    contMayor = cantidadProductosSuperanProm(lista, tam);

    system("cls");
    printf("Total del importe: %.2f\n", total);
    printf("Promedio del importe: %.2f\n", promedioImp);
    printf("Cantidad de productos cuyo importe es mayor al promedio: (%d)\n\n", contMayor);
    system("pause");
}

void mostrarCantidadProductosNoSuperanProm(EProducto lista[], int tam)
{
    int contador = 0, contMenor = 0;
    float total, promedioImp;

    total = acumulador(lista, tam);
    contador = cantidadTotalProductos(lista, 50);
    promedioImp = total/contador;
    contMenor = cantidadProductosNoSuperanProm(lista, tam);

    system("cls");
    printf("Total del importe: %.2f\n", total);
    printf("Promedio del importe: %.2f\n", promedioImp);
    printf("Cantidad de productos cuyo importe es menor o igual al promedio: (%d)\n\n", contMenor);
    system("pause");
}

void mostrarProductosMas10Des(EProducto lista[])
{
    int i, flag = 0;

    system("cls");
    printf("Productos cuyo stock es mayor a 10:\n\n");
    for(i = 0; i<50; i++)
    {
        if(lista[i].cantidad > 10 && lista[i].estado == 1)
        {
            printf("%s\n", lista[i].descripcion);
            flag = 1;
        }
    }
    system("pause");
    if(flag == 0)
    {
        system("cls");
        printf("no hay productos con esa descripcion.\n");
        system("pause");
    }
}

void mostrarProductosMenos10Des(EProducto lista[])
{
    int i, flag = 0;

    system("cls");
    printf("Productos cuyo stock es menor o igual a 10:\n\n");
    for(i = 0; i<50; i++)
    {
        if(lista[i].cantidad <= 10 && lista[i].estado == 1)
        {
            printf("%s\n", lista[i].descripcion);
            flag = 1;
        }
    }
    system("pause");
    if(flag == 0)
    {
        system("cls");
        printf("no hay productos con esa descripcion.\n");
        system("pause");
    }
}

void mostrarCantidadProductosSuperanPromDes(EProducto lista[], int tam)
{
    int i;
    float total, promedioImp;

    total = acumulador(lista, tam);
    promedioImp = promedio(lista, tam);

    system("cls");
    printf("Productos cuyo importe supera el promedio: \n\n");
    for(i = 0; i<50; i++)
    {
        if(lista[i].importe >= promedioImp && lista[i].estado == 1)
        {
            printf("%s\n", lista[i].descripcion);
        }
    }


    printf("\n\nTotal del importe: %.2f\n", total);
    printf("Promedio del importe: %.2f\n", promedioImp);
    system("pause");
}

void mostrarCantidadProductosNoSuperanPromDes(EProducto lista[], int tam)
{
    int i;
    float total, promedioImp;

    total = acumulador(lista, tam);
    promedioImp = promedio(lista, tam);

    system("cls");
    printf("Productos cuyo importe no supera el promedio: \n\n");
    for(i = 0; i<50; i++)
    {
        if(lista[i].importe < promedioImp && lista[i].estado == 1)
        {
            printf("%s\n", lista[i].descripcion);
        }
    }


    printf("\n\nTotal del importe: %.2f\n", total);
    printf("Promedio del importe: %.2f\n", promedioImp);
    system("pause");
}

void productosDeProveedores(EProveedor lista[], EProducto listaP[])
{
    int i, j;


    system("cls");
    printf("Productos de cada proveedor: \n\n");
    for(i=0; i<5; i++)
    {
        printf("%s\n", lista[i].descripcion);
        for(j=0; j<50; j++)
        {
            if(lista[i].idProv == listaP[j].idProv && listaP[j].estado == 1)
            {
                printf("\n%s\t%.2f\t%d\n\n", listaP[j].descripcion, listaP[j].importe, listaP[j].cantidad);
            }
        }
    }
    system("pause");
}

void buscarProductosDeProveedor(EProveedor lista[], int tam, EProducto listaP[], int tamP)
{
    int i, j;
    int proveedor;

    system("cls");
    mostrarProveedores(lista, tam);
    printf("\nIngrese proveedor a mostrar productos: ");
    scanf("%d", &proveedor);

    while(proveedor > 5 || proveedor < 0)
    {
        mostrarProveedores(lista, tam);
        printf("\nIngrese proveedor a mostrar productos: ");
        scanf("%d", &proveedor);
    }

    printf("\n");
    for(i = 0; i<tam; i++)
    {
        if(proveedor == lista[i].idProv)
        {
            printf("%s:\n\n", lista[i].descripcion);

            for(j=0; j<tamP; j++)
            {
                if(listaP[j].estado == 1 && listaP[j].idProv == lista[i].idProv)
                {
                    printf("%s\t%.2f\n", listaP[j].descripcion, listaP[j].importe);
                }
            }
        }
    }
    printf("\n");
    system("pause");
}

int cantidadProductosBusqueda(int proveedor, EProducto lista[], int tam)
{
    int i, contador=0;

    for(i=0; i<tam; i++)
    {
        if(proveedor == lista[i].idProv && lista[i].estado == 1)
        {
            contador++;
        }
    }

    return contador;
}

int maximoProductos(EProveedor lista[], int tam, EProducto lista2[], int tam2)
{
    int flag = 0, maximo, cantidad, i;

    for(i=0; i<tam; i++)
    {
        cantidad = cantidadProductosBusqueda(lista[i].idProv, lista2, tam);
        if(cantidad>maximo || flag==0)
        {
            maximo = cantidad;
            flag = 1;
        }
    }
    return maximo;
}

int minimoProductos(EProveedor lista[], int tam, EProducto lista2[], int tam2)
{
    int flag = 0, minimo, cantidad, i;

    for(i=0; i<tam; i++)
    {
        cantidad = cantidadProductosBusqueda(lista[i].idProv, lista2, tam);
        if(cantidad<minimo || flag==0)
        {
            minimo = cantidad;
            flag = 1;
        }
    }
    return minimo;
}

void proveedorConMasProductos(EProveedor proveedor[], int tamPROV, EProducto productos[], int tamPROD)
{
    int i, j, cant;

    system("cls");
    cant = maximoProductos(proveedor, tamPROV, productos, tamPROD);
    printf("Proveedor con mas productos:\n\n");
    for(i=0; i<tamPROV; i++)
    {
        if(cant==cantidadProductosBusqueda(proveedor[i].idProv, productos, tamPROD))
        {
            printf("\n\n%s:\n", proveedor[i].descripcion);
            for(j=0; j<tamPROD; j++)
            {
                if(productos[j].estado == 1 && productos[j].idProv == proveedor[i].idProv)
                {
                    printf("\n%s\t\t$%.2f", productos[j].descripcion, productos[j].importe);
                }
            }
        }
    }
    printf("\n\n");
    system("pause");
}

void proveedorConMenosProductos(EProveedor proveedor[], int tamPROV, EProducto productos[], int tamPROD)
{
    int i, j, cant;

    system("cls");
    cant = minimoProductos(proveedor, tamPROV, productos, tamPROD);
    printf("Proveedor con menos productos:\n\n");
    for(i=0; i<tamPROV; i++)
    {
        if(cant==cantidadProductosBusqueda(proveedor[i].idProv, productos, tamPROD))
        {
            printf("\n\n%s:\n", proveedor[i].descripcion);
            for(j=0; j<tamPROD; j++)
            {
                if(productos[j].estado == 1 && productos[j].idProv == proveedor[i].idProv)
                {
                    printf("\n%s\t\t$%.2f", productos[j].descripcion, productos[j].importe);
                }
            }
        }
    }
    printf("\n\n");
    system("pause");
}

void mostrarProveedorConProductoMas10(EProveedor listaPROV[], int tamPROV, EProducto listaPROD[], int tamPROD)
{
    int j, flag = 0;

    system("cls");

    for(j=0; j<tamPROD; j++)
    {
        if(listaPROD[j].idProv && listaPROV[j].idProv && listaPROD[j].estado == 1 && listaPROD[j].cantidad > 10)
        {
            printf("Proveedor: %s\tProducto: %s\tCantidad: %d\tImporte: %.2f\n\n", listaPROV[j].descripcion, listaPROD[j].descripcion, listaPROD[j].cantidad, listaPROD[j].importe);

            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay datos con esa descripcion.\n\n");
    }
    system("pause");
}


