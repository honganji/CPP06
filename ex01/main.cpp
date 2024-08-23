#include "include/Serializer.hpp"

int main()
{
	Data *data = new Data();
	uintptr_t intPtr;

	data->num = 10;
	std::cout << "Original data ptr: " << data << ", num: " << data->num << std::endl;
	intPtr = Serializer::serialize(data);
	std::cout << "Serialized data unsigned int ptr: " << intPtr << std::endl;
	std::cout << "Deserialized data ptr: " << Serializer::deserialize(intPtr);
	std::cout << ", num: " << Serializer::deserialize(intPtr)->num << std::endl;
	delete data;
	return (0);
}
