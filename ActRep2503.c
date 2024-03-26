#include <stdio.h>
#include <math.h>

void costo(int alu){
    float t;
    if(alu >= 100){
        printf("Cada Alumno debera pagar $500\n");
        t = alu * 500;
        printf("El costo del viaje sera de: %.1f\n", t);
    } else if(alu >= 50 && alu <= 99){
        printf("Cada alumno debera pagar $400\n");
        t = alu * 400;
        printf("El costo del viaje sera de: %.1f\n", t);
    } else if(alu >= 30 && alu <= 49){
        printf("Cada alumno debera pagar $300\n");
        t = alu * 300;
        printf("El costo del viaje sera de: %.1f\n", t);
    } else {
        printf("El costo del viaje sera de: $6000\n");
        t = 6000 / alu;
        printf("Cada alumno debera pagar $%.2f\n", t);
    }
}

int main(void){
    int alu;
    scanf("%d", &alu);
    costo(alu);
    return 0;
}