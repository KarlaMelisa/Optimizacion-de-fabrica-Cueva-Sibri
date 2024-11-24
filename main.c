#include <stdio.h>
#include "funciones.h"
#include "string.h"

int main (int argc, char *argv[]) {
    char nombres[5][80];
    float tiempo[5];
    int recursos[5];
    char buscarProducto[80];
    char pedido[80];
    float limTiempo, sumaTiempo;
    int limRecursos, sumaRecursos, opc, opc1, opc2, opc3, cant;
    float restaT, tiempoTotal;
    int recursosTotal, restaR;
    
    do{
        opc2=menu(opc2);
        switch (opc2){
        case 1:
            cant= ingresoProductos(nombres, tiempo, recursos, &limRecursos);
            break;
        case 2:
            pedidos(nombres, tiempo, recursos, pedido, &limTiempo, &limRecursos);
        break;
        case 3:
            do{
                opc= opciones(opc);
                switch (opc){
                case 1:
                    editarProducto(nombres, tiempo, recursos, buscarProducto, cant);
                    break;
                case 2:
                    eliminarProducto(nombres, tiempo, recursos, buscarProducto, cant);
                    break;
                case 3:
                    break;
                }
                do{
                    printf("Desea volver al menu de modificacion de productos?\n1.Si\n2.No\n>>");
                    scanf("%d",&opc1);
                    if (opc1!=1 && opc1!=2){
                        printf("Ingrese un numero valido. Desea volver al menu de modificacion de productos?\n1.Si\n2.No\n>>");
                        scanf("%d",&opc1);
                    }
                    if (opc1==2){
                        break;
                    }
                } while (opc1==0);
            } while (opc1==1);
            break;
        case 4:
            break;
        }
        do{
            printf("Desea volver al menu de seleccion?\n1.Si\n2.No(Salir)\n");
            scanf("%d",&opc3);
            if (opc3!=1 && opc3!=2){
                printf("Ingrese un numero valido. Desea volver al menu de modificacion de productos?\n1.Si\n2.No\n");
                scanf("%d",&opc3);
            }
            if (opc1==2){
                break;
            }
        } while (opc3==0);
    } while (opc3==1);
    
    return 0;
}