#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "libreria.h"
typedef struct{
    char descripcion[51];
    int code;
    int stock;
    int proveedorId;
    int importe;
    int status; /**< Active (1) or Inactive (0)  */
}EProducto;

typedef struct{
    char nombre[51];
    char lastName[51];
    int proveedorId;
    int status; /**< Active (1) or Inactive (0)  */
}EProveedor;

void setProductoStatus(EProducto productoArray[], int arrayTama�o, int value);
int findProductoEmptyPlace(EProducto productoArray[],int arrayTama�o);
int findProductoByCode(EProducto productoArray[],int arrayTama�o,int code);
void setProducto(EProducto productoArray[],int freePlaceIndex, int codeAux,char titleAux[], int proveedorIdAux,int stockAux);
void showProductoArray(EProducto productoArray[],int arrayTama�o);
void orderProductoArrayByTitle(EProducto productoArray[],int arrayTama�o);

void setProveedorStatus(EProveedor proveedorArray[],int arrayTama�o,int value);
int findProveedorEmptyPlace(EProveedor proveedorArray[],int arrayTama�o);
int findPrveedorById(EProveedor proveedorArray[],int arrayTama�o,int proveedorIdAux);
void setProveedor(EProveedor proveedorArray[],int freePlaceIndex, int proveedorIdAux,char nameAux[]);
void showProveedorArray(EProveedor proveedorArray[],int arrayTama�o);

void showProductoProveedorArray(EProducto productoArray[],int arrayTama�o,EProveedor proveedorArray[],int authorArrayLenght);
void modificaProducto(EProducto vec[], int tam);
int menuModifica();
#endif // FUNCIONES_H_INCLUDED
