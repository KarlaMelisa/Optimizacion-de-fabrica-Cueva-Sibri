#include <stdio.h>
#include "funciones.h"
#include "string.h"

int ingresoProductos(char nombres[5][80], float tiempo[5], int recursos[5], int *limRecursos){
    int i=0, opc=0;
    int cant=0;
    do{
        printf("-----------------INGRESO DEL PRODUCTO %d:-----------------\nNombre: ",i+1);
        fflush(stdin);
        fgets(nombres[i],80, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
        do{
            printf("Tiempo (en horas): ");
            scanf("%f",&tiempo[i]);
            if (tiempo[i]<0){
                printf("El tiempo no puede ser negativo, por favor ingrese un numero valido ");
                scanf("%f",&tiempo[i]);
            }
        } while (tiempo[i]==0);
        do{
            printf("Cantidad de recursos a utilizar: $");
            scanf("%d",&recursos[i]);
            if (recursos[i]<0){
                printf("El valor no puede ser negativo, por favor ingrese un numero valido \n");
                scanf("%d",&recursos[i]);
            }
        } while (recursos[i]==0);
        printf("Desea ingresar otro producto?\n1.Si\n2.No\n>>");
        scanf("%d",&opc);
        i ++;
        cant ++;
    } while (opc==1);

    printf("---------------INGRESO DE PRESUPUESTO:---------------\n");
    printf("Ingrese el presupuesto: ");
    scanf("%d",&*limRecursos);

    return cant;
}

int menu(int opc2){
    printf("-----------------MENU DE SELECCION:-----------------\n1.Ingreso de productos.\n2.Ingreso de pedido\n3.Modificacion de productos\n4.Salir\n>>");
    scanf("%d",&opc2);
    return opc2;
}

void pedidos(char nombres[5][80], float tiempo[5], int recursos[5], char pedido[80], float *limTiempo, int *limRecursos){
    int cant=0, recursosTotal;
    float tiempoTotal;
    printf("-----------------INGRESO DE PEDIDO:-----------------\nNombre del producto: ");
    fflush(stdin);
    fgets(pedido,80, stdin);
    pedido[strcspn(pedido, "\n")] = '\0';
    printf("Cantidad: ");
    scanf("%d",&cant);
    printf("Limite de tiempo: ");
    scanf("%f",&*limTiempo);
    for (int i = 0; i < 5; i++) {
            if (strcmp(nombres[i], pedido) == 0) {
                int opcion=0;
                tiempoTotal= cant * tiempo[i];
                recursosTotal= cant * recursos[i];
            }
    } 
    float restaT= *limTiempo - tiempoTotal;
    int restaR= *limRecursos - recursosTotal;
    /*printf("Lim tiempo %f\n",*limTiempo);
    printf("Lim recursos %d\n",*limRecursos);

    printf("Resta tiempo %.2f\n",restaT);
    printf("Resta recursos %d\n",restaR);
    return pedido;*/
    printf("----------------------RESULTADOS:----------------------\nEl tiempo total de la produccion del pedido: %.2fh.\nLos recursos totales para la produccion del pedido: $%d\n",tiempoTotal,recursosTotal);
    if (restaT<0){
        printf("El tiempo disponible no es suficiente para la produccion de los productos ingresados por %.2f hora(s).\n",restaT);
    }else {
        printf("El tiempo disponible es suficiente para la produccion de los productos ingresados\n");
    }
    if (restaR<0){
        printf("Los recursos disponibles no son suficientes para la produccion de los productos ingresados por $%d\n",restaR);
    }else {
        printf("Los recursos disponibles son suficientes para la produccion de los productos ingresados\n");
    }
}


int opciones(int opc){
    do{
        printf("------------------MENU DE MODIFICACION DE PRODUCTOS:------------------\n1.Edicion de datos de producto.\n2.Eliminacion de un producto.\n3.Salir\n>>");
        scanf("%d",&opc);
        if (opc!=2 && opc!=1 && opc!=3){
            printf("Ingreso un numero invalido. Seleccione la acción que desea realizar.\n1.Modificacion de datos de producto.\n2.Eliminacion de un producto.\n3.Salir\n>>");
            scanf("%d",&opc);
        }    
    } while (opc==0);
    return opc;
}

void editarProducto(char nombres[5][80], float tiempo[5], int recursos[5], char buscarProducto[80], int cant){
    int validar= 0;
    int opc= 0;  
    do {
        printf("---------------EDICION DE DATOS DE UN PRODUCTO:---------------\nIngrese el nombre del producto que desea modificar: ");
        fflush(stdin);
        fgets(buscarProducto,80, stdin);
        buscarProducto[strcspn(buscarProducto, "\n")] = '\0';  
        for (int i = 0; i < cant; i++) {
            if (strcmp(nombres[i], buscarProducto) == 0) {
                int opcion=0;
                printf("Los datos del producto %s son:\nTiempo: %.2f\nRecursos: $%d\n",buscarProducto,tiempo[i],recursos[i]);
                printf("Que dato desea modificar?\n1.Tiempo\n2.Recursos\n>>");
                scanf("%d",&opcion);
                    if (opcion!=1 && opcion!=2){
                        printf("Ingreso un valor incorrecto, por favor seleccione\n1.Tiempo\n2.Recursos\n>>");
                        scanf("%d", &opcion);
                    }
                switch (opcion){
                    case 1:
                        do{
                            printf("Ingrese el nuevo valor del tiempo: ");
                            scanf("%f",&tiempo[i]);
                            if (tiempo[i]<0){
                                printf("El tiempo no puede ser negativo, por favor ingrese un numero valido: ");
                                scanf("%f",&tiempo[i]);
                            }
                        } while (tiempo[i]==0);
                        break;
                    case 2:
                        do{
                            printf("Ingrese el nuevo valor de recursos: $");
                            scanf("%d",&recursos[i]);
                            if (recursos[i]<0){
                                printf("El valor no puede ser negativo, por favor ingrese un numero valido: $");
                                scanf("%d",&recursos[i]);
                            }
                        } while (recursos[i]==0);
                        break;
                }
                printf("Datos actualizados exitosamente. \nDesea editar otro producto?\n1. Si\n2. No\n>> ");
                scanf("%d", &opc);
                validar = 1;
            }
        }
        if (validar == 0){
            printf("Producto no encontrado. ¿Desea intentar de nuevo?\n1. Si\n2. No\n>>");
            scanf("%d", &opc);
        }
    } while (opc == 1);
}

void eliminarProducto(char nombres[5][80], float tiempo[5], int recursos[5], char buscarProducto[80], int cant){
    int validar= 0;
    int opc= 0;
    do{
        printf("---------------ELIMINACION DE UN PRODUCTO:---------------\nIngrese el nombre del producto que desea eliminar: ");
        fflush(stdin);
        fgets(buscarProducto, 80, stdin);
        buscarProducto[strcspn(buscarProducto, "\n")] = '\0'; // Eliminar salto de línea

        for (int i = 0; i < cant; i++){
            if (strcmp(nombres[i], buscarProducto) == 0){
                validar = 1;
                printf("Producto %s encontrado. ", nombres[i]);
                printf("Esta seguro que desea eliminar este producto?\n1.Si\n2.No\n>> ");
                int confirmacion;
                scanf("%d", &confirmacion);
                if (confirmacion == 1){
                    // Desplazar elementos hacia arriba
                    for (int j = i; j < cant; j++){
                        strcpy(nombres[j], nombres[j + 1]);
                        tiempo[j] = tiempo[j + 1];
                        recursos[j] = recursos[j + 1];
                    }
                    // Limpiar el último elemento
                    strcpy(nombres[cant-1], "");
                    tiempo[cant-1] = 0;
                    recursos[cant-1] = 0;
                    printf("Producto eliminado exitosamente.\n");
                } else { printf("Operacion cancelada.\n");
                }
                break;
            }
        }
    if (!validar) {
        printf("Producto no encontrado.\n");
    }
    } while (opc==1);  
    printf("--------------------LISTA DE PRODUCTOS ACTUALIZADOS--------------------\n");
    for (int i = 0; i < cant; i++){
        printf("PRODUCTO %d:\nNombre: %s\n",i+1, nombres[i]);
    } 
}