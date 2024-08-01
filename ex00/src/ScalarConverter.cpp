#include "../include/ScalarConverter.hpp"

void ScalarConverter::_outputChar(std::string str)
{
	std::cout << "char: ";
	if (str.length() == 1)
	{
		if (std::isprint(str[0]))
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
				return ;
			}
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::_outputInt(std::string str)
{
	std::cout << "int: ";
	try
	{
		std::cout << std::stoi(str) << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "out of range" << std::endl;
	}
}

void ScalarConverter::_outputFloat(std::string str)
{
	std::cout << "float: ";
	try
	{
		std::cout << std::fixed << std::setprecision(1) << std::stof(str);
		std::cout << "f" << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "out of range" << std::endl;
	}
}

void ScalarConverter::_outputDouble(std::string str)
{
	std::cout << "double: ";
	try
	{
		std::cout << std::stod(str) << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "out of range" << std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
	_outputChar(str);
	_outputInt(str);
	_outputFloat(str);
	_outputDouble(str);
}
