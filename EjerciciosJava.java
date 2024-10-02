/*Ejercicio 1*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
      System.out.println("Ingrese el primer numero: ");
	    Scanner myObj = new Scanner(System.in);
	    int num = myObj.nextInt();
      System.out.println("Ingrese el segundo numero: ");
	    Scanner myObj1 = new Scanner(System.in);
	    int num1 = myObj1.nextInt();
	    System.out.println("El resultado de la suma es: "+(num + num1));
	    System.out.println("El resultado de la resta es: "+(num - num1));
	    System.out.println("El resultado de la multiplicacion es: "+(num * num1));
	    System.out.println("El resultado de la division es: "+(num / num1));
	    System.out.println("El resto de la division es: "+(num % num1));
	}
}
/*Ejercicio 2*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		System.out.println("Ingrese el primer numero: ");
		Scanner myObj = new Scanner(System.in);
		int num = myObj.nextInt();
		System.out.println("Ingrese el segundo numero: ");
		Scanner myObj1 = new Scanner(System.in);
		int num1 = myObj1.nextInt();
		if(num == num1) {
			System.out.println("Ambos numeros son iguales");
		} else if (num > num1) {
			System.out.println("El numero: "+num+" es mayor que el numero: "+num1);
		} else {
			System.out.println("El numero: "+num+" es menor que el numero: "+num1);
		}
	}
}
/*Ejercicio 3 y Ejercicio 4*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
			System.out.println("Ingrese su nombre: ");
			Scanner myObj = new Scanner(System.in);
			String nombre = myObj.nextLine();
			System.out.println("Bienvenido "+nombre);
	}
}
/*Ejercicio 5*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		    double pi = 3.14;
			System.out.println("Ingrese el radio: ");
			Scanner myObj = new Scanner(System.in);
			int num = myObj.nextInt();
			System.out.println("El area del circulo es de: "+ ((num * num) * pi));
	}
}
/*Ejercicio 6*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
			System.out.println("Ingrese un numero: ");
			Scanner myObj = new Scanner(System.in);
			int num = myObj.nextInt();
			if((num % 2) == 0){
			    System.out.println("El numero es divisible por 2");
			} else {
			    System.out.println("El numero no es divisible por 2");
			}
	}
}
/*Ejercicio 7*/
/*Ejercicio 8*/
/*Ejercicio 9*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	        final double IVA = 0.21;
			System.out.println("Ingrese un numero: ");
			Scanner myObj = new Scanner(System.in);
			int p = myObj.nextInt();
			System.out.println("El precio final del producto sera de: "+((p * IVA) + p));
	}
}
/*Ejercicio 10*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		System.out.println("Ingrese un numero: ");
		Scanner myObj = new Scanner(System.in);
		int p = myObj.nextInt();
		int i = 0;
		while(i <= p) {
			System.out.println(i);
			i++;
		}
	}
}
/*Ejercicio 11*/
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		System.out.println("Ingrese un numero: ");
		Scanner myObj = new Scanner(System.in);
		int p = myObj.nextInt();
		for(int i = 0; i <= p; i++) {
			System.out.println(i);
		}
	}
}
/*Ejercicio 12*/
/*Ejercicio 13*/
/*Ejercicio 14*/
/*Ejercicio 15*/
/*Ejercicio 16*/
/*Ejercicio 17*/
/*Ejercicio 18*/
/*Ejercicio 19*/
/*Ejercicio 20*/
/*Ejercicio 21*/
/*Ejercicio 22*/
/*Ejercicio 23*/
/*Ejercicio 24*/
/*Ejercicio 25*/
/*Ejercicio 26*/
/*Ejercicio 27*/
/*Ejercicio 28*/
/*Ejercicio 29*/
/*Ejercicio 30*/
/*Ejercicio 31*/
/*Ejercicio 32*/
/*Ejercicio 33*/
/*Ejercicio 34*/
/*Ejercicio 35*/
/*Ejercicio 36*/
/*Ejercicio 37*/
/*Ejercicio 38*/
/*Ejercicio 39*/
