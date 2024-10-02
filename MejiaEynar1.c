// Eynar Misal Mejia Calsina. Copilador usado: OnlineGDB
#include <stdio.h>
#include <stdlib.h>
#define PrecioChocolate 250
#define PrecioDulcedeLeche 200
#define PrecioFruta 150
#define caja 6

int Calculos(int operario, int cantidadvendida, int tipo){
    int t, t1, t2, t3, error, entrega;
    if(operario != 0){
        if((cantidadvendida % caja) == 0){
            if(tipo == 1){
                t = (cantidadvendida / caja) * PrecioChocolate;
                entrega = entrega + 1;
                printf("El ganacia es: %d\n", t);
            } else if(tipo == 2){
                t1 = (cantidadvendida / caja) * PrecioDulcedeLeche;
                entrega = entrega + 1;
                printf("El ganacia es: %d\n", t1);
            } else if(tipo == 3){
                t2 = (cantidadvendida / caja) * PrecioFruta;
                entrega = entrega + 1;
                printf("El ganacia es: %d\n", t2);
            } else {
                printf("Entrada no valida\n");
            }
        } else {
            if(tipo == 1){
                t = (cantidadvendida / caja) * PrecioChocolate;
                entrega = entrega + 1;
                error = error + 1;
                printf("El ganacia es: %d\n", t);
            } else if(tipo == 2){
                t1 = (cantidadvendida / caja) * PrecioDulcedeLeche;
                entrega = entrega + 1;
                error = error + 1;
                printf("El ganacia es: %d\n", t1);
            } else if(tipo == 3){
                t2 = (cantidadvendida / caja) * PrecioFruta;
                entrega = entrega + 1;
                error = error + 1;
                printf("El ganacia es: %d\n", t2);
            } else {
                printf("Entrada no valida\n");
            }
        }
    
    }
}


int main(){
    char *Tipo[3] = {
        "Chocolate",
        "Dulce de Leche",
        "Frutas"
        };
    
    int operario, cantidadvendida, op, tipo;
    printf("Ingrese una opcion:\n");
    printf("1) Iniciar\n");
    printf("2) Finalizar\n");
    scanf("%d", &op);
    switch(op){
        case 1:
        printf("Ingrese el numero de usuario (1-6): ");
            scanf("%d", &operario);
            printf("Ingrese la cantidad vendida: ");
            scanf("%d", &cantidadvendida);
            printf("Ingrese el tipo de alfajor:\n ");
            printf("1 Chocolate\n ");
            printf("2 dulce de leche\n ");
            printf("3 fruta\n ");
            scanf("%d", &tipo);
            Calculos(operario, cantidadvendida, tipo);
            break;
        case 2:
            printf("Programa Finalizado\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }
}