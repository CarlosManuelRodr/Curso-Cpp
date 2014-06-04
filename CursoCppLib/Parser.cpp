#include "Parser.h"
#include <cstdlib>
using namespace std;

//Parser simple para polinomios
vector<double> Parser(string ecuacion)
{
	double *ListaTerminos[2];   //Renglon cero es para coeficientes y el renglon 1 es para exponentes

	//Cuenta cuantos términos hay para reservar memoria
	int nTerminos = 1;
	for(unsigned int i=0; i<ecuacion.length(); i++)
	{
		if(ecuacion[i] == '+' || ecuacion[i] == '-') nTerminos++;
	}
	ListaTerminos[0] = new double[nTerminos];
	ListaTerminos[1] = new double[nTerminos];

	int termino = 0;		//Se refiere a la posicion del término en la matriz de coeficientes y exponentes
	unsigned int posicion = 0;    //Posicion se refiere a la posición dentro de la cadena de texto,
	bool NumeroAnterior = false;
	bool PreparaExponente = false;
	bool exponente = false;
	bool HuboSigno = false;
	bool HuboX = false;

	//Limpia la matriz
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<nTerminos; j++)
		{
			ListaTerminos[i][j] = 0;
		}
	}

	while(posicion < ecuacion.length())
	{
		if(posicion+1 == ecuacion.length() && !exponente)
		{
			if(HuboSigno)
			{
				ListaTerminos[0][termino] *= atoi(&ecuacion[posicion]);
				HuboSigno = false;
			}
			else if(!NumeroAnterior)
			{
				ListaTerminos[0][termino] = atoi(&ecuacion[posicion]);
			}
			if(ecuacion[posicion] == 'x' || ecuacion[posicion] == 'X')
			{
				ListaTerminos[1][termino] = 1;
			}

		}
		else
		{
			switch(ecuacion[posicion])
			{
				case '-':
					{
						if(!HuboX)
						{
							ListaTerminos[1][termino] = 1;
							HuboX = true;
						}
						if(PreparaExponente)
						{
							ListaTerminos[1][termino] = 1;
							if(!NumeroAnterior) termino++; //
							PreparaExponente = false;
						}
						if(NumeroAnterior)
						{
							exponente = false;
							termino++;
						}
						NumeroAnterior = false;
						if(exponente)
						{
							ListaTerminos[1][termino] = -1;
						}
						else
						{
							ListaTerminos[0][termino] = -1;		//Esto es para que no cambie de término si se encuentra con el primer signo
						}
						HuboSigno = true;
					}
					break;
				case '+':
					{
						if(!HuboX)
						{
							ListaTerminos[1][termino] = 1;
							HuboX = true;
						}
						if(PreparaExponente)
						{
							ListaTerminos[1][termino] = 1;
							if(!NumeroAnterior) termino++;
							PreparaExponente = false;
						}
						if(NumeroAnterior)
						{
							exponente = false;
							termino++;
						}
						NumeroAnterior = false;
						if(exponente)
						{
							ListaTerminos[1][termino] = 1;
						}
						else
						{
							ListaTerminos[0][termino] = 1;
						}
						HuboSigno = true;
					}
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					{
						int temp;
						if(NumeroAnterior)
						{
							if(exponente)
							{
								temp = atoi(&ecuacion[posicion]);
								ListaTerminos[1][termino] += temp;
							}
							else
							{
								temp = atoi(&ecuacion[posicion]);
								ListaTerminos[0][termino] += temp;
							}
						}
						else
						{
							if(exponente)
							{
								if(HuboSigno)
								{
									ListaTerminos[1][termino] *= atoi(&ecuacion[posicion]);
									HuboSigno = false;
								}
								else
								{
									ListaTerminos[1][termino] = atoi(&ecuacion[posicion]);
								}
							}
							else
							{
								if(HuboSigno)
								{
									int n = atoi(&ecuacion[posicion]);
									if(n != 0)
										ListaTerminos[0][termino] *= atoi(&ecuacion[posicion]);
									else
										ListaTerminos[0][termino] *= 10;
									HuboSigno = false;
								}
								else ListaTerminos[0][termino] = atoi(&ecuacion[posicion]);
								HuboX = false;
							}
							NumeroAnterior = true;
						}
					}
					break;
				case 'x':
				case 'X':
					{
						HuboX = true;
						PreparaExponente = true;

						if((termino == 0)&&(!NumeroAnterior))
							ListaTerminos[0][0] = 1;
					}
					break;
				case '^':
					{
						if(PreparaExponente)
						{
							exponente = true;
							NumeroAnterior = false;
							PreparaExponente = false;
						}
					}
					break;
				default:
					{
						if(!HuboX) HuboX = true;
					}
			}
		}
		posicion++;
	}
	int nTerminosTemp = nTerminos;

	vector<double> out;
	double MaxPower = 1;
	for(int i=0; i<nTerminosTemp; i++)
		if(ListaTerminos[1][i] > MaxPower) MaxPower = ListaTerminos[1][i];

	bool HayPower;
	for(int p=static_cast<int>(MaxPower); p>=0; p--)
	{
		HayPower = false;
		for(int i=0; i<nTerminosTemp; i++)
		{
			if(ListaTerminos[1][i] == p)
			{
				if(nTerminos >= 0)
				{
					out.push_back(ListaTerminos[0][i]);
					nTerminos--;
				}
				HayPower = true;
			}
		}
		if(!HayPower && nTerminos >= 0) out.push_back(0);
	}
	delete[] ListaTerminos[0];
	delete[] ListaTerminos[1];

	return out;
}
