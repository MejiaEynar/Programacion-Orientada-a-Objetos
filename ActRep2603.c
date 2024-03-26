#include <stdio.h>
#include <math.h>

void promediode3(float n1, float n2, float n3){
    float t = (n1 + n2 + n3) / 3;
    printf("El promedio de estos 3 numeros es: %.2f\n", t);
}

int main(void){
    float n1, n2, n3;
    scanf("%f %f %f", &n1, &n2, &n3);
    promediode3(n1, n2, n3);
    return 0;
}