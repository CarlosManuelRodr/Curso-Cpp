/* Unidad 4: Programacion modular y matematicas.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
#include <cmath>  // Incluye las funciones matematicas.
using namespace std;

/* C y C++ son lenguajes que admiten la programacion modular. Es decir, se pueden descomponer
   en funciones. */

void escribe_numero(int numero)
{
	cout << numero << endl;
}


// Se pueden sobrecargar las funciones para varios tipos de datos.
void escribe_numero(float numero)
{
	cout << numero << endl;
}

int suma(int n1, int n2)
{
	return n1 + n2;
}

int main()
{
	// Uso de funciones.
	escribe_numero(4);		// Escribe numero entero.
	escribe_numero((float)4.39); // Escribe flotante.
	escribe_numero( suma(5,7) );

	escribe_numero( (float)sin(3.49) );
	return 0;
}

/* cmath incluye las funcioes: sin, cos, tan, pow, sqrt, log, sinh, cosh, tanh, etc.. */

/* Ejercicio 1: Hacer un programa que calcule la solucion de una ec. cuadratica. Habra una funcion 
   llamada "raiz_positiva" y otra "raiz_negativa". 

   Ejercicio 2: Hacer un programa que resuelva la ecuacion diferencial del oscilador armonico por
   el metodo de euler para un tiempo t y un intervalo deltaT especificado por el usuario. Tomar k = 1.*/

