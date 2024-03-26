#include <stdio.h>
#include <math.h>

//Funcion para resolver el ejercicio: 1
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

//Funcion para resolver el ejercicio: 2
void SueldoTotal(float sueldob, float v1, float v2, float v3){
    float comicion = (v1 + v2 + v3) / 0.1;
    float comicionT = comicion * 3;
    float SueldoT = sueldob + comicionT;
    printf("El sueldo a final de mes que recibira es de: %.2f\n", comicionT);
    printf("El concepto por comicion de las 3 ventas es de: %.2f\n", SueldoT);
}

//Funcion para resolver el ejercicio: 3
void NotaF(float not1, float not2, float not3, float notf, float tpf){
    float promedio = (not1 + not2 + not3) / 3;
    float notaf = (promedio + notf + tpf) / 3;
    printf("La nota final sera de: %.2f\n", notaf);
}

//Funcion para resolver el ejercicio: 4
void numPar(int num1, int num2){
    for (int i = num1; i <= num2; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

//Funcion para resolver el ejercicio: 5
void MRU(int km_c1, int km_c2){
    int v = 1;
    int distancia_c1_c2 = km_c2 - km_c1;
    float t = (float)distancia_c1_c2 / (2 * v);
    int km_encuentro = km_c1 + v * t;
    printf("los coches se encontran en el Km: %d\n", km_encuentro);
}

int main(void){
    
    int alu; // Variable para el ejercicio 1
    float sueldob, v1, v2, v3, comicion, comicionT; // Variables para el ejercicio 2
    float not1, not2, not3, notf, tpf; // Variables para el ejercicio 3
    int num1, num2; // Variables para el ejercicio 4
    int km_c1, km_c2; // Variables para el ejercicio 5
    int opcion;
    printf("Escoje alguna de las opciones:\n");
    printf("1) Ejercicio Nº1\n");
    printf("2) Ejercicio Nº2\n");
    printf("3) Ejercicio Nº3\n");
    printf("4) Ejercicio Nº4\n");
    printf("5) Ejercicio Nº5\n");
    printf("Ingrese el numero de la opcion: ");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            printf("1. Pago por alumno y pago por alquiler del micro\n");
            printf("Ingrese el numero de alumnos: ");
            scanf("%d", &alu);
            costo(alu);
            break;
        case 2:
            printf("2. Sueldo del vendedor\n");
            printf("Ingresar el sueldo base:\n");
            scanf("%f", &sueldob);
            printf("Ingresar el valor de las 3 comiciones\n");
            scanf("%f %f %f", &v1, &v2, &v3);
            SueldoTotal(sueldob, v1, v2, v3);
            break;
        case 3:
            printf("3. Calificación final del alumno\n");
            printf("Ingresar las notas de los 3 parciales\n");
            printf("Luego la nota del examen final y luego del trabajo final\n");
            scanf("%f %f %f %f %f", &not1, &not2, &not3, &notf, &tpf);
            NotaF(not1, not2, not3, notf, tpf);
            break;
        case 4:
            printf("4. Números pares entre dos números\n");
            printf("Ingresa el primer numero: ");
            scanf("%d", &num1);
            printf("Ingresa el segundo numero:");
            scanf("%d", &num2);
            printf("Los numeros pares entre %d y %d son: ",num1 ,num2);
            numPar(num1, num2);
            break;
        case 5:
            printf("5. Encuentro de coches en la carretera\n");
            printf("Ingrese la distancia del primer coche:\n");
            scanf("%d", &km_c1);
            printf("Ingrese la distancia del segundo coche:\n");
            scanf("%d", &km_c2);
            MRU(km_c1, km_c2);
        default:
            break;
    }
    return 0;
}