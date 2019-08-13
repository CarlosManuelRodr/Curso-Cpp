/*
	Title: CharlesLib.
	Brief: Funciones para graficar.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#ifndef _PLOTTER
#define _PLOTTER

#include "BmpWriter.h"
#include "Matrix.h"
#include <vector>
#include <string>

// Auxiliares
Color CalcColor(unsigned int colorNum);

// Almacena coordenadas.
struct Coord
{
public:
	double x, y;
	Coord();
	Coord(double _x, double _y);
};

// Funciones.
void Plot(const std::vector<Coord> data);  // Grafica usando Matplotlib (python).
void Plot(const std::vector<double> data);
void BMPPlot(const std::vector<double> data, const std::string filename);	// Grafica en un BMP.
void BMPPlot(const std::vector<Coord> data, const std::string filename);
void BMPPlot(Matrix<Color> &data, const std::string filename);

#endif
