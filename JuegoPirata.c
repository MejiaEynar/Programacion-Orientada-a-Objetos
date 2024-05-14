#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void limpiarPantalla() {
    system("clear || cls");
}

void GenerarTablero(){
    srand(time(NULL));
}

int dibujarTablero(int **tablero, int f, int c, int f_p, int c_p){
}

int main(){
    int f, c, op;
    int **Matriz = NULL;
    printf("¡Bienvenido al juego del Pirata\n");
    do{
        printf("\nMenú:\n");
        printf("1) Jugar\n");
        printf("2) Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &op);
        limpiarPantalla();
        switch(op){
            case 1:
                printf("1. Normal\n");
                printf("2. Difícil\n");
                do{
                    printf("\nSeleccione la dificultad: ");
                    if (scanf("%d", &f) != 1 || f > 2){
                            limpiarPantalla();
                            printf("1. Normal\n");
                            printf("2. Difícil\n");
                            printf("\nOpcion invalida, ingrese una opcion valida.\n");
                        while (getchar() != '\n');
                    } else {
                        break;
                    }
                } while (1);
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
                GenerarTablero();
                printf("El tablero de juego sera de:\n");
                printf("Columnas: %d\n", c);
                printf("Filas: %d\n", f);
                printf("¿Desea ver el tablero? (1: Sí / 0: No): ");
                int op_tablero;
                scanf("%d", &op_tablero);
                if (op_tablero) {
                    printf("\nTablero:\n");
                    dibujarTablero(Matriz, f, c, -1, -1);
                }
                break;
            case 2:
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