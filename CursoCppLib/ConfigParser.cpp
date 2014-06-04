#include "ConfigParser.h"
#include <fstream>
using namespace std;

const int CTRUE = 0;
const int CFALSE = 1;

ConfigParser::ConfigParser(string filename)
{
	ifstream file;
	file.open(filename.c_str());

	// Analiza archivo.
	if(file.is_open())
	{
		const int bufferSize = 200;
		char buffer[bufferSize];
		string line;

		while(!file.eof())
		{
			file.getline(buffer, bufferSize);
			line = buffer;
			int equalPos = -1;
			for(unsigned int i=0; i<line.length(); i++)
			{
				if(line[i] == '=')
				{
					equalPos = i;
					break;
				}
			}
			if(equalPos != -1)
			{
				labels.push_back(line.substr(0,equalPos));
				args.push_back(line.substr(equalPos+1, line.length()-equalPos-1));
			}
		}
		fileOpened = true;
	}
	else fileOpened = false;
}
void ConfigParser::IntArgToVar(int& myVar, string expr, int defaultValue)
{
	bool found = false;
	for(unsigned int i=0; i<labels.size(); i++)
	{
		if(labels[i] == expr)
		{
			myVar = string_to_int(args[i]);
			found = true;
			break;
		}
	}
	if(!found) myVar = defaultValue;
}
void ConfigParser::DblArgToVar(double& myVar, string expr, double defaultValue)
{
	bool found = false;
	for(unsigned int i=0; i<labels.size(); i++)
	{
		if(labels[i] == expr)
		{
			myVar = string_to_double(args[i]);
			found = true;
			break;
		}
	}
	if(!found) myVar = defaultValue;
}
void ConfigParser::BoolArgToVar(bool& myVar, string expr, bool defaultValue)
{
	bool found = false;
	for(unsigned int i=0; i<labels.size(); i++)
	{
		if(labels[i] == expr)
		{
			if(args[i] == "TRUE" || args[i] == "True" || args[i] == "true") myVar = true;
			else myVar = false;
			found = true;
			break;
		}
	}
	if(!found) myVar = defaultValue;
}
void ConfigParser::StringArgToVar(string& myVar, string expr, string defaultValue)
{
	bool found = false;
	for(unsigned int i=0; i<labels.size(); i++)
	{
		if(labels[i] == expr)
		{
			myVar = args[i];
			found = true;
			break;
		}
	}
	if(!found) myVar = defaultValue;
}
