#include <stdio.h>

void posOneg(int n){
    if(n > 0){
        printf("El numero es positivo\n");
    }else if(n < 0){
        printf("El numero es negativo\n");
    }else {
        printf("El numero es 0\n");
    }
}

void parOinpar(){
    if(n % 2 == 0){
        printf("El numero es par\n");
    }else {
        printf("El numero no es par\n");
    }
}

void Multiplo2o3(){
    if (n % 2 == 0 && n % 3 == 0) {
        printf("Es multiplo de ambos 2 y 3\n");
    } else if (n % 2 == 0) {
        printf("Es multiplo de 2\n");
    } else if (n % 3 == 0) {
        printf("Es multiplo de 3\n");
    } else {
        printf("No es multiplo de ninguno de los dos\n");
    }
}

void Mayorque(int a, int b, int c) {
    if (a > b && a > c) {
            printf("El primer numero es el mayor\n");
        } else if (b > a && b > c) {
            printf("El segundo numero es el mayor\n");
        } else if(c > a && c > b){
        printf("El tercer numero es el mayor\n");
        } else if (a == b && b > c) {
        printf("El primer y segundo numero son iguales y mayores que el tercero\n");
        } else if (a == c && c > b) {
        printf("El primer y tercer numero son iguales y mayores que el segundo\n");
        } else if (b == c && c > a) {
        printf("El segundo y tercer numero son iguales y mayores que el primero\n");
        } else (a == b && b == c) {
        printf("Los tres numeros son iguales\n");
        }
}

int main(){
    int opcion, n1, n2, n3;
    
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            scanf("%d", &n1);
            posOneg(n1);
            break;
        case 2:
            scanf("%d", &n1);
            parOinpar(n1);
            break;
        case 3:
            scanf("%d", &n1);
            multiplo2o3(n1);
            break;
        case 4:
            scanf("%d", &n1);
            scanf("%d", &n2);
            scanf("%d", &n3);
            mayorDeTres(n1, n2, n3);
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }
    
    return 0;
}