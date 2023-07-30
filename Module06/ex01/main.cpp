#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	//Data*		data = new Data("Hello", "World", 42);
	Data*		data = Data::AutoFiller();
	uintptr_t	serialized;

	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	data = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->value << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;
	return (0);
}