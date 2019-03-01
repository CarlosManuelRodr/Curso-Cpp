/* Unidad 3: Estructuras de control.
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
using namespace std;

/* La estructura for, for (valorInicial; CondiciónRepetición; Incremento)
   permite ejecutar cierto codigo un numero definido de veces. En general es una
   forma de resumir el while. */

int main()
{
	/* Si se quiere aumentar la variable "i" en una unidad se puede
	   usar i = i + 1, o i++ */

	for(int i=1; i<=10; i++)
	{
		if(i == 5) continue; // "continue" permite saltarse la ejecucion de un bucle. 
		cout << i << endl;
	}

	return 0;
}

/* Ejercicio: Crear un programa que escriba en pantalla los números del 1 al 50 que sean múltiplos
de 3 (pista: habrá que recorrer todos esos números y ver si el resto de la división entre
3 resulta 0). */


