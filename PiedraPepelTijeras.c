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

void Juego(){
    printf("Escoja una opcion:\n");
    printf("1 Piedra\n");
    printf("2 Papel\n");
    printf("3 Tijera\n");

    int JugadaP;
    printf("Ingrese una de las opciones:");
    scanf("%d", &JugadaP);
    while(JugadaP < 1 || JugadaP > 3){
        printf("Opcion invalida, ingrese una opcion valida:");
        scanf("%d", &JugadaP);
    }

    int Maquina = JugadaM();
    printf("La maquina escoje: %d\n", Maquina);
    int t1, t2, t3;
    int ganador = Ganador(JugadaP, Maquina);
    if(ganador == 1){
        t1 = t1 + 1;
    }else if(ganador < 0){
        t2 = t2 + 1;
    }
    
    if(ganador == 0){
        printf("La ronda termino en empáte\n");
    }else if(ganador == 1){
        printf("Tu ganaste esta ronda\n");
    }else{
        printf("La maquina gana esta ronda\n");
    }

    if(t1 > 7 && t2 <= 7){
        printf("Tu eres el ganador del campeonato\n");
    }else if(t1 >= 7 && t2 > 7){
        printf("La maquina es la ganadora del campeonato\n");
        
    }else{
        printf("El campeonato termino en empate\n");
    }

}

int main() {
    srand(time(NULL));
    int opcion;
    printf("Bienvenido/a al campeonato de Piedra, Papel o Tijeras\n");
    printf("Escoja una de las siguientes opciones:\n");
    printf("1) Participar\n");
    printf("2) Reglas\n");
    printf("3) Salir del programa\n");
    printf("Ingrese la opcion:");
    scanf("%d", &opcion);
    do {
        switch (opcion) {
            case 1:
                printf("\nComienza el campeonato\n");
                for(int ronda = 1; ronda <= 5; ronda++){
                    printf("\nRonda: %d\n", ronda);
                    for(int partida = 1; partida <= 3; partida++){
                        printf("\nPartida: %d\n", partida);
                        Juego();
                    }
                }
            case 2:
                printf("El Campeonato constara de 5 rondas\n");
                printf("Cada ronda constara de 3 partidas\n");
                printf("Se debera escojer una de las siguientes opciones:\n");
                printf("Piedra = 1\n");
                printf("Papel = 2\n");
                printf("Tijera = 3\n");
                printf("Ingrese 1 para entrar al Campeonato o 3 para salir:");
                scanf("%d", &opcion);
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
