/* Unidad 3: Estructuras de control.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

/* El comando break permite detener subitamente un bucle como while */

int main()
{
	int numero = 0;
	
	while(true)		// Esto es una condicion siempre verdadera, es decir, se ejecuta indefinidamente.
	{
		cout << "Introduzca el numero 2: ";
		cin >> numero;

		if(numero == 2)
		{
			cout << "Correcto." << endl;
			break;
		}
		else
		{	
			cout << "No, idiota! Te dije que el numero 2. " << endl;
		}
	}

	return 0;
}

/* Ejercicio 1: Crear un programa que pida números positivos al usuario, y vaya calculando la suma
de todos ellos (terminará cuando se teclea un número negativo o cero).

   Ejercicio 2: Hacer un programa que escriba del 1 al 10. 

   Ejercicio 3: Hacer un programa que escriba el termino n de la serie de fibonnaci. */

