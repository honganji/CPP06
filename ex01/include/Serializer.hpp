#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <cstdint>

struct Data
{
	int num;
};

class Serializer
{	
	private:
		Serializer(void);
		Serializer (const Serializer &ref);
		Serializer &operator=(const Serializer &ref);
		~Serializer(void);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
