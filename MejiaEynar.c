#include<stdio.h>

void punto1(char *tipo, int tamaño){
    if(tipo = "a"){
        if(tamaño == 1){
            printf("El precio es de $200\n");
        } else if(tamaño == 2){
            printf("El precio es de $300\n");
        } else{
            printf("El tamaño de la uva no es valido\n");
        }
    } else if(tipo = "b"){
        if(tamaño == 1){
            printf("El precio es de $300\n");
        } else if(tamaño == 2){
            printf("El precio es de $500\n");
        } else{
            printf("El tamaño de la uva no es valido\n");
        }
    } else{
        printf("No hay registros del tipo de uva solicitado\n");
    }
}

void punto2(int base, int potencia){
    int t = base;
    if(base < 0 || potencia < 0){
        printf("Por favor ingrese un numero positivo en base y potenci\n");
    }
    for (int i = 0; i < potencia; i++){
        printf("%d\n", base);
        base = t * base;
    }
}

void punto3(float radio){
    float PI = 3.14;
    float L = 2 * PI * radio;
    float A = PI * (radio * radio);
    float V = (4 / 3) * PI * (radio * radio * radio);
    if(radio < 0){
        printf("El valor del radio ingresado debe ser positivo\n");
    }
    printf("La longitud de la circunferencia segun el radio ingreseado es de: %.2f\n", L);
    printf("El Area de la circunferencia es de: %.2f\n", A);
    printf("El Volumen de la circunferencia es de: %.2f\n", V);
}

void punto4(int genero, int edad, int añosAporte){
    if(genero == 1 && edad >= 65 && añosAporte > 20){
        printf("Esta persona tiene derecho a jubilarse\n");
    } else if(genero == 2 && edad >= 60 && añosAporte > 20){
        printf("Esta persona tiene derecho a jubilarse\n");
    } else{
        printf("Esta persona no tiene derecho a jubilarse\n");
        printf("Porque no cumple conj los requisitos para ello\n");
    }
}

void punto5(int hijos, int Age){
    int t;
    int t1;
    if (hijos < 2){
        printf("La familia no cumple con los requisitos para el subsidio\n");        
    }else if(hijos == 2){
        t = hijos * 700;
        t1 = Age * 1000;
        printf("La familia recibira un total de: $%d\n", t + t1);
        printf("Debido a que tiene %d\n", hijos);
    }else if(hijos > 2 && hijos <= 5){
        t = hijos * 800;
        t1 = Age * 1000;
        printf("La familia recibira un total de: $%d\n", t + t1);
        printf("Debido a que tiene %d\n", hijos);
    } else{
        t = hijos * 1200;
        t1 = Age * 1000;
        printf("La familia recibira un total de: $%d\n", t + t1);
        printf("Debido a que tiene %d\n", hijos);
    }
}

int main(){
    char *tipo;
    int tamaño;
    int base, potencia;
    float radio;
    int genero, edad, añosAporte;
    int hijos, Age;
    int opcion;
    printf("Evaluacion de Programacion Orientada a Objetos\n");
    printf("1) Punto 1\n");
    printf("2) Punto 2\n");
    printf("3) Punto 3\n");
    printf("4) Punto 4\n");
    printf("5) Punto 5\n");
    printf("Ingrese una de las opciones: ");
    scanf("%d", &opcion);
    switch (opcion){
        case 1:
            printf("Ingrese el tipo de uva que desea: ");
            scanf("%s", &tipo);
            printf("Ingrese el tamaño de la uva deseada: ");
            scanf("%d", &tamaño);
            punto1(tipo, tamaño);
            break;
        case 2:
            printf("Ingrese el valor de la base:");
            scanf("%d", &base);
            printf("Ingrese el valor de la potencia:");
            scanf("%d", &potencia);
            punto2(base, potencia);
            break;
        case 3:
            printf("Ingrese el valor del radio de la circunferencia:");
            scanf("%f", &radio);
            punto3(radio);
            break;
        case 4:
            printf("Ingrese el 1 si el genero es masculino y 2 si es femenino:");
            scanf("%d", &genero);
            printf("Ingrese la edad de la persona: ");
            scanf("%d", &edad);
            printf("Ingrese los años de aporte de la persona: ");
            scanf("%d", &añosAporte);
            punto4(genero, edad, añosAporte);
            break;
        case 5:
            printf("Ingrese el numero de hijos:");
            scanf("%d", &hijos);
            int total;
            for(int i = 0; i < hijos; i++){
                printf("Ingrese la edad del %d hijo:", i + 1);
                scanf("%d", &Age);
                if(Age >= 6 && Age <= 18){
                    total = total + 1;
                }
            }
            Age = total;
            punto5(hijos, Age);
            break;
        default:
            break;
    }
}