#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpiarPantalla() {
    system("clear || cls");
}

int dibujarTablero(int c, int f){
    for(int i = 0;i < f; i++){
        printf("[ ");
        for(int j = 0;j < c; j++){
            printf(" # ");
        }
        printf(" ]\n");
    }
}

int main(){
    srand(time(NULL));
    int f, c, op;
    int Matriz[f][c];
    scanf("%d", &op);
    do{
    switch(op){
        case 1:
            do{
                printf("\nIngrese el numero de Columnas: ");
                if (scanf("%d", &c) != 1 || c < 4){
                        limpiarPantalla();
                        printf("\nOpcion invalida, ingrese una opcion valida.\n");
                    while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
            do{
                printf("\nIngrese el numero de Filas: ");
                if (scanf("%d", &f) != 1 || f < 4){
                        limpiarPantalla();
                        printf("\nOpcion invalida, ingrese una opcion valida.\n");
                    while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
            limpiarPantalla();
            printf("El tablero de juego sera de:\n");
            printf("Columnas: %d\n", c);
            printf("Filas: %d\n", f);
            dibujarTablero(c,f);
            break;
        case 2:
            
            break;
        case 3:
            printf("\nEsperamos que vuelva a participar pronto.\n");
            printf("\n. . . Saliendo del Programa . . .\n");
            break;
        default:
            printf("\n. . . ERROR . . .\n");
            printf("\nEl numero ingresado es invalido\n");
            printf("Porfavor ingrese una opcion valida: ");
            scanf("%d", &op);
            break;
    }
    }while(op != 3);
}