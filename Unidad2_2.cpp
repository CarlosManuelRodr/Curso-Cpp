/* Unidad 2: Tipos de variables.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

int entero1, entero2;	// Si son del mismo tipo se pueden declarar asi.

int main()
{
	cout << "Introduzca el primer numero: ";
	cin >> entero1;
	cout << "Introduzca el segundo numero: ";
	cin >> entero2;

	int suma = entero1 + entero2;
	cout << "La suma de los numeros es: " << suma << endl;

	cout << "Tambien se puede hacer la suma aqui: " << entero1 + entero2 << endl;
	return 0;
}

/* Ejercicio: El usuario tecleará dos números (a y b), y el programa mostrar el resultado de la
operación (a+b)*(a-b) y el resultado de la operación a^2-b^2 */

