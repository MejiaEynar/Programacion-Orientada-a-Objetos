#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILAS 10
#define COLUMNAS 10
#define MAX_POZOS 10
#define MAX_CAIDAS 3

void limpiarPantalla() {
    system("clear || cls");  // Limpiar la pantalla
}

void generarPozos(int **tablero) {
    int pozos_colocados = 0;
    while (pozos_colocados < MAX_POZOS) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
        if (tablero[fila][columna] == 1 && (fila != 0 || columna != 0)) {
            tablero[fila][columna] = 0;  // Colocar un pozo en el tablero
            pozos_colocados++;
        }
    }
}

void dibujarTablero(int **tablero, int fila_p, int columna_p, int vidas) {
    printf("\nTablero:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == fila_p && j == columna_p) {
                printf("\x1b[47m  \x1b[0m");  // Posición del jugador
            } else if (tablero[i][j] == 1) {
                printf("\x1b[42m  \x1b[0m");  // Celda vacía
            } else if (tablero[i][j] == 0) {
                printf("\x1b[44m  \x1b[0m");  // Pozo
            }
        }
        printf("\n");
    }
    printf("Vidas restantes: %d\n", vidas);  // Mostrar vidas restantes
}

int moverJugador(int **tablero, int *fila_p, int *columna_p, int *vidas) {
    char direccion[10];
    printf("\nIngrese una dirección (norte, sur, este, oeste): ");
    scanf("%s", direccion);

    int nueva_fila = *fila_p;
    int nueva_columna = *columna_p;

    if (strcmp(direccion, "norte") == 0) {
        nueva_fila = *fila_p - 1;
    } else if (strcmp(direccion, "sur") == 0) {
        nueva_fila = *fila_p + 1;
    } else if (strcmp(direccion, "este") == 0) {
        nueva_columna = *columna_p + 1;
    } else if (strcmp(direccion, "oeste") == 0) {
        nueva_columna = *columna_p - 1;
    } else {
        printf("Dirección no válida.\n");
        return 0;  // Movimiento no válido
    }

    if (nueva_fila < 0 || nueva_fila >= FILAS || nueva_columna < 0 || nueva_columna >= COLUMNAS) {
        printf("Fuera de los límites del tablero.\n");
        return 0;  // Movimiento fuera de los límites
    }

    if (tablero[nueva_fila][nueva_columna] == 0) {
        (*vidas)--;
        if (*vidas == 0) {
            printf("¡Caidas al pozo 3 veces! Has perdido.\n");
            return -1;  // Juego perdido
        } else {
            printf("¡Caíste en un pozo! Vidas restantes: %d\n", *vidas);
            return 0;  // Caída en un pozo
        }
    }

    *fila_p = nueva_fila;
    *columna_p = nueva_columna;

    return 1;  // Movimiento válido
}

int main() {
    srand(time(NULL));  // Inicializar la semilla para los números aleatorios
    int **tablero;
    int fila_p, columna_p;
    int vidas = MAX_CAIDAS;
    
    // Inicializar tablero
    tablero = (int **)malloc(FILAS * sizeof(int *));
    for (int i = 0; i < FILAS; i++) {
        tablero[i] = (int *)malloc(COLUMNAS * sizeof(int));
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = 1;  // Llenar con celdas vacías
        }
    }

    // Generar pozos aleatoriamente
    generarPozos(tablero);

    // Iniciar jugador en posición 0,0 sin pozo
    fila_p = 0;
    columna_p = 0;

    // Juego
    while (fila_p != FILAS - 1 || columna_p != COLUMNAS - 1) {
        limpiarPantalla();
        dibujarTablero(tablero, fila_p, columna_p, vidas);
        int movimiento = moverJugador(tablero, &fila_p, &columna_p, &vidas);
        if (movimiento == -1) {
            break;  // Salir del juego si se perdió
        }
    }

    limpiarPantalla();
    if (fila_p == FILAS - 1 && columna_p == COLUMNAS - 1) {
        printf("¡Felicidades, has llegado a la posición [9][9] con vida!\n");
    }
    
    // Liberar memoria
    for (int i = 0; i < FILAS; i++) {
        free(tablero[i]);
    }
    free(tablero);

    return 0;  // Salir del programa
}
