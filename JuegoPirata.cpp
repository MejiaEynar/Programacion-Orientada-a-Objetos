#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dibujarTablero(int c, int f){
    for(int i = 0;i < f; i++){
        printf("[ ");
        for(int j = 0;j < c; j++){
            printf(" # ");
        }
        printf(" ]\n");
    }
}

int main(){
    srand(time(NULL));
    int f, c, op;
    int Matriz[f][c];
    scanf("%d", &op);
    do{
    switch(op){
        case 1:
            do{
                printf("\nIngrese el numero de Columnas: ");
                if (scanf("%d", &c) != 1 || c < 1){
                        printf("Opcion invalida, ingrese una opcion valida.\n");
                    while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
            do{
                printf("\nIngrese el numero de Filas: ");
                if (scanf("%d", &f) != 1 || f < 1){
                        printf("Opcion invalida, ingrese una opcion valida.\n");
                    while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
            dibujarTablero(c,f);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    }while(op != 3);
}