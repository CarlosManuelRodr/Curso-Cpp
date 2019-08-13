/* Unidad 2: Tipos de variables.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

// Hay varios tipos de variable para cada tipo de dato que se quiera almacenar.

int entero = -4439483;		// Puede tomar valores desde -2^31 a 2^31
unsigned int enteroUnsinged = 740239848;  // Entero sin signo, solo numeros positivos. Valores de 0 a 2^32
short int enteroCorto = 32; // Entero con valores de -2^15 a 2^15.
float flotante = 2.8989;  // 6 cifras significativas. Exponente de -10^38 a 10^38.
double doblePrecision;    // 10 cifras significativas. Exponente de -10^308 a 10^308.
char letra = 'a';
string texto = "Esto es una cadena de texto";

// Una estructura puede contener varios tipos de datos.
struct Estructura
{
	int dato1;
	double dato2;
};

int main()
{
	cout << "Entero: " << entero << endl;
	cout << "Entero Sin signo: " << enteroUnsinged << endl;
	cout << "Entero Corto: " << enteroCorto << endl;
	cout << "Flotante: " << flotante << endl;
	cout << "Texto: " << texto << endl;

	Estructura miStruct;
	miStruct.dato1 = 89;
	miStruct.dato2 = 39.09;
	cout << "Dato 2 de estructura: " << miStruct.dato2 << endl;
	return 0;
}

/* Ejercicio: Con el texto se pueden hacer tambien operaciones de suma. La suma en texto
			  une las cadenas de texto. Hacer un programa que le pregunte el nombre al usuario
			  y lo salude por su nombre */

