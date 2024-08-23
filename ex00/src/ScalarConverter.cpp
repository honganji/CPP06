#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Scalar converter is created!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) {(void)ref;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Scalar converter is destroyed!" << std::endl;
}

bool ScalarConverter::_checkChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

bool ScalarConverter::_checkInt(std::string str)
{
	size_t index = 0;

	if (!(str[0] == '+' || str[0] == '-' || std::isdigit(str[0])))
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

bool ScalarConverter::_checkDouble(std::string str)
{
	size_t index = 0;
	bool isDot = false;

	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (true);
	if (!(str[0] == '+' || str[0] == '-' || std::isdigit(str[0])))
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (isDot && str[i] == '.')
			return (false);
		else if (!isDot && str[i] == '.')
		{
			isDot = true;
			continue;
		}
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::_checkFloat(std::string str)
{
	size_t index = 0;
	bool isDot = false;
	bool isF = false;

	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (true);
	if (!(str[0] == '+' || str[0] == '-' || std::isdigit(str[0])))
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (isDot && str[i] == '.')
			return (false);
		else if (!isDot && str[i] == '.')
		{
			isDot = true;
			continue;
		}
		if (isF && str[i] == 'f')
			return (false);
		else if (!isF && str[i] == 'f')
		{
			isF = true;
			continue;
		}
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

Type ScalarConverter::_checkType(std::string str)
{
	const check funs[] = {
		{CHAR, &_checkChar},
		{INT, &_checkInt},
		{DOUBLE, &_checkDouble},
		{FLOAT, &_checkFloat},
	};

	for (size_t i = 0; i < 4; i++)
		if (funs[i].checkFun(str))
			return (funs[i].type);
	return (EXCEPTION);
}

void ScalarConverter::_caseOfChar(std::string str)
{
	char c = str[1];
	double input = static_cast<double>(c);
	std::cout << "char: ";

	if (!isprint(input))
		std::cout << "impassible" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << input << ".0" << std::endl;
}

void ScalarConverter::_caseOfInt(std::string str)
{
	double input = strtod(str.c_str(), NULL);
	std::cout << "char: ";
	if (input < 0. || input > 255.)
		std::cout << "overflow" << std::endl;
	else if (input < 32. || input > 126.)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << input << std::endl;
	std::cout << "int: ";
	if (input > static_cast<double>(INT_MAX) || input < static_cast<double>(INT_MIN))
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << input << ".0" << std::endl;
}

void ScalarConverter::_caseOfFloat(std::string str)
{
	double input = strtod(str.c_str(), NULL);
	double tmp, fracNum;
	fracNum = std::modf(input, &tmp);
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		if (!str.compare("-inff"))
		{
			std::cout << "float: " << "-inff" << std::endl;
			std::cout << "double: " << "-inf" << std::endl;
		}
		else if (!str.compare("+inff"))
		{
			std::cout << "float: " << "+inff" << std::endl;
			std::cout << "double: " << "+inf" << std::endl;
		}
		else
		{
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
		return;
	}
	std::cout << "char: ";
	if (input < 0. || input > 255.)
		std::cout << "overflow" << std::endl;
	else if (input < 32. || input > 126.)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << input << std::endl;
	std::cout << "int: ";
	if (input > static_cast<double>(INT_MAX) || input < static_cast<double>(INT_MIN))
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input);
	if (fracNum == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << input;
	if (fracNum == 0)
		std::cout << ".0" << std::endl;
}

void ScalarConverter::_caseOfDouble(std::string str)
{
	double input = strtod(str.c_str(), NULL);
	double tmp, fracNum;
	fracNum = std::modf(input, &tmp);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		if (!str.compare("-inf"))
		{
			std::cout << "float: " << "-inff" << std::endl;
			std::cout << "double: " << "-inf" << std::endl;
		}
		else if (!str.compare("+inf"))
		{
			std::cout << "float: " << "+inff" << std::endl;
			std::cout << "double: " << "+inf" << std::endl;
		}
		else
		{
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
		return;
	}
	std::cout << "char: ";
	if (input < 0. || input > 255.)
		std::cout << "overflow" << std::endl;
	else if (input < 32. || input > 126.)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << input << std::endl;
	std::cout << "int: ";
	if (input > static_cast<double>(INT_MAX) || input < static_cast<double>(INT_MIN))
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input);
	if (fracNum == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << input;
	if (fracNum == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::_caseOfException(void)
{
	std::cout << "char: " << "\'*\'" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	Type type = _checkType(str);
	switch (type)
	{
	case CHAR:
		_caseOfChar(str);
		break;
	case INT:
		_caseOfInt(str);
		break;
	case DOUBLE:
		_caseOfDouble(str);
		break;
	case FLOAT:
		_caseOfFloat(str);
		break;
	default:
		_caseOfException();
		break;
	}
}
