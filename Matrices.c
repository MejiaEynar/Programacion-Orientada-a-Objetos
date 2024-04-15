#include <stdio.h>

main ()
{
    int A [3][3];
    int i, j;
    printf ("Este programa te pide una matriz de 3x3 \n \n");
    // ciclo for para pedir datos de la matriz
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			printf ("Ingresa el valor A[%d][%d]: ", i, j);
			scanf ("%d", &A[i][j]);
		}
	}
    
    // ciclo for para pedir imprimir en pantalla la matriz
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			/* printf ("%d ", A[i][j]);
			puedo agregar un espacio, pero lo que necesito es que baje cada vez
			que termine la fila y eso lo controla el ciclo for con variable i */
			
			// caracter de control \t tabulador horizontal
			printf ("%d\t", A[i][j]);
		}
		printf ("\n");
	}
      
}

/*

	No entendi bien si queria que se indicara las formas en las que se podia optimizar este codigo
	o si queria que en una "caja" como esta. Escribieramos en codigo los cambios a hacer.

*/

/*

Opcion 1(No codigo):
	Lo que se podria hacer para mejorar el codigo para que este aceptara matrices de un tamaño
	ingresado por el usuario. A travez de una funcion haciendo uso del scanf para obtener el tamaño 
	de la matriz. Y este llevarlo a una funcion en la cual se crearia la matriz y en la misma se solicitarian
	los valores que serian ingresados en la matriz. Tambien se podria dar a escojer al usuario si este quiere rellenar
	la matriz de forma manual o que esta se rellene automaticamente con numeros aleatorios.
*/

/*

Opcion 2(codigo):

#include<stdio.h>

void imprimirMatriz(int f, int c, int A[f][c]) {
    int i, j;
    printf("La matriz ingresada es:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int f, c;
    int i, j;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &f);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &c);

    int A[f][c];

    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("Ingrese el valor A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    imprimirMatriz(f, c, A);

}

*/