#include "include/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (1);
	}
	else if (argc > 2)
		std::cout << "too many input" << std::endl;
	else
		std::cout << "input a string" << std::endl;
	return (1);
}
