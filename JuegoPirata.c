#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void limpiarPantalla() {
    system("clear || cls");
}

void GenerarTablero(int ***tablero, int f, int c){
    srand(time(NULL));
    *tablero = (int **)malloc(f * sizeof(int *));
    for (int i = 0; i < f; i++) {
        (*tablero)[i] = (int *)malloc(c * sizeof(int));
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == f - 1 || j == 0 || j == c - 1) {
                (*tablero)[i][j] = 'X';
            } else {
                (*tablero)[i][j] = ' ';
            }
        }
    }
    int f_p = rand() % (f - 2) + 1;
    int c_p = rand() % (c - 2) + 1;
    (*tablero)[f_p][c_p] = 'P';

    int f_tesoro, c_tesoro;
    do {
        f_tesoro = rand() % (f - 2) + 1;
        c_tesoro = rand() % (c - 2) + 1;
    } while ((*tablero)[f_tesoro][c_tesoro] != ' ');
    (*tablero)[f_tesoro][c_tesoro] = 'T';
}

int dibujarTablero(int **tablero, int f, int c, int f_p, int c_p){
    for (int i = 0; i < f; i++) {
        printf("[ ");
        for (int j = 0; j < c; j++) {
            if (i == f_p && j == c_p) {
                printf("P ");
            } else {
                printf("%c ", tablero[i][j]);
            }
        }
        printf("]\n");
    }
}

int buscarTesoro(int **tablero, int f, int c, int *f_p, int *c_p, int *movs_r){
    char direccion[10];
    int fila_anterior = *f_p;
    int columna_anterior = *c_p;

    while (*movs_r > 0) {
        printf("Ingrese una dirección (norte, sur, este, oeste): ");
        scanf("%s", direccion);

        
        fila_anterior = *f_p;
        columna_anterior = *c_p;

        if (strcmp(direccion, "norte") == 0) {
            if (*f_p > 1) {
                (*f_p)--;
            }
        } else if (strcmp(direccion, "sur") == 0) {
            if (*f_p < f - 2) {
                (*f_p)++;
            }
        } else if (strcmp(direccion, "este") == 0) {
            if (*c_p < c - 2) {
                (*c_p)++;
            }
        } else if (strcmp(direccion, "oeste") == 0) {
            if (*c_p > 1) {
                (*c_p)--;
            }
        }

        
        if (tablero[*f_p][*c_p] == 'X') {
            
            if (*movs_r == 50) {
                *movs_r -= 2; 
            } else {
                *movs_r -= 4; 
            }
            printf("¡El pirata ha pisado el agua! Pierdes %d intentos.\n", (*movs_r == 50) ? 2 : 4);
            printf("Movimientos restantes: %d\n", *movs_r);
            dibujarTablero(tablero, f, c, *f_p, *c_p);
            
            *f_p = fila_anterior;
            *c_p = columna_anterior;
        } else {
            (*movs_r)--;
            printf("Movimientos restantes: %d\n", *movs_r);
            dibujarTablero(tablero, f, c, *f_p, *c_p);
        }

        if (tablero[*f_p][*c_p] == 'T') {
            return 1; 
        }
}
}

int main(){
    int f, c; 
    int op, opd;
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
                    if (scanf("%d", &opd) != 1 || f > 2){
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
                printf("El tablero de juego sera de:\n");
                printf("Columnas: %d\n", c);
                printf("Filas: %d\n", f);
                GenerarTablero(&Matriz, f, c);
                printf("¿Desea ver el tablero? (1: Sí / 0: No): ");
                int op_tablero;
                scanf("%d", &op_tablero);
                if (op_tablero) {
                    printf("\nTablero:\n");
                    dibujarTablero(Matriz, f, c, -1, -1);
                }
                switch(opd){
                    case 1:
                        int f_p, c_p;
                        int movs_r = 50;
                        
                        for (int i = 1; i < f - 1; i++) {
                            for (int j = 1; j < c - 1; j++) {
                                if (Matriz[i][j] == 'P') {
                                    f_p = i;
                                    c_p = j;
                                    break;
                                }
                            }
                        }

                        int tesoro = buscarTesoro(Matriz, f, c, &f_p, &c_p, &movs_r);
                        if (tesoro) {
                            printf("¡Has encontrado el tesoro!\n");
                        } else {
                            printf("No has encontrado el tesoro.\n");
                        }
                    case 2:
                        int f_p, c_p;
                        int movs_r = 25;
                        for (int i = 1; i < f - 1; i++) {
                            for (int j = 1; j < c - 1; j++) {
                                if (Matriz[i][j] == 'P') {
                                 f_p = i;
                                    c_p = j;
                                    break;
                                }
                            }
                        }

                        while (movs_r > 0) {
                            printf("\nIntentos restantes: %d\n", movs_r);

                            int tesoro = buscarTesoro(Matriz, f, c,  f_p, &c_p, &movs_r);
                            if (tesoro) {
                                printf("¡Has encontrado el tesoro!\n");
                                break;
                            } else {
                                printf("No has encontrado el tesoro en este intento.\n");
                                movs_r--;
                            }
                        }

                        if (movs_r == 0) {
                            printf("\nSe te han acabado los intentos.\n");
                        }

                        break;
                    }
                    default:
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
    }while(op != 2);
}