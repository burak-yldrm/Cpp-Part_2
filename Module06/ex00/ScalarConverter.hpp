#pragma once

#include <cstdlib>
#include <climits>
#include <cerrno>
#include <iomanip>

#include "CheckInputType.hpp"

class ScalarConverter
{
	public:
		static void convert(std::string const &str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		static void printChar(std::string const &str);
		static void printInt(std::string const &str);
		static void printFloat(std::string const &str);
		static void printDouble(std::string const &str);

};