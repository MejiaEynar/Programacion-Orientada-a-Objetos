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
// Ejercicio N°4

int main(void){
    float n1, n2, n3; //Variable del ejercicio 2
    int n; //Variable del ejercicio 3
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
            break;
        case 5:
            break;
        default:
            break;
    }
    return 0;
}