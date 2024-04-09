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
        printf("El alumno no figura en la lista.");
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
// Ejercicio 6
void impuesto(int sueldo){
}

// Ejercicio 7
void hora(int hh, int mm){
    if(hh < 0 || mm < 0){
        printf("Error, ingrese numeros positivos\n");
    }else if (hh > 23 || mm > 59){
        printf("Error, ingrese un en hora un numero menor a 24 y en minutos un numero inferior o igual a 59\n");
    }else if(hh <= 12 && hh > 0){
        printf("%d:%d am", hh, mm);
    }else if(hh > 12 || hh == 0){
        printf("%d:%d pm", hh, mm);
    }
}

// Ejercicio 8
void ahorroT(float capital, int meses){
    for (int i = 0; i < meses; i++){
        float pagb = capital * 0.02;
        capital = capital + pagb;
    }
    printf("%.2f\n", capital);
}

// Ejercicio 9
void a_que_edad(int edad1, int edad2){
    int t1 = edad1;
    int t2 = edad2;
    for(int i = edad1; i > (edad2 * 2); i++){
        edad1 = edad1 + 1;
        edad2 = edad2 + 1;
        if(edad1 == (edad2 * 2)){
            printf("El padre tiene %d y el hijo %d\n", t1, t2);
            printf("Por ende debe pasar %d años para que el padre tenga el doble de edad que su hijo\n", (i-t1)+ 1);
            break;
        }
    }
}

//Base Ejercicio 10
/*
int main(){
    int segundos = 40000;
    int horas = 0;
    int minutos = 0;
    int t = segundos;
        if(segundos >= 3600){
            t = segundos - 3600;
            for(int i = 0; t >= i; i++){
                if(segundos >= 60){
                    t = t - 60;
                    minutos = minutos + 1;
                    if(minutos > 60){
                        horas = horas + 1;
                        minutos = t - minutos;
                    }
                }
            }
        printf("son las %d/%d/%d", horas, minutos,t);
        }
}
*/

// Ejercicio 13
void Pago(float pago, float descuento){
    float t = (pago * descuento) / 100;
    t = pago - t; 
    printf("%.2f", t);
}

int main(void){
    float n1, n2, n3; //Variable del ejercicio 2
    int n; //Variable del ejercicio 3
    float not1, not2, not3, not4, tarea; // Variables jercicio 4
    int sueldo;
    int hh, mm;//Variable del ejercicio 7
    
    float capital;
    int meses;
    
    int edad1, edad2;
    int nota;
    float pago, descuento; //Variables del ejercicio 13
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
            scanf("%f ", &not1);
            printf("Ingresa la nota de la segunda prueba: ");
            scanf("%f ", &not2);
            printf("Ingresa la nota de la tercera prueba: ");
            scanf("%f ", &not3);
            printf("Ingresa la nota de la cuarta prueba: ");
            scanf("%f ", &not4);
            printf("Ingresa la nota de la tarea: ");
            scanf("%f ", &tarea);
            apro(not1, not2, not3, not4, tarea);
            break;
        case 5:
            scanf("%d", &nota);
            apro2(nota);
            break;
        case 6:
            scanf("%d", &sueldo);
            impuesto(sueldo);
            break;
        case 7:
            scanf("%d", &hh);
            scanf("%d", &mm);
            hora(hh, mm);
            break;
        case 8:
            scanf("%f", &capital);
            scanf("%d", &meses);
            ahorroT(capital, meses);
            break;
        case 9:
            printf("Ingrese la edad del padre\n");
            scanf("%d", &edad1);
            printf("Ingrese la edad del hijo/a\n");
            scanf("%d", &edad2);
            a_que_edad(edad1, edad2);
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            printf("Ingrese el pago a realizar: ");
            scanf("%f", &pago);
            printf("Ingrese el descuento que se hara: ");
            scanf("%f", &descuento);
            Pago(pago, descuento);
            break;
        default:
            break;
    }
    return 0;
}