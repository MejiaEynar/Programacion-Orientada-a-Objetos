// El codigo se debe copilar en onlineGDB
// Tema: 7

#include <stdio.h>
#include <stdlib.h>
#define RESET   "\x1b[0m"
#define ROJO    "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define F10 10
#define C10 6
#define F4 4
#define C3 3
#define AD 15
#define D 4

int matrizO[F10][C10];
int matrizM[F10][C10];
int matriz[F4][C3];
int notas[D][AD];

void limpiar(){
    system("clear || cls");
}

void crearMatriz1() {
    for (int i = 0; i < F10; i++) {
        for (int j = 0; j < C10; j++) {
            printf(VERDE"Ingrese los Matriz[%d][%d] números de la matriz:\n"RESET, i + 1, j + 1);
            scanf("%d", &matrizO[i][j]);
        }
    }
}

void modificarMatriz1() {
    for (int i = 0; i < F10; i++) {
        for (int j = 0; j < C10; j++) {
            if (j % 2 == 0) {
                matrizM[i][j] = matrizO[i][j] * matrizO[i][j] * matrizO[i][j];
            } else {
                matrizM[i][j] = matrizO[i][j] * matrizO[i][j];
            }
        }
    }
}

void mostrarMatrices1() {
    printf(VERDE"\nMatriz Original:\n"RESET);
    for (int i = 0; i < F10; i++) {
        printf("[ ");
        for (int j = 0; j < C10; j++) {
            printf("%d ", matrizO[i][j]);
        }
        printf("]\n");
    }

    printf("\nMatriz Modificada:\n");
    for (int i = 0; i < F10; i++) {
        printf("[ ");
        for (int j = 0; j < C10; j++) {
            printf("%d ", matrizM[i][j]);
        }
        printf("]\n");
    }
}

void crearMatriz2() {
    printf(VERDE"Ingrese 12 números para llenar la matriz 4x3:\n"RESET);
    for (int i = 0; i < F4; i++) {
        for (int j = 0; j < C3; j++) {
            printf(VERDE"Ingrese el número para la posición [%d][%d]: "RESET, i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz2() {
    printf(AMARILLO"\nMatriz 4x3:\n"RESET);
    for (int i = 0; i < F4; i++) {
        printf("[ ");
        for (int j = 0; j < C3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("]\n");
    }
}
void Calculos() {
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;
    int sumaPrimeraFila = 0;
    int sumaUltimaFila = 0;
    int sumaPrimeraColumna = 0;
    int sumaUltimaColumna = 0;

    for (int i = 0; i < F4; i++) {
        sumaDiagonalPrincipal += matriz[i][i];
    }

    for (int i = 0; i < F4; i++) {
        sumaDiagonalSecundaria += matriz[i][C3 - 1 - i];
    }

    for (int j = 0; j < C3; j++) {
        sumaPrimeraFila += matriz[0][j];
    }

    for (int j = 0; j < C3; j++) {
        sumaUltimaFila += matriz[F4 - 1][j];
    }

    for (int i = 0; i < F4; i++) {
        sumaPrimeraColumna += matriz[i][0];
    }

    for (int i = 0; i < F4; i++) {
        sumaUltimaColumna += matriz[i][C3 - 1];
    }

    printf(AMARILLO"\nResultados:\n"RESET);
    printf(VERDE"Suma Diagonal Principal: %d\n"RESET, sumaDiagonalPrincipal);
    printf(VERDE"Suma Diagonal Secundaria: %d\n"RESET, sumaDiagonalSecundaria);
    printf(VERDE"Suma Primera Fila: %d\n"RESET, sumaPrimeraFila);
    printf(VERDE"Suma Última Fila: %d\n"RESET, sumaUltimaFila);
    printf(VERDE"Suma Primera Columna: %d\n"RESET, sumaPrimeraColumna);
    printf(VERDE"Suma Última Columna: %d\n"RESET, sumaUltimaColumna);
}

void ingresarnotas() {
    printf(VERDE"Ingrese las notas de informática para %d alumnos por división:\n"RESET, AD);
    for (int d = 0; d < D; d++) {
        printf(AMARILLO"Division %d:\n"RESET, d + 1);
        for (int a = 0; a < AD; a++) {
            printf(AMARILLO"Nota del alumno %d: "RESET, a + 1);
            scanf("%d", &notas[d][a]);
        }
    }
}

void calcularPromedioNotas() {
    printf(AMARILLO"\nPromedio de notas por división:\n"RESET);
    for (int d = 0; d < D; d++) {
        int suma = 0;
        for (int a = 0; a < AD; a++) {
            suma += notas[d][a];
        }
        double promedio = (double)suma / AD;
        printf(VERDE"División %d: %.2f\n"RESET, d + 1, promedio);
    }
}

int encontrarMayorNota() {
    int mayorNota = -1;
    for (int d = 0; d < D; d++) {
        for (int a = 0; a < AD; a++) {
            if (notas[d][a] > mayorNota) {
                mayorNota = notas[d][a];
            }
        }
    }
    return mayorNota;
}

void imprimirTodasLasNotas() {
    printf(AMARILLO"\nNotas de informática de todos los alumnos:\n"RESET);
    for (int d = 0; d < D; d++) {
        printf(AMARILLO"División %d:\n"RESET, d + 1);
        for (int a = 0; a < AD; a++) {
            printf("%d ", notas[d][a]);
        }
        printf("\n");
    }
}

void contarAprobadosReprobados() {
    printf(ROJO"\nAprobados y Reprobados por división:\n"RESET);
    for (int d = 0; d < D; d++) {
        int aprobados = 0;
        int reprobadors = 0;
        for (int a = 0; a < AD; a++) {
            if (notas[d][a] >= 60) {
                aprobados++;
            } else {
                reprobadors++;
            }
        }
        printf(ROJO"División %d: Aprobados = %d, Reprobados = %d\n"RESET, d + 1, aprobados, reprobadors);
    }
}

int main() {
    int opcion;
    int mayorNota;

    do {
        printf(AMARILLO"\nMenu de opciones:\n"RESET);
        printf(AMARILLO"1. Punto 1\n"RESET);
        printf(AMARILLO"2. Punto 2\n");
        printf(AMARILLO"3. Punto 3\n"RESET);
        printf(AMARILLO"4. Salir\n"RESET);
        printf(VERDE"Ingrese su opción: "RESET);
        scanf("%d", &opcion);
        limpiar();
        switch (opcion) {
            case 1:
                printf(AMARILLO"\nMenu de operaciones con Matriz[10][6]:\n"RESET);
                printf(AMARILLO"1. Crear Matriz\n"RESET);
                printf(AMARILLO"2. Modificar Matriz\n"RESET);
                printf(AMARILLO"3. Mostrar Matrices\n"RESET);
                printf(AMARILLO"Ingrese su opción: "RESET);
                scanf("%d", &opcion);
                limpiar();
                switch (opcion) {
                case 1:
                    crearMatriz1();
                    break;
                case 2:
                    modificarMatriz1();
                    break;
                case 3:
                    mostrarMatrices1();
                    break;
                default:
                    printf(ROJO"Opción no válida\n"RESET);
                }
    
                break;

            case 2:
                printf(AMARILLO"\nMenu de operaciones con Matriz[4][3]:\n"RESET);
                printf(AMARILLO"1. Crear Matriz\n"RESET);
                printf(AMARILLO"2. Mostrar Matriz\n"RESET);
                printf(AMARILLO"3. Calculos\n"RESET);
                printf(VERDE"Ingrese su opción: "RESET);
                scanf("%d", &opcion);
                limpiar();
                switch (opcion) {
                    case 1:
                        crearMatriz2();
                        break;
                    case 2:
                        mostrarMatriz2();
                        break;
                    case 3:
                        Calculos();
                        break;
                    default:
                        printf(ROJO"Opción no válida\n"RESET);
                }
                break;

            case 3:
                printf(AMARILLO"\nMenu de operaciones con Notas de Informática:\n"RESET);
                printf(AMARILLO"1. Ingresar Notas de Informática\n"RESET);
                printf(AMARILLO"2. Calcular y Mostrar Promedio de Notas\n"RESET);
                printf(AMARILLO"3. Mostrar Mayor Nota en General\n"RESET);
                printf(AMARILLO"4. Mostrar Todas las Notas\n"RESET);
                printf(AMARILLO"5. Contar Aprobados y Reprobados por División\n"RESET);
                printf(VERDE"Ingrese su opción: "RESET);
                scanf("%d", &opcion);
                limpiar();
                switch (opcion) {
                    case 1:
                        ingresarnotas();
                        break;
                    case 2:
                        calcularPromedioNotas();
                        break;
                    case 3:
                        mayorNota = encontrarMayorNota();
                        printf(VERDE"\nMayor nota en general: %d\n"RESET, mayorNota);
                        break;
                    case 4:
                        imprimirTodasLasNotas();
                        break;
                    case 5:
                        contarAprobadosReprobados();
                        break;
                    default:
                        printf(ROJO"Opción no válida\n"RESET);
                }
                break;

            case 4:
                limpiar();
                printf(ROJO"Saliendo...\n"RESET);
                printf(ROJO"Gracias por participar :)\n"RESET);
                break;

            default:
                limpiar();
                printf(ROJO"Opción no válida\n"RESET);
        }
    } while (opcion != 4);
}
