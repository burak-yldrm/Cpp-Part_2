#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str)
{
	if (CheckInputType::isInteger(str)
		|| CheckInputType::isFloat(str)
		|| CheckInputType::isDouble(str)
		|| CheckInputType::isNaN(str))
	{
		printChar(str);
		printInt(str);
		printFloat(str);
		printDouble(str);
	}
	else
		std::cout << "Please enter a valid input" << std::endl;
}

void ScalarConverter::printChar(std::string const &str)
{
	char charValue = static_cast<char>(atoi(str.c_str())); 
	std::cout << "char: ";

	if (isascii(charValue) == 0 || isdigit(str[0]) == 0)
		std::cout << "impossible" << std::endl;
	else if (isprint(charValue))
		std::cout << "'" << charValue << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(std::string const &str)
{
	long int intValue = atol(str.c_str());
	std::cout << "int: ";

	if (((intValue > INT_MAX || intValue < INT_MIN) && str.length() >= 10) || isdigit(str[0]) == 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
}


//340282346638528859811704183484516925440.0000000000000000 ==> Float max limit / +inf
//-340282346638528859811704183484516925440.0000000000000000 ==> Float max limit / -inf
// std::fixed --> sayıyı bilimsel gösterimden normal gösterime çevirir.
// std::setprecision(1) --> virgülden sonra kaç basamak gösterileceğini belirler.
void ScalarConverter::printFloat(std::string const &str)
{
	float floatValue = strtof(str.c_str(), NULL);
	std::cout << "float: ";

	if (std::isinf(floatValue) && floatValue > 0)
		std::cout << "+inff" << std::endl;
	else if (std::isinf(floatValue) && floatValue < 0)
		std::cout << "-inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

// Double MIN:
//-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
// Double MAX:
//179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
void ScalarConverter::printDouble(std::string const &str)
{
	double doubleValue = atof(str.c_str());
	std::cout << "double: ";

	if (std::isinf(doubleValue) && doubleValue > 0)
		std::cout << "+inf" << std::endl;
	else if (std::isinf(doubleValue) && doubleValue < 0)
		std::cout << "-inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}