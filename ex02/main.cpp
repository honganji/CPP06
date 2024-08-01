#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"

int main()
{
	// TEST for identify(Base *p) and identify(Base &p)
	{
		std::cout << "\033[31mTEST for identify(Base *p) and identify(Base &p)\033[0m" << std::endl;
		std::cout << "\033[31m--------------------------------------------------------\033[0m" << std::endl;
		Base *base1;
		Base *base2;
		base1 = generate();
		base2 = generate();
		Base &base3 = *base2;
		identify(base1);
		identify(base3);
	}
	std::cout << "\033[31m--------------------------------------------------------\033[0m" << std::endl << std::endl;

	// Test if generate function generates randomly
	{
		std::cout << "\033[32mTest if generate function generates randomly\033[0m" << std::endl;
		std::cout << "\033[32m--------------------------------------------------------\033[0m" << std::endl;
		Base *base;
		base = generate();
		identify(base);
		delete base;
		base = generate();
		identify(base);
		delete base;
		base = generate();
		identify(base);
		delete base;
		base = generate();
		identify(base);
		delete base;
	}
	std::cout << "\033[32m--------------------------------------------------------\033[0m" << std::endl;
	return (0);
}
