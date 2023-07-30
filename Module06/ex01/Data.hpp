#pragma once

#include <iostream>

class Data {
	public:
		std::string	s1;
		std::string	s2;
		int			value;

		Data(std::string s1, std::string s2, int value);
		~Data();

		static Data* AutoFiller();
	private:
		Data();
		Data(const Data& src);
		Data&	operator=(const Data& rhs);
};
