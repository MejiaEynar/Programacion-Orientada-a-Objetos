#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define f 3
#define c 3

void limpiarPantalla() {
    system("clear || cls");
}

void inicializarTablero(char tablero[f][c]){
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void dibujarTablero(char tablero[f][c], char jugador){
    printf("\n");
    for (int i = 0; i < f; i++) {
       if(jugador = 'X'){
           printf("\x1B[31m %c \x1B[37m|\x1B[37m %c \x1B[37m|\x1B[37m %c \x1B[31m\n", tablero[i][0], tablero[i][1], tablero[i][2]);
        } else{
            printf("\x1B[34m %c \x1B[37m|\x1B[37m %c \x1B[37m|\x1B[37m %c \x1B[34m\n", tablero[i][0], tablero[i][1], tablero[i][2]);
        }
        if (i != f - 1)
            printf("\x1B[37m ---|---|--- \x1B[37m\n");
    }
}

int verificarGanador(char tablero[f][c], char jugador){
    for (int i = 0; i < f; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return 1; 
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return 1; 
    }

    if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
        (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador))
        return 1; 

    return 0; 
}

int tableroCompleto(char tablero[f][c]){
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (tablero[i][j] == ' ')
                return 0; 
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));
    char tablero[f][c];
    int fila, columna;
    char jugador_actual = 'X';
    int op;
    printf("¡Bienvenido al TA TE TI!\n");
    do{
        printf("\nMenú:\n");
        printf("1) Jugar\n");
        printf("2) Reglas\n");
        printf("3) Salir \n");
        printf("Ingrese una opción: ");
        scanf("%d", &op);
        limpiarPantalla();
        switch(op){
            case 1:
                inicializarTablero(tablero);
                printf("\n");
                dibujarTablero(tablero, jugador_actual);
                while (1) {
                    printf("Turno del jugador %c. Ingrese la fila y columna: ", jugador_actual);
                    scanf("%d %d", &fila, &columna);

                    if (fila < 1 || fila > 3 || columna < 1 || columna > 3) {
                        printf("Posición fuera de rango. Inténtelo de nuevo.\n");
                        continue;
                    }

                    if (tablero[fila - 1][columna - 1] == ' ') {
                        tablero[fila - 1][columna - 1] = jugador_actual;
                        limpiarPantalla();
                        dibujarTablero(tablero, jugador_actual);

                        if (verificarGanador(tablero, jugador_actual)) {
                            printf("¡El jugador %c ha ganado!\n", jugador_actual);
                            break;
                        }

                        if (tableroCompleto(tablero)) {
                            printf("¡Empate!\n");
                            break;
                        }

                        jugador_actual = (jugador_actual == 'X') ? 'O' : 'X';
                    } else {
                        printf("Posición ocupada. Inténtelo de nuevo.\n");
                    }
                }

                printf("¿Desea jugar otra vez? (1: Sí / 2: No): ");
                scanf("%d", &op);
                limpiarPantalla();

                break;
            
            case 2:
                printf("Reglas:\n");
                printf("Cada jugador tendra un turno.\n");
                printf("Cada jugador debera ingresar la posicion de su jugada: \n");
                printf("En este orden: Fila Columna X/O \n");
                printf("Una vez echa la jugada no se podra cambiar\n");
                printf("El 1er jugador sera siempre X.\n");
                printf("Se debe ingresar unicamente X/O cualquier otro valor sera tomado como erroneo.\n");
                printf("Y la mas importante: Disfrute el juego ;) \n");
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
    }while(op != 2);
    
}