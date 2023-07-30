#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

// struct Data
// {
// 	std::string	s1;
// 	int			n;
// 	std::string	s2;
// };

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& rhs);
};