#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>
#include <cmath>

int main()
{
	// CLASS TEST ALANI <<<<<<<<<<
	{
		std::cout << "-------------------NAN TEST-------------------\n";
		std::string str = "nan";
		ScalarConverter::convert(str);
		std::cout << "-------------------NAN TEST END--------------------\n\n";

		std::cout << "-------------------+INF TEST(FLOAT)-------------------\n";
		str = "3402823466385288598117041834845169254401.0000000000000000";
		ScalarConverter::convert(str);
		std::cout << "-------------------+INF TEST(FLOAT) END--------------------\n\n";
		
		std::cout << "---------------------INF TEST(FLOAT)-------------------\n";
		str = "-3402823466385288598117041834845169254401.0000000000000000";
		ScalarConverter::convert(str);
		std::cout << "-------------------INF TEST(FLOAT) END--------------------\n\n";

		std::cout << "-------------------CHAR & INT TEST-------------------\n";
		str = "42";
		ScalarConverter::convert(str);
		std::cout << "----------------------CHAR & INT TEST END-----------------\n\n";

		std::cout << "-------------------DOUBLE TEST-------------------\n";
		str = "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000";
		ScalarConverter::convert(str);
		std::cout << "----------------------CHAR & INT TEST END-----------------\n\n";

		std::cout << "-------------------ZERO TEST-------------------\n";
		str = "0";
		ScalarConverter::convert(str);
		std::cout << "---------------------ZERO TEST END------------------\n";

		std::cout << "-------------------+INF TEST(DOUBLE)-------------------\n";
		str = "1179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368";
		ScalarConverter::convert(str);
		std::cout << "-------------------INF TEST(DOUBLE) END--------------------\n\n";
	}
}