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

void Mayorque(){

}

int main(){
    switch(){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("Opcion no Valida\n");
            break;
    }
}