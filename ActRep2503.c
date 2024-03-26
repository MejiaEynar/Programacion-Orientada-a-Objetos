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
void SueldoT(float sueldob, float v1, float v2, float v3){
}

void NotaF(float not1, float not2, float not3, float notf, float tpf){
    float promedio = (not1 + not2 + not3) / 3;
    float notaf = (promedio + notf + tpf) / 3;
    printf("La nota final sera de: %.2f\n", notaf);
}
void numPar(int num1, int num2){
    for (int i = num1; i <= num2; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void){
    int alu; // Variable para el ejercicio 1
    float sueldob, v1, v2, v3;
    float not1, not2, not3, notf, tpf; // Variables para el ejercicio 3
    int num1, num2; // Variables para el ejercicio 4
    int opcion;
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            scanf("%d", &alu);
            costo(alu);
            break;
        case 2:
            printf("Ingresar el sueldo base:\n");
            scanf("%f", &sueldob);
            printf("Ingresar el valor de las 3 comiciones\n");
            scanf("%f %f %f", &v1, &v2, &v3);
        case 3:
            printf("Ingresar las notas de los 3 parciales\n");
            printf("Luego la nota del examen final y luego del trabajo final\n");
            scanf("%f %f %f %f %f", &not1, &not2, &not3, &notf, &tpf);
            NotaF(not1, not2, not3, notf, tpf);
            break;
        case 4:
            printf("Ingresa el primer numero de inicio");
            scanf("%d", &num1);
            printf("Ingresa el segundo numero de inicio");
            scanf("%d", &num2);
            printf("Los numeros pares entre %d y %d son: ",num1 ,num2);
            numPar(num1, num2);
            break;
    }
    return 0;
}