/* Unidad 1: Introduccion 
   Autor: Carlos Manuel Rodriguez y Martinez */

#include <iostream>
#include <cstdlib>

int main()
{
	/* Si eliminamos "using namespace std;" hay que agregar std:: antes de todas
	   las funciones que estan en ese espacio de nombres */
 
	std::cout << "La vida es miseria" << std::endl;

/* Todos los comandos que empiezan con "#" son directivas preprocesador. Es decir,
   parte del codigo que se interpreta antes de compilar. */

#ifdef _WIN32	// En esta directiva se identifica el tipo de sistema antes de compilar.
	system("pause");
#elif __linux__
	std::cin.get();
#endif
	return 0;
}

// Ejercicio: Hacer el programa hola mundo.
