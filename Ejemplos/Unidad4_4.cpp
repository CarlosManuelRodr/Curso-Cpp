/* Unidad 4: Programacion modular y matematicas.
   Autor: Carlos Manuel Rodriguez y Martinez */

/* El metodo de Newton-Rhapson es un bastante eficiente para resolver ecuaciones
   numericamente. Para usarlo se requiere conocer la funcion f(x) y su derivada
   fPrime(x). Funciona tanto para numeros reales como para complejos. Su desventaja
   es que solo permite calcular una solucion por condicion inicial. 

   Esta definido por la relacion recurrente:

      x_(n+1) = x_n - f(x_n)/fPrime(x_n)

*/

#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

int maxIter = 10;

// Funcion 1: x^2 - 5x + 6
double f1(double x)
{
	return pow(x,2) - 5*x + 6;
}
double f1Prime(double x)
{
	return 2*x - 5;
}

void newtonRhapson1(double x0)
{
	double x = x0;
	cout << "Iteracion | x" << endl;
	cout << "-------------" << endl;
	for(int i=0; i<maxIter; i++)
	{
		x = x - f1(x)/f1Prime(x);
		cout << i << ", " << x << endl;
	}
}

// Funcion 2 (compleja): z^3 - 1
complex<double> f2(complex<double> z)
{
	return pow(z,3) - complex<double>(1,0);
}
complex<double> f2Prime(complex<double> z)
{
	return complex<double>(3,0)*pow(z,2);
}
void newtonRhapson2(complex<double> z0)
{
	complex<double> z = z0;
	cout << "Iteracion | z" << endl;
	cout << "-------------" << endl;
	for(int i=0; i<maxIter; i++)
	{
		z = z - f2(z)/f2Prime(z);
		cout << i << ", " << z.real() << " + i" << z.imag() << endl;
	}
}

int main()
{
	// Real.
	double x0;
	cout << "Newton-Rhapson real.\nIntroduzca x0: ";
	cin >> x0;
	newtonRhapson1(x0);

	// Complejo.
	double real, imag;
	cout << "Newton-Rhapson complejo.\nIntroduzca la parte real de z0: ";
	cin >> real;
	cout << "Ahora la parte imaginaria: ";
	cin >> imag;
	newtonRhapson2(complex<double>(real, imag));
	
	return 0;
}

/* Ejercicio: Implementar el metodo de Newton-Rhapson para f(z) := sen(z) - z */
