#include "include/Serializer.hpp"

int main()
{
	Data *data = new Data();
	uintptr_t intPtr;

	std::cout << "Original ptr: " << data << std::endl;
	intPtr = Serializer::serialize(data);
	std::cout << "Serialized int ptr: " << intPtr << std::endl;
	std::cout << "Deserialized ptr: " << Serializer::deserialize(intPtr) << std::endl;
	delete data;
	return (0);
}
