#include<stdio.h>
#include<math.h>

void Collatz(int collatz){
    int t;
    printf("%d ", collatz);
    while(collatz != 1){
        if(collatz % 2 == 0){
            collatz = collatz / 2;
        } else{
            collatz = (collatz * 3) + 1;
        }
        printf("%d ", collatz);
    }
}

int main(void){
   int collatz;
   printf("Ingrese un numero: ");
   scanf("%d", &collatz);
   printf("La conjetura collatz del %d\n", collatz);
   printf("Es la siguiente: ");
   Collatz(collatz);
    return 0;
}