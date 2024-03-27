#include <stdio.h>
#include <math.h>
// Ejercicio N°1

// Ejercicio N°2
void promediode3(float n1, float n2, float n3){
    float t = (n1 + n2 + n3) / 3;
    printf("El promedio de estos 3 numeros es: %.2f\n", t);
}

// Ejercicio N°3
void parOinparmayorque0(int n){
    if (n > 0) {
        if (n % 2 == 0) {
            printf("%d es un número par.\n", n);
        } else {
            printf("%d es un número impar.\n", n);
        }
    } else {
        printf("El número ingresado no es válido. Debe ser positivo y mayor que cero.\n");
    }
}

// Ejercicio 4
void apro(float not1, float not2, float not3, float not4, float tarea){
    float notA = (not1 + not2 + not3 + not4 + tarea) / 5;
    if(notA >= 0 && notA <= 5){
        printf("La nota de alumno es de: %.2f\n", notA);
        printf("Por lo tanto no aprobo la materia.");
    } else if(notA >= 6 && notA <= 10){
        printf("La nota de alumno es de: %.2f\n", notA);
        printf("Por lo tanto aprobo la materia.");
    } else {
        printf("El alumno no figura en la lista.")
    }
}

// Ejercicio 5
void apro2(float nota){
    if(nota >= 8){
        printf("El alumno aprobo\n");
        printf("Felicitaciones\n");
    }else if(nota >= 6){
        printf("El alumno aprobo\n");
    } else if(nota = 1){
        printf("El alumno no aprobo\n");
        printf("Debes esforzarte más\n");
    } else if(nota <= 5){
        printf("El alumno no aprobo\n");
    } 
}

int main(void){
    float n1, n2, n3; //Variable del ejercicio 2
    int n; //Variable del ejercicio 3
    float not1, not2, not3, not4, tarea; // Variables jercicio 4
    int nota;
    int opcion;
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            break;
        case 2:
            scanf("%f %f %f", &n1, &n2, &n3);
            promediode3(n1, n2, n3);
            break;
        case 3:
            scanf("%d", &n);
            parOinparmayorque0(n);
            break;
        case 4:
            printf("Ingresa la nota de la primera prueba: ");
            scanf("%f ", not1);
            printf("Ingresa la nota de la segunda prueba: ");
            scanf("%f ", not2);
            printf("Ingresa la nota de la tercera prueba: ");
            scanf("%f ", not3);
            printf("Ingresa la nota de la cuarta prueba: ");
            scanf("%f ", not4);
            printf("Ingresa la nota de la tarea: ");
            scanf("%f ", tarea);
            apro(not1, not2, not3, not4, tarea);
            break;
        case 5:
            scanf("%d", %nota);
            apro2(nota);
            break;
        default:
            break;
    }
    return 0;
}