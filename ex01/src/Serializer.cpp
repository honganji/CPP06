#include "../include/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer instance is created!" << std::endl;
}

Serializer::Serializer (const Serializer &ref)
{
	(void)ref;
}

Serializer &Serializer::operator=(const Serializer &ref)
{
	(void)ref;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer instance is destroyed!" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
