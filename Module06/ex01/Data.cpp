#include "Data.hpp"

Data::Data(std::string s1, std::string s2, int value)
{
	this->s1 = s1;
	this->s2 = s2;
	this->value = value;
}

Data::~Data() {}

Data* Data::AutoFiller()
{
	Data* data = new Data("Hello", "World", 42);
	return (data);
}

