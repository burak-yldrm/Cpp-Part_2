#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	//Data*		data = new Data("Hello", "World", 42);
	Data*		data = Data::AutoFiller();
	uintptr_t	serialized;

	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data* data_2 = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << std::endl;
	std::cout << "s1: " << data_2->s1 << std::endl;
	std::cout << "s2: " << data_2->s2 << std::endl;
	std::cout << "n: " << data_2->value << std::endl;

	delete data;
	return (0);
}