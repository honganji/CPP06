#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base() {};

static Base *createA(void)
{
	return (new A());
}

static Base *createB(void)
{
	return (new B());
}

static Base *createC(void)
{
	return (new C());
}

static bool isTypeA(Base *p)
{
	return (dynamic_cast<A*>(p) != nullptr);
}

static bool isTypeB(Base *p)
{
	return (dynamic_cast<B*>(p) != nullptr);
}

static bool isTypeC(Base *p)
{
	return (dynamic_cast<C*>(p) != nullptr);
}

Base *generate(void)
{
	static int index = 0;
	Base *(*creators[])() = {
		createA,
		createB,
		createC
	};

	if (index >= 3)
		index = 0;
	return (creators[index++]());
}

void identify(Base *p)
{
	TypeIden typeIdens[] = {
		{"A", isTypeA},
		{"B", isTypeB},
		{"C", isTypeC}
	};
	for (size_t i = 0; i < 3; i++)
		if (typeIdens[i].isTheType(p))
		{
			std::cout << "The type is " << typeIdens[i].type << std::endl;
			return ;
		}
}

void identify(Base &p)
{
	identify(&p);
}
