#include<stdio.h>
#include<math.h>

void Ternas(int h, int cO, int cA){
    int t1, t2;
    t1 = (cO * cO) + (cA * cA);
    t2 = h * h;
    if(t1 == t2){
    printf("Es un triangulo rectangulo\n");
    } else{
        printf("No es un trianguo rectangulo");
    }
}

int main(void){
   int h, cO, cA;
   printf("Ingrese valores menores a 500\n");
   printf("Ingrese un valor para la Hipotenusa: ");
   scanf("%d", &h);
   if(h > 500){
        printf("ERROR N° no valido reinicie el programa\n");
        return 0;
    }
   printf("Ingrese un valor para el cateto Opuesto: ");
   scanf("%d", &cO);
   if(cO > 500){
        printf("ERROR N° no valido reinicie el programa\n");
        return 0;
    }
    printf("Ingrese un valor para el cateto Adyacente: ");
   scanf("%d", &cA);
   if(cA > 500){
        printf("ERROR N° no valido reinicie el programa\n");
        return 0;
    }
   Ternas(h, cO, cA);
}