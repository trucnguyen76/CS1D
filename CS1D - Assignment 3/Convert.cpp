#include "header.h"
#include <sstream>

double Convert(string str)
{
	double result;

	stringstream convert(str);

	if(!(convert >> result))
	{
		result = 0;
	}

	return result;
}

string Convert(double num)
{
	stringstream convert;

	//Put num into the stream
	convert << num;

	return convert.str();
}

string Convert(char character)
{
	stringstream convert;

	//Put character into the stream
	convert << character;

	return convert.str();
}




