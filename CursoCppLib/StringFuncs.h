/*
	Title: CharlesLib.
	Brief: Funciones para manipulacion de cadenas de texto.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#ifndef __cadenas
#define __cadenas

#include <sstream>
#include <string>

std::string num_to_string( int d );
std::string num_to_string( double d );
double string_to_double( const std::string& s );
int string_to_int( const std::string& s );
bool is_there_substr( std::string cad, std::string cadBus );
bool is_there_function(std::string input);
std::string replace_ext(std::string filepath, std::string newExt);

#endif
