/* Unidad 4: Programacion modular y matematicas.
   Autor: Carlos Manuel Rodriguez y Martinez */

/* CursoCppLib provee metodos para graficar usando arreglos de matrices. Este metodo es muy popular
   al trabajar con graficos. La sintaxis de la clase Matrix es:

      Matrix<tipo> nombre(int altura, int anchura)

   Al igual que en los vectores se puede acceder a cada uno de sus elementos por sus indices:

      nombre[i][j]

   Se puede usar esto para crear imagenes.

   En CursoCppLib tambien esta definida la clase Color, que crea los colores a partir de

      Color(char rojo, char verde, char azul)
*/

#include "CursoCppLib/CursoCppLib.h"
#include <cmath>
#include <complex>
using namespace std;

void DibujaRecuadro()
{
	// Dibuja recuadro rojo.
	Matrix<Color> colores(400,600);
	for(int i=0; i < colores.GetNumRows(); i++)
	{
		for(int j=0; j < colores.GetNumCols(); j++)
		{
			// Llena la matriz colores del color rojo.
			colores[i][j] = Color(255,0,0);
		}
	}
	BMPPlot(colores, "rojo.bmp");
}

void DibujaMandelbrot()
{
	// Dibuja Mandelbrot en blanco y negro.
	int filas = 400;
	int columnas = 600;
	Matrix<Color> mandelbrot(filas, columnas);

	double minRe = -2.45296;
	double maxRe = 1.1624;
	double minIm = -1.169;
	double maxIm = minIm+(maxRe-minRe)*filas/columnas;

	double reFactor = (maxRe-minRe)/(columnas-1);
	double imFactor = (maxIm-minIm)/(filas-1);

	complex<double> z, c;
	unsigned n;
	unsigned int maxIter = 100;
	bool pertenece;
	
	for(int y=0; y<filas; y++)
	{
		for(int x=0; x<columnas; x++)
		{
			z = c = complex<double>(minRe + x*reFactor, maxIm - y*imFactor);

			pertenece = true;

			for(n=0; n<maxIter; n++)
			{
				if(z.real()*z.real() + z.imag()*z.imag() > 4)
				{
					pertenece = false;
					break;
				}
				z = pow(z,2) + c;
			}

			if(pertenece)
			{
				mandelbrot[y][x] = Color(0,0,0);
			}
			else
			{
				mandelbrot[y][x] = Color(255,255,255);
			}
		}
	}

	BMPPlot(mandelbrot, "mandelbrot.bmp");
}

void DibujaMandelbrotColor()
{
	// Dibuja Mandelbrot en blanco y negro.
	int filas = 400;
	int columnas = 600;
	Matrix<Color> mandelbrot(filas, columnas);

	double minRe = -2.45296;
	double maxRe = 1.1624;
	double minIm = -1.169;
	double maxIm = minIm+(maxRe-minRe)*filas/columnas;

	double reFactor = (maxRe-minRe)/(columnas-1);
	double imFactor = (maxIm-minIm)/(filas-1);

	complex<double> z, c;
	unsigned n;
	unsigned int maxIter = 100;
	bool pertenece;
	
	for(int y=0; y<filas; y++)
	{
		for(int x=0; x<columnas; x++)
		{
			z = c = complex<double>(minRe + x*reFactor, maxIm - y*imFactor);

			pertenece = true;

			for(n=0; n<maxIter; n++)
			{
				if(z.real()*z.real() + z.imag()*z.imag() > 4)
				{
					pertenece = false;
					break;
				}
				z = pow(z,2) + c;
			}
			if(pertenece)
			{
				mandelbrot[y][x] = Color(0,0,0);
			}
			else
			{
				mandelbrot[y][x] = CalcColor(n);
			}
		}
	}

	BMPPlot(mandelbrot, "mandelbrot_color.bmp");
}

int main()
{
	DibujaRecuadro();
	DibujaMandelbrot();
	DibujaMandelbrotColor();

	return 0;
}
