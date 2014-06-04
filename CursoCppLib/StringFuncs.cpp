#include "StringFuncs.h"
using namespace std;

std::string num_to_string(int d)
{
	std::ostringstream oss;
	oss << d;
	return oss.str();
}
std::string num_to_string(double d)
{
	std::ostringstream oss;
	oss << d;
	return oss.str();
}
double string_to_double(const std::string& s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}
int string_to_int(const std::string& s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return static_cast<int>(x);
}
bool is_there_substr(string cad,string cadBus)
{
	int nCad,nCadBus;
	nCad=cad.length();
	nCadBus=cadBus.length();
	string subCad;
 
	for(int i=0; i<=nCad-nCadBus; i++)
	{                
		subCad = cad.substr(i, nCadBus);
		if(subCad == cadBus) return true;
	}
	return false;
}

bool is_there_function(string input)
{
	// Busca signos fuera de paréntesis.
	int signLevel = 0;
	for(unsigned int i=0; i<input.length(); i++)
	{
		if(input[i] == '(') signLevel--;
		if(input[i] == ')') signLevel++;
		if(signLevel == 0)
		{
			switch(input[i])
			{
			case '+':
			case '-':
			case '*':
			case '^':
			case'/': return false;
				break;
			}
		}
	}
	// Busca función.
	bool pLeft = false, pRight = false;
	for(unsigned int i=0; i<input.length(); i++)
	{
		if(input[i] == '(') pLeft = true;
		if(input[i] == ')') pRight = true;
	}
	if(pLeft && pRight) return true;
	else return false;
}
string replace_ext(string filepath, string newExt)
{
	// Cambia la extensión a la ruta de un archivo.
	unsigned int extDot; 
	for(unsigned int i=0; i<filepath.size(); i++)
	{
		if(filepath[i] == '.') extDot = i;
	}
	filepath.erase(extDot, filepath.size()-extDot);
	filepath += newExt;
	return filepath;
}
