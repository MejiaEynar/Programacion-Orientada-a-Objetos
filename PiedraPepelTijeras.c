#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;
    printf("Bienvenido/a al campeonato de Piedra, Papel o Tijeras\n");
    printf("Escoja una de las siguientes opciones:\n");
    printf("1) Participar\n");
    printf("2) Reglas\n");
    printf("3) Salir del programa\n");
    scanf("%d", &opcion);
    do {
        switch (opcion) {
            case 1:
            case 2:
                printf("El Campeonato constara de 5 rondas\n");
                printf("Cada ronda constara de 3 vueltas\n");
                printf("Se debera escojer una de las siguientes opciones:\n");
                printf("Piedra = 1\n");
                printf("Papel = 2\n");
                printf("Tijera = 3\n");
                break;
            case 3:
                printf(". . . Saliendo del Programa . . .\n");
                break;
            default:
                printf(". . . ERROR . . .\n");
                printf("El numero ingresado es invalido\n");
                printf("Porfavor ingrese una opcion valida:");
                scanf("%d", &opcion);
        }
    } while (opcion != 3);
}
