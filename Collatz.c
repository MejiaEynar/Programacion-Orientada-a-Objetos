#include<stdio.h>
#include<math.h>

int main(){
   int collatz = 6;
    int t;
    printf("%d\n", collatz);
    if(collatz % 2 == 0){
        t = collatz;
        collatz = collatz / 2;
        printf("%d\n", collatz);
        if(collatz % 2 != 0){
            t = collatz;
            collatz = (collatz * 3) + 1;
            
        }
        printf("%d\n", collatz);
    }
    
}