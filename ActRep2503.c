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

void NotaF(float not1, float not2, float not3, float notf, float tpf){
    float promedio = (not1 + not2 + not3) / 3;
    float notaf = (promedio + notf + tpf) / 3;
    printf("La nota final sera de: %.2f\n", notaf);
}

int main(void){
    int alu;
    float not1, not2, not3, notf, tpf;
    int opcion;
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            scanf("%d", &alu);
            costo(alu);
            break;
        case 2:
            
        case 3:
            printf("Ingresar las notas de los 3 parciales\n");
            printf("Luego la nota del examen final y luego del trabajo final\n");
            scanf("%f %f %f %f %f", &not1, &not2, &not3, &notf, &tpf);
            NotaF(not1, not2, not3, notf, tpf);
            break;
        case 4:
    }
    return 0;
}