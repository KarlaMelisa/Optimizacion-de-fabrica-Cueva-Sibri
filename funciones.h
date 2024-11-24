int ingresoProductos(char nombres[5][80], float tiempo[5], int recursos[5], int *limRecursos);
void pedidos(char nombres[5][80], float tiempo[5], int recursos[5], char pedido[80], float *limTiempo, int *limRecursos);
int menu(int opc2);
int opciones(int opc);
void editarProducto(char nombres[5][80], float tiempo[5], int recursos[5], char buscarProducto[80], int cant);
void eliminarProducto(char nombres[5][80], float tiempo[5], int recursos[5], char buscarProducto[80], int cant);