#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int JugadaM() {
    return rand() % 3 + 1;
} // Funcion para obtener la jugada de la maquina

int Ganador(int JugadaP, int Maquina){
    if(JugadaP == Maquina){
        return 0; // Valor si sale un empate
    }else if((JugadaP == 1 && Maquina == 3)||(JugadaP == 2 && Maquina == 1)||(JugadaP == 3 && Maquina == 2)){
        return 1; // Valor si el Usuario gana
    }else{
        return -1; // Valor si la maquina gana
    }
} // Funcion para determinar al ganador de cada partida

void Juego(int *t1, int *t2){
    printf("\nEscoja una opcion:\n");
    printf("1 Piedra\n");
    printf("2 Papel\n");
    printf("3 Tijera\n");

    int JugadaP;
    // Solicitar al Jugador que ingrese su opcion y validarla
    do {
        printf("Ingrese una de las opciones: ");
        if (scanf("%d", &JugadaP) != 1 || JugadaP < 1 || JugadaP > 3) {
            printf("Opcion invalida, ingrese una opcion valida.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    int Maquina = JugadaM();
    printf("La maquina escoje: %d\n", Maquina);

    int ganador = Ganador(JugadaP, Maquina);

    if(ganador == 1){
        (*t1)++;
        printf("El jugador gano la ronda.\n");
    }else if(ganador < 0){
        (*t2)++;
        printf("La maquina gano la ronda.\n");
    } else {
        printf("La ronda terminó en empate.\n");
    }// Actualizar los contadores de victorias del jugador y la maquina

}

int main() {
    srand(time(NULL));
    int opcion;
    // Menu de bienvenida
    printf("\nBienvenido/a al campeonato de Piedra, Papel o Tijeras\n");
    printf("Escoja una de las siguientes opciones:\n");
    printf("1) Participar\n");
    printf("2) Reglas\n");
    printf("3) Salir del programa\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

    int t1 = 0, t2 = 0; // Variables para definir al ganador del campeonato
    do {
        switch (opcion) {
            case 1:
                printf("\nComienza el campeonato\n");
                int ganadorCampeonato[6] = {0}; // Array para almacenar los resultados de cada ronda
                for(int ronda = 1; ronda <= 5; ronda++){
                    printf("\nRonda: %d\n", ronda);
                    int empates = 0;
                    for(int partida = 1; partida <= 3; partida++){
                        printf("\nPartida: %d\n", partida);
                        Juego(&t1, &t2);
                    } // Bucle para que se jueguen las 3 partidas
                    //If para obtener y almacenar al ganador de cada ronda
                    if (t1 > t2) {
                        ganadorCampeonato[ronda] = 1; // El jugador gana la ronda
                        printf("\nEl jugador gano la ronda.\n");
                    } else if (t2 > t1) {
                        ganadorCampeonato[ronda] = -1; // La maquina gana la ronda
                        printf("\nLa maquina gano la ronda.\n");
                    } else {
                        empates++;
                        printf("\nLa ronda terminó en empate.\n");
                    }
                    if (empates == 0 && (t1 >= 3 || t2 >= 3)) {
                        break; 
                    } // If para salir si la maquina/jugador gana 3 rondas
                }

                int jugadorG = 0, maquinaG = 0;
                for (int i = 1; i < 5; i++) {
                    if (ganadorCampeonato[i] == 1) {
                        jugadorG++;
                    } else if (ganadorCampeonato[i] == -1) {
                        maquinaG++;
                    }
                } // For para contar el numero de rondas ganadas por el/la jugador/maquina
                //Ifs para mostrar al usuario quien gano el campeonato
                if (jugadorG > maquinaG) {
                    printf("\n¡Felicidades! El jugador es el ganador del campeonato.\n");
                } else if (maquinaG > jugadorG) {
                    printf("\n¡Felicidades! La maquina es el ganador del campeonato.\n");
                } else {
                    printf("\nEl campeonato terminó en empate.\n");
                }
                break;
            case 2:
                printf("\nEl Campeonato constara de 5 rondas\n");
                printf("Cada ronda constara de 3 partidas\n");
                printf("Se debera escojer una de las siguientes opciones:\n");
                printf("Piedra = 1\n");
                printf("Papel = 2\n");
                printf("Tijera = 3\n");
                printf("Ingrese 1 para entrar al Campeonato o 3 para salir: ");
                scanf("%d", &opcion);
                break;
            case 3:
                printf("\nEsperamos que vuelva a participar pronto.\n");
                printf("\n. . . Saliendo del Programa . . .\n");
                break;
            default:
                printf("\n. . . ERROR . . .\n");
                printf("\nEl numero ingresado es invalido\n");
                printf("Porfavor ingrese una opcion valida: ");
                scanf("%d", &opcion);
                break;
        }
    } while (opcion != 3);
}
