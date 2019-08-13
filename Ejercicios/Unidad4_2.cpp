#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	// El vector es una estructura que contiene datos en una lista.
	vector<double> miLista;  // Aqui se crea un vector con elementos double.
	miLista.push_back(5.2);
	miLista.push_back(39.0);
	miLista.push_back(98.38); // Añadimos 3 elementos al vector.

	cout << "El primer elemento de miLista es: " << miLista[0] << endl;
	cout << "El segundo elemento de miLista es: " << miLista[1] << endl;
	cout << "El tercer elemento de miLista es: " << miLista[2] << endl;

	// Creamos un vector que guardara los numeros.
	vector <int> numeros;
	for(int i=0; i<=10; i++)
	{
		numeros.push_back(i);
	}

	// Ahora escribimos los elementos del vector.
	for(int i=0; i<numeros.size(); i++)
	{
		cout << numeros[i] << endl;
	}
	return 0;
}
