#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout << "-------------------NAN TEST-------------------\n";
		std::string str = argv[1];
		ScalarConverter::convert(str);
		std::cout << "-------------------NAN TEST END--------------------\n\n";
	}
	else
		std::cout << "Parameters is not valid!\n" << "usage: ./convert 'value'" << std::endl;
}