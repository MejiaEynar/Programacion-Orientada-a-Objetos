#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void limpiarPantalla() {
    system("clear || cls");
}

int GenerarTablero(int ***tablero, int f, int c, int f_p, int c_p){
    
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
    // Colocar el pirata 'P' en una posición aleatoria dentro del tablero
    (*tablero)[f_p][c_p] = 'P';
    // Colocar el tesoro 'T' en una posición aleatoria que no esté ocupada por el pirata
    int f_tesoro, c_tesoro;
    do {
        f_tesoro = rand() % (f - 2) + 1;
        c_tesoro = rand() % (c - 2) + 1;
    } while ((*tablero)[f_tesoro][c_tesoro] != ' ');
    (*tablero)[f_tesoro][c_tesoro] = 'T';
}

int dibujarTablero(int **tablero, int f, int c, int f_p, int c_p){
    for (int i = 0; i < f; i++) {
        printf("|");
        for (int j = 0; j < c; j++) {
            if (i == f_p && j == c_p) {
                printf("\x1b[47m  \x1b[0m");
            } else if (tablero[i][j] == 'X') {
                printf("\x1b[44m  \x1b[0m");
            } else if (tablero[i][j] == 'T') {
                printf("\x1b[42m  \x1b[0m");
            } else {
                printf("\x1b[42m  \x1b[0m");
            }
        }
        printf("|\n");
    }
    
}

int buscarTesoro(int **tablero, int f, int c, int *f_p, int *c_p, int *movs_r){
    char direccion[10];
    
    while (*movs_r > 0) {
        printf("Ingrese una dirección (norte, sur, este, oeste): ");
        scanf("%s", direccion);

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

        limpiarPantalla();

            (*movs_r)--;
            printf("Movimientos restantes: %d\n", *movs_r);
        
        dibujarTablero(tablero, f, c, *f_p, *c_p);
        
        if (tablero[*f_p][*c_p] == 'T') {
            return 1; // Tesoro encontrado
        }
    }
    return 0; // Tesoro no encontrado
}

int main(){
    srand(time(NULL));
    int f, c; 
    int op;
    int **Matriz = NULL;
    printf("¡Bienvenido al juego del Pirata\n");
    do{
        printf("\nMenú:\n");
        printf("1) Jugar\n");
        printf("2) Salir\n");
        printf("3) Reglas \n");
        printf("Ingrese una opción: ");
        scanf("%d", &op);
        limpiarPantalla();
        switch(op){
            case 1:
                do{
                    printf("\nIngrese el numero de Columnas: ");
                    if (scanf("%d", &c) != 1 || c < 8){
                            limpiarPantalla();
                            printf("\nOpcion invalida, ingrese una opcion valida.\n");
                        while (getchar() != '\n');
                    } else {
                        break;
                    }
                } while (1);
                do{
                    printf("\nIngrese el numero de Filas: ");
                    if (scanf("%d", &f) != 1 || f < 8){
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
                int f_p = rand() % (f - 2) + 1;
                int c_p = rand() % (c - 2) + 1;
                GenerarTablero(&Matriz, f, c, f_p, c_p);
                printf("¿Desea ver el tablero? (1: Sí / 0: No): ");
                int op_tablero;
                scanf("%d", &op_tablero);
                if (op_tablero) {
                    printf("\nTablero:\n");
                    dibujarTablero(Matriz, f, c, f_p, c_p);
                }
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
                break;
            
            case 2:
                printf("\nEsperamos que vuelva a participar pronto.\n");
                printf("\n. . . Saliendo del Programa . . .\n");
                break;
        /*  case 3:
                printf("\nReglas: \n");
                printf("Modo facil: \n");
                printf("Movimientos ""ilimitada"". \n");
                printf("Capacidad de moverse por el agua. \n");
                printf("\nModo dificil: \n");
                printf("Movimientos Limitados \n");
                printf("Penalizacion si se cae en el agua por primera vez \n");
                printf("fin del juego si se cae al agua 3 veces \n");
                break;
        Esta Parte del codigo no esta operativa
        */
            default:
                printf("\n. . . ERROR . . .\n");
                printf("\nEl numero ingresado es invalido\n");
                printf("Porfavor ingrese una opcion valida: ");
                scanf("%d", &op);
                break;
        }
    }while(op != 2);
    if (Matriz != NULL) {
        for (int i = 0; i < f; i++) {
            free(Matriz[i]);
        }
        free(Matriz);
    }
}