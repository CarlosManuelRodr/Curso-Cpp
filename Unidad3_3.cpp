/* Unidad 3: Estructuras de control.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

/* while es una estructura que permite crear un bucle, verificando si se cumple
   la condicion */

int main()
{
	int numero = 0;
	
	while(numero != 2)
	{
		cout << "Introduzca el numero 2: ";
		cin >> numero;

		if(numero == 2)
		{
			cout << "Correcto." << endl;
		}
		else
		{	
			cout << "No, idiota! Te dije que el numero 2. " << endl;
		}
	}

	return 0;
}

