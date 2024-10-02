#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Función para imprimir la matriz Sudoku
void printSudoku(int sudoku[SIZE][SIZE], bool initial[SIZE][SIZE]) {
    printf("   1 2 3   4 5 6   7 8 9\n"); // Imprimir guías para columnas
    printf(" +-------+-------+-------+\n"); // Imprimir línea superior del Sudoku
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0) {
            printf(" +-------+-------+-------+\n"); // Imprimir líneas divisorias entre subcuadros
        }
        printf("%d| ", i + 1); // Imprimir guía para filas
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| "); // Imprimir separadores verticales entre subcuadros
            }
            if (sudoku[i][j] == 0) {
                if (initial[i][j]) {
                    printf(". "); // Imprimir punto si la celda es inicial (números fijos)
                } else {
                    printf("  "); // Imprimir espacio si la celda es modificable
                }
            } else {
                printf("%d ", sudoku[i][j]); // Imprimir número en la celda si está lleno
            }
        }
        printf("|\n"); // Imprimir borde derecho del Sudoku
    }
    printf(" +-------+-------+-------+\n"); // Imprimir línea inferior del Sudoku
}

// Función para verificar si se puede poner un número en una posición específica
bool canPlace(int sudoku[SIZE][SIZE], int row, int col, int num) {
    // Verificar fila
    for (int x = 0; x < SIZE; x++) {
        if (sudoku[row][x] == num) {
            return false; // Si el número ya está en la fila, retornar falso
        }
    }
    // Verificar columna
    for (int x = 0; x < SIZE; x++) {
        if (sudoku[x][col] == num) {
            return false; // Si el número ya está en la columna, retornar falso
        }
    }
    // Verificar subcuadro 3x3
    int startRow = row - row % 3; // Calcular el inicio de la fila del subcuadro
    int startCol = col - col % 3; // Calcular el inicio de la columna del subcuadro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false; // Si el número ya está en el subcuadro, retornar falso
            }
        }
    }
    return true; // Si el número puede ser colocado, retornar verdadero
}

// Función para resolver el Sudoku
bool solveSudoku(int sudoku[SIZE][SIZE], bool initial[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return true; // Si se ha resuelto todo el Sudoku, retornar verdadero
    }
    
    int nextRow, nextCol;
    if (col == SIZE - 1) {
        nextRow = row + 1; // Si se alcanzó el final de la fila, pasar a la siguiente fila
        nextCol = 0; // La siguiente columna es la primera
    } else {
        nextRow = row; // Quedarse en la misma fila
        nextCol = col + 1; // Mover a la siguiente columna
    }
    
    if (initial[row][col]) {
        return solveSudoku(sudoku, initial, nextRow, nextCol); // Si la celda es inicial, pasar a la siguiente
    }
    
    // Probar números del 1 al 9
    for (int num = 1; num <= 9; num++) {
        if (canPlace(sudoku, row, col, num)) {
            sudoku[row][col] = num; // Colocar el número en la celda
            
            if (solveSudoku(sudoku, initial, nextRow, nextCol)) {
                return true; // Si se resuelve el Sudoku, retornar verdadero
            }
            
            sudoku[row][col] = 0; // Si no se puede resolver, deshacer y probar otro número (backtracking)
        }
    }
    return false; // No se puede resolver el Sudoku para ningún número, retornar falso
}

// Función para generar un Sudoku aleatorio con dificultad seleccionada
void generateRandomSudoku(int sudoku[SIZE][SIZE], bool initial[SIZE][SIZE], int numToRemove) {
    // Inicializar la semilla para los números aleatorios
    srand(time(NULL));
    
    // Rellenar la matriz con números aleatorios
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            initial[i][j] = false; // Inicialmente todas las celdas son modificables
            sudoku[i][j] = 0; // Inicialmente todas las celdas están vacías
        }
    }
    
    // Resolver el Sudoku para obtener una solución válida
    solveSudoku(sudoku, initial, 0, 0);
    
    // Quitar algunos números para crear un Sudoku inicial aleatorio
    int removedCount = 0;
    while (removedCount < numToRemove) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (!initial[row][col]) {
            initial[row][col] = true; // Marcar la celda como inicial (número fijo)
            sudoku[row][col] = 0; // Vaciar la celda
            removedCount++;
        }
    }
}

// Función para verificar si el Sudoku está completado
bool isSudokuComplete(int sudoku[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku[i][j] == 0) {
                return false; // Si hay una celda vacía, el Sudoku no está completo
            }
        }
    }
    return true; // Si no hay celdas vacías, el Sudoku está completo
}

// Función para validar la entrada del usuario
bool isValidInput(int sudoku[SIZE][SIZE], int row, int col, int num) {
    if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
        return false; // Si las coordenadas están fuera del rango, retornar falso
    }
    row--; // Convertir la fila a índice (0-8)
    col--; // Convertir la columna a índice (0-8)
    if (num < 1 || num > 9) {
        return false; // Si el número está fuera del rango, retornar falso
    }
    if (sudoku[row][col] != 0) {
        return false; // Si la celda no está vacía, retornar falso
    }
    return canPlace(sudoku, row, col, num); // Verificar si se puede colocar el número en la celda
}

// Función para elegir la dificultad
int chooseDifficulty() {
    int choice;
    printf("Elige la dificultad:\n");
    printf("1. Fácil\n");
    printf("2. Intermedia\n");
    printf("3. Difícil\n");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int sudoku[SIZE][SIZE]; // Declarar matriz para el Sudoku
    bool initial[SIZE][SIZE]; // Declarar matriz para las celdas iniciales (números fijos)
    
    // Mensaje de bienvenida y elección de dificultad
    printf("Bienvenido al juego de Sudoku.\n");
    int difficulty = chooseDifficulty();
    
    int numToRemove;
    switch (difficulty) {
        case 1:
            numToRemove = rand() % 10 + 30; // Entre 30 y 39 números
            break;
        case 2:
            numToRemove = rand() % 10 + 40; // Entre 40 y 49 números
            break;
        case 3:
            numToRemove = rand() % 10 + 50; // Entre 50 y 59 números
            break;
        default:
            numToRemove = rand() % 10 + 40; // Por defecto, intermedia
    }
    
    generateRandomSudoku(sudoku, initial, numToRemove); // Generar Sudoku aleatorio con la dificultad seleccionada
    
    // Instrucciones para el usuario
    printf("Instrucciones: Ingresa la fila, columna y número que deseas colocar (separados por espacios).\n");
    printf("Ejemplo: '3 5 7' coloca el número 7 en la fila 3, columna 5.\n\n");
        
    // Ciclo principal del juego
    while (!isSudokuComplete(sudoku)) { // Mientras el Sudoku no esté completo
        printSudoku(sudoku, initial); // Imprimir el estado actual del Sudoku
        int row, col, num;
        printf("Ingresa la fila, columna y número (1-9): ");
        scanf("%d %d %d", &row, &col, &num); // Leer la entrada del usuario
        
        // Validar la entrada del usuario
        if (isValidInput(sudoku, row, col, num)) {
            sudoku[row - 1][col - 1] = num; // Colocar el número en la celda
        } else {
            printf("Movimiento no válido. Intenta de nuevo.\n"); // Mensaje de error si la entrada no es válida
        }
    }
    
    // Mensaje de felicitaciones al completar el Sudoku
    printf("¡Felicidades! Has completado el Sudoku.\n");
    printSudoku(sudoku, initial); // Mostrar el Sudoku completo
    
    return 0; // Salir del programa
}

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>  // Para _kbhit() y _getch()
#include <windows.h>  // Para Sleep()

using namespace std;

const int width = 60;
const int height = 20;
int birdX = width / 3;
int birdY = height / 2;
int birdVelocity = 0;
bool gameOver = false;
int score = 0;
int tubeGap = 6;
int tubeWidth = 5;
int tubePosition = width - tubeWidth - 1;

void Draw()
{
    system("cls");  
    
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
                cout << "|";
            else if ((j == tubePosition || j == tubePosition + 1 || j == tubePosition + 2 || j == tubePosition + 3 || j == tubePosition + 4) && (i <= tubeGap || i >= tubeGap + 3))
                cout << "|";  // Tubos representados con 'l'
            else if (i == birdY && j == birdX)
                cout << "V";  // Pájaro representado con 'V'
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        char current = _getch();
        if (current == ' ')
            birdVelocity = -1;
    }
}

void Logic()
{
    birdY += birdVelocity;
    birdVelocity += 1;

    // Colisión con los bordes
    if (birdY <= 0 || birdY >= height - 1)
    {
        gameOver = true;
        return;
    }

    // Movimiento de los tubos
    tubePosition--;
    if (tubePosition == 0)
    {
        tubePosition = width - tubeWidth - 1;
        score++;
    }

    // Colisión con los tubos
    if ((birdX >= tubePosition && birdX <= tubePosition + tubeWidth - 1) && (birdY <= tubeGap || birdY >= tubeGap + 3))
    {
        gameOver = true;
        return;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        // Ajusta la velocidad del juego
        Sleep(0.5);  // Espera 200 milisegundos
    }

    system("cls");
    cout << "Game Over!" << endl;
    cout << "Score: " << score << endl;

    return 0;
}

*/