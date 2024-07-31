#include "../include/ScalarConverter.hpp"

void ScalarConverter::_outputChar(std::string str)
{
	bool isNum = false;
	std::cout << "char: ";
	if (str.length() == 1)
	{
		if (std::isdigit(str[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << str << std::endl;
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
			if (std::isdigit(str[i]))
			{
				std::cout << "'" << "*" << "'" << std::endl;
				isNum = true;
				break ;
			}
		if (!isNum)
			std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::_outputInt(std::string str)
{
	std::cout << "char: ";
	if (str.length() == 1)
	{
		std::cout << str << std::endl;
	}
	// else
	// 	std::cout << "impossible" << std::endl;
}

void ScalarConverter::_outputFloat(std::string str)
{
	std::cout << str << std::endl;
}

void ScalarConverter::_outputDouble(std::string str)
{
	std::cout << str << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	_outputChar(str);
	_outputInt(str);
	_outputFloat(str);
	_outputDouble(str);
}
