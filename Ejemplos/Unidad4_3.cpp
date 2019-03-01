/* Unidad 4: Programacion modular y matematicas.
   Autor: Carlos Manuel Rodriguez y Martinez */

/* Se pueden incluir archivos de inclusion con funciones adicionales.
   En este caso usaremos "CursoCppLib.h" que contiene definiciones y funciones 
   para este curso. Para este ejemplo usaremos el graficador. */

#include "CursoCppLib/CursoCppLib.h"
#include <cmath>
using namespace std;

int main()
{
	// Creamos un vector para que guarde los valores de la grafica de seno.
	vector<Coord> data;
	for(double i = 0; i< 6.28; i += 0.01)
	{
		data.push_back(Coord(i,sin(i)));
	}

	// Graficamos los valores guardados.
	Plot(data);

	// La misma grafica pero guardando el archivo en BMP
	BMPPlot(data, "grafica.bmp");
	return 0;
}

/* Ejercicio: Graficar los resultados de la ecuacion del oscilador armonico. */
