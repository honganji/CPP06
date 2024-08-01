#ifndef BASE_H
# define BASE_H

#include <iostream>

class Base
{	
	public:
		virtual ~Base();
};


struct TypeIden
{
	const std::string type;
	bool (*isTheType)(Base *);
};
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
