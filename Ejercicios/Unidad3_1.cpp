/* Unidad 3: Estructuras de control.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

/* La estructura de control "if" permite verificar si se cumple una condicion,
   y ejecutar cierta porcion de codigo */

int main()
{
	int numero;
	cout << "Introduzca un numero: ";
	cin >> numero;

	if(numero == 2)
	{
		cout << "El numero es 2" << endl;
	}
	else
	{
		cout << "El numero no es 2" << endl;
	}

	return 0;
}

/* Ejercicio: Crear un programa que pida al usuario un número entero y diga si es par (pista: habrá
que comprobar si el resto que se obtiene al dividir entre dos es cero: x % 2 == 0 */

