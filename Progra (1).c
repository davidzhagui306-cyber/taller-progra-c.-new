#include <stdio.h>
#include <stdlib.h>

int main() {
    int ID, stock, restock, ventas, opcion;
    int unidadesV = 0;
    char nombre[50];
    char continuar = 's';
    char venta;
    char oferta;
    float precio;
    float ganancia = 0;
    float gananciaT = 0;
    float descuento;
    while (continuar == 's'){
        printf("-Bienvenido, seleccione lo que desee realizar-\n");
        printf("(1) Registro de datos de producto\n");
        printf("(2) Venta de unidades de producto\n");
        printf("(3) Reabastecimiento de producto\n");
        printf("(4) Información de Producto\n");
        printf("(5) Calculo y muestreo de ganancia\n");
        printf("(6) Salir del programa\n");

        scanf("%d", &opcion);
        while (opcion >= 7 || opcion <= 0){
            printf("Error en lectura\n");
            printf("Ingrese nuevamente\n");
            scanf("%d", &opcion);
        }
        switch (opcion){
            case 1:
                printf("-Ingreso de datos-\n");
                printf("Ingrese ID del producto\n");
                scanf("%d", &ID);
                printf("Registrado!\n");
                printf("\n");
                while ((getchar()) != '\n' && getchar() != EOF);
                printf("Ingrese nombre del producto\n");
                fgets(nombre, sizeof(nombre), stdin);
                printf("Registrado!\n");
                printf("\n");
                printf("Ingrese cantidad en stock\n");
                scanf("%d", &stock);
                while (stock < 0){
                    printf("Cantidad no permitido\n");
                    printf("Ingrese nuevamente\n");
                    scanf("%d", &stock);
                }
                printf("Registrado!\n");
                printf("\n");
                printf("Ingrese precio por unidad\n");
                scanf("%f", &precio);
                while (precio < 0){
                    printf("Precio no permitido\n");
                    printf("Ingrese nuevamente\n");
                    scanf("%f", &precio);
                }
                printf("Registrado!\n");
                printf("\n");
                printf("Ingrese descuento de producto en punto decimal (Ejemplo 20% == 0.8)\n");
                scanf("%f", &descuento);
                while (descuento > 1 || descuento < 0){
                    printf("Descuento no permitido\n");
                    printf("Ingrese nuevamente\n");
                    scanf("%f", &descuento);
                }
                printf("Registrado!\n");
                printf("\n");
                break;
            case 2:
                printf("-Venta de unidades-\n");
                printf("Ingrese la cantidad de unidades que desea vender\n");
                scanf("%d", &ventas);
                while (ventas > stock || ventas < 0){
                    printf("Venta no permitida, excede stock\n");
                    printf("Ingrese nuevamente\n");
                    scanf("%d", &ventas);
                }
                printf("Continuar con la venta? (s o n)\n");
                printf("Cantidad a vender %d\n", ventas);
                scanf(" %c", &venta);
                while (venta != 's' && venta != 'n'){
                    printf("Error en lectura\n");
                    printf("Ingrese nuevamente\n");
                    scanf(" %c", &venta);
                }
                if (venta == 's'){
                    printf("¿Desea añadir el descuento? (s o n)\n");
                    scanf(" %c", &oferta);
                    while (oferta != 's' && oferta != 'n'){
                        printf("Error en lectura\n");
                        printf("Ingrese nuevamente\n");
                        scanf(" %c", &oferta);
                    }
                    if (oferta == 's'){
                        printf("Venta aceptada exitosamente\n");
                        printf("\n");
                        unidadesV = ventas + unidadesV;
                        stock = stock - ventas;
                        ganancia = ventas * precio * descuento;
                        gananciaT = ganancia + gananciaT;
                    }
                    else if (oferta == 'n'){
                        printf("Venta aceptada exitosamente\n");
                        printf("\n");
                        unidadesV = ventas + unidadesV;
                        stock = stock - ventas;
                        ganancia = ventas * precio;
                        gananciaT = ganancia + gananciaT;
                    }
                }
                else if (venta == 'n'){
                    printf("Venta rechazada exitosamente\n");
                    printf("\n");
                }
                break;
            case 3:
                printf("-Reabastecer producto-\n");
                printf("Ingrese la cantidad de unidades que desea añadir al stock\n");
                scanf("%d", &restock);
                while (restock < 0){
                    printf("Cantidad no permitida\n");
                    printf("Ingrese nuevamente\n");
                    scanf("%d", &restock);
                }
                printf("Cantidad añadida exitosamente\n");
                printf("\n");
                stock = stock + restock;
                break;
            case 4:
                printf("-Información de producto-\n");
                printf("ID del producto: %d\n", ID);
                printf("Nombre del producto: %s", nombre);
                printf("Stock del producto: %d\n", stock);
                printf("Precio del producto: %.2f\n", precio);
                printf("Descuento del producto: %.2f\n", descuento);
                printf("\n");
                break;
            case 5:
                printf("-Cálculo y muestreo de ganancia-\n");
                printf("Ventas totales: %d\n", unidadesV);
                printf("Ganancia obtenida: %.2f\n", gananciaT);
                printf("\n");
                break;
            case 6:
                printf("-Saliendo del programa...-\n");
                exit(0);
            }
        printf("Desea continuar? (s o n)\n");
        scanf(" %c", &continuar);
        while (continuar != 's' && continuar != 'n'){
            printf("Error en lectura\n");
            printf("Ingrese nuevamente\n");
            scanf(" %c", &continuar);
        }
        }
    }