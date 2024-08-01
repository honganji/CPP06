#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

#include <iostream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
		static void _outputChar(std::string str);
		static void _outputInt(std::string str);
		static void _outputFloat(std::string str);
		static void _outputDouble(std::string str);
	
	public:
		static void convert(std::string str);
};

#endif
