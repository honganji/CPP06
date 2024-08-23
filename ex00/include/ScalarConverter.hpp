#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

enum Type
{	
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	EXCEPTION
};

struct check
{
	Type type;
	bool (*checkFun)(std::string str);
};

class ScalarConverter
{
	private:
		static bool _checkChar(std::string str);
		static bool _checkInt(std::string str);
		static bool _checkDouble(std::string str);
		static bool _checkFloat(std::string str);
		static Type _checkType(std::string str);
		static void _caseOfChar(std::string str);
		static void _caseOfInt(std::string str);
		static void _caseOfFloat(std::string str);
		static void _caseOfDouble(std::string str);
		static void _caseOfException(void);
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter &operator=(const ScalarConverter &ref);
		~ScalarConverter(void);

	public:
		static void convert(std::string str);
};

#endif
