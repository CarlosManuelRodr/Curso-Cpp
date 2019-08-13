/* Unidad 2: Tipos de variables.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

// Espacio global.
int enteroGlobal;
float floatGlobal;

int main()
{
	// Espacio local. Solo disponible dentro de las funciones.
	int enteroLocal = 23;
	float floatLocal = 4.87;
	
	cout << "El numero entero es: " << enteroLocal << endl;
	cout << "El numero flotante es: " << floatLocal << endl;
	return 0;
}
