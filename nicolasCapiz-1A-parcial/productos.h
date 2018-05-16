typedef struct
{
    int idProd;
    char descripcion[51];
    float importe;
    int cantidad;
    int idProv;
    int estado;

}EProducto;

typedef struct
{
    int idProv;
    char descripcion[51];

}EProveedor;

void hardcodeProv(EProveedor lista[]);
void inicializarVariables(EProducto vec[], int tam);
int buscarLibre(EProducto lista[], int tam);
int buscarId(EProducto lista[], int tam, int Id);
void mostrar(EProducto lista, EProveedor proveedores);
int mostrarTodos(EProducto lista[], int tam1, EProveedor proveedores[], int tam2);
void alta(EProducto lista[], int tam, int Id, EProveedor proveedores[]);
void modificacion(EProducto lista[], int tam, EProveedor proveedores[]);
void baja(EProducto lista[], int tam, EProveedor proveedores[]);
void mostrarProveedores(EProveedor lista[], int tam);
void mostrarProveedor(EProveedor lista);

int cantidadStockMenos10(int cantidad, EProducto lista[], int tam);
int cantidadStockMas10(int cantidad, EProducto lista[], int tam);
float acumulador(EProducto lista[], int tam);
float promedio(EProducto lista[], int tam);
int cantidadTotalProductos(EProducto lista[], int tam);
int cantidadProductosSuperanProm(EProducto lista[], int tam);
int cantidadProductosNoSuperanProm(EProducto lista[], int tam);

void mostrarProductosMas10(EProducto lista[]);
void mostrarProductosMenos10(EProducto lista[]);
void mostrarCantidadProductosSuperanPromDes(EProducto lista[], int tam);
void mostrarCantidadProductosNoSuperanPromDes(EProducto lista[], int tam);
void mostrarProveedorConProductoMas10(EProveedor listaPROV[], int tamPROV, EProducto listaPROD[], int tamPROD);
void mostrarCantidadProductosNoSuperanProm(EProducto lista[], int tam);
void mostrarCantidadProductosSuperanProm(EProducto lista[], int tam);
void mostrarProductosMenos10Des(EProducto lista[]);
void mostrarProductosMas10Des(EProducto lista[]);
void productosDeProveedores(EProveedor lista[], EProducto listaP[]);

void buscarProductosDeProveedor(EProveedor lista[], int tam, EProducto listaP[], int tamP);
int cantidadProductosBusqueda(int proveedor, EProducto lista[], int tam);
int maximoProductos(EProveedor lista[], int tam, EProducto lista2[], int tam2);
int minimoProductos(EProveedor lista[], int tam, EProducto lista2[], int tam2);
void proveedorConMasProductos(EProveedor proveedor[], int tamPROV, EProducto productos[], int tamPROD);
void proveedorConMenosProductos(EProveedor proveedor[], int tamPROV, EProducto productos[], int tamPROD);


