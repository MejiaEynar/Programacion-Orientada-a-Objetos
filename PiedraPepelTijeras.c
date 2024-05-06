#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int JugadaM() {
    return rand() % 3 + 1;
}

int Ganador(int JugadaP, int Maquina){
    if(JugadaP == Maquina){
        return 0;
    }else if((JugadaP == 1 && Maquina == 3)||(JugadaP == 2 && Maquina == 1)||(JugadaP == 3 && Maquina == 2)){
        return 1;
    }else{
        return -1;
    }
}

void Juego(int *t1, int *t2){
    printf("\nEscoja una opcion:\n");
    printf("1 Piedra\n");
    printf("2 Papel\n");
    printf("3 Tijera\n");

    int JugadaP;
    printf("Ingrese una de las opciones: ");
    scanf("%d", &JugadaP);
    while(JugadaP < 1 || JugadaP > 3){
        printf("Opcion invalida, ingrese una opcion valida: ");
        scanf("%d", &JugadaP);
    }

    int Maquina = JugadaM();
    printf("La maquina escoje: %d\n", Maquina);

    int ganador = Ganador(JugadaP, Maquina);

    if(ganador == 1){
        *t1 = *t1 + 1;
        printf("Felicidades por haber ganado el campeonato!\n");
    }else if(ganador < 0){
        *t2 = *t2 + 1;
        printf("Mejor suerte la próxima.\n");
    } else {
        printf("La ronda terminó en empate.\n");
    }

}

int main() {
    srand(time(NULL));
    int opcion;
    printf("\nBienvenido/a al campeonato de Piedra, Papel o Tijeras\n");
    printf("Escoja una de las siguientes opciones:\n");
    printf("1) Participar\n");
    printf("2) Reglas\n");
    printf("3) Salir del programa\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    int t1 = 0, t2 = 0;
    do {
        switch (opcion) {
            case 1:
                printf("\nComienza el campeonato\n");
                for(int ronda = 1; ronda <= 5; ronda++){
                    printf("\nRonda: %d\n", ronda);
                    int ganador_ronda = 0;
                    for(int partida = 1; partida <= 3; partida++){
                        printf("\nPartida: %d\n", partida);
                        Juego(&t1, &t2);
                        if (t1 >= 2 || t2 >= 2) {
                            if (t1 > t2) {
                                ganador_ronda = 1;
                            } else if (t2 > t1) {
                                ganador_ronda = -1; 
                            }
                            break;
                        }
                    }
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
                printf(". . . Saliendo del Programa . . .\n");
                break;
            default:
                printf(". . . ERROR . . .\n");
                printf("El numero ingresado es invalido\n");
                printf("Porfavor ingrese una opcion valida: ");
                scanf("%d", &opcion);
                break;
        }
    } while (opcion != 3);
    if(opcion == 2) {
        printf("\nEsperamos que vuelva a participar pronto.\n");
    }
}
