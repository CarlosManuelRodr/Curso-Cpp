/*
	Title: CharlesLib.
	Brief: Parser para archivos de configuracion.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#ifndef _configParser
#define _configParser
#include <string>
#include <vector>
#include "StringFuncs.h"

class ConfigParser  // Se encarga de analizar el archivo de configuración que se abre al iniciar el programa.
{
	std::vector<std::string> labels, args;
	bool fileOpened;

public:
	ConfigParser(std::string filename);
	bool FileOpened();
	void IntArgToVar(int& myVar, std::string expr, int defaultValue);
	void DblArgToVar(double& myVar, std::string expr, double defaultValue);
	void BoolArgToVar(bool& myVar, std::string expr, bool defaultValue);
	void StringArgToVar(std::string& myVar, std::string expr, std::string defaultValue);
	template<class M> void OptionToVar(M& myVar, std::string expr, std::vector<std::string> options, std::vector<M> values, M defaultValue);
};

template<class M> void ConfigParser::OptionToVar(M& myVar, std::string expr, std::vector<std::string> options, std::vector<M> values, M defaultValue)
{
	bool found = false;
	if(options.size() == values.size())
	{
		for(unsigned int i=0; i<labels.size() && !found; i++)
		{
			if(labels[i] == expr)
			{
				for(unsigned int j=0; j<options.size(); j++)
				{
					if(args[i] == options[j])
					{
						myVar = values[j];
						found = true;
						break;
					}
				}
			}
		}
		if(!found) myVar = defaultValue;
	}
	else myVar = defaultValue;
}

#endif
