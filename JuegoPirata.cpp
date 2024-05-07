#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void iniciarTablero(){}

void dibujarTablero(int c, int f){
    for(int i = 0;i < f; i++){
        printf("[ ");
        for(int j = 0;j < c; j++){
            printf(" # ");
        }
        printf(" ]\n");
    }
}

void BuscarTesoro(){}

int main(){
    srand(time(NULL));
    int f, c;
    printf("\nIngrese el numero de Filas:");
    scanf("%d", &c);
    printf("\nIngrese el numero de Columnas:");
    scanf("%d", &f);
    iniciarTablero(c, f);
    dibujarTablero();
    BuscarTesoro();
    
}