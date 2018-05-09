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

void setProductoStatus(EProducto productoArray[], int arrayTamaño, int value);
int findProductoEmptyPlace(EProducto productoArray[],int arrayTamaño);
int findProductoByCode(EProducto productoArray[],int arrayTamaño,int code);
void setProducto(EProducto productoArray[],int freePlaceIndex, int codeAux,char titleAux[], int proveedorIdAux,int stockAux);
void showProductoArray(EProducto productoArray[],int arrayTamaño);
void orderProductoArrayByTitle(EProducto productoArray[],int arrayTamaño);

void setProveedorStatus(EProveedor proveedorArray[],int arrayTamaño,int value);
int findProveedorEmptyPlace(EProveedor proveedorArray[],int arrayTamaño);
int findPrveedorById(EProveedor proveedorArray[],int arrayTamaño,int proveedorIdAux);
void setProveedor(EProveedor proveedorArray[],int freePlaceIndex, int proveedorIdAux,char nameAux[]);
void showProveedorArray(EProveedor proveedorArray[],int arrayTamaño);

void showProductoProveedorArray(EProducto productoArray[],int arrayTamaño,EProveedor proveedorArray[],int authorArrayLenght);
void modificaProducto(EProducto vec[], int tam);
int menuModifica();
#endif // FUNCIONES_H_INCLUDED
