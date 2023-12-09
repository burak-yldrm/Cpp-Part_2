#include "RPN.hpp"

int	main ( int argc, char ** argv)
{
	if (argc < 2)
		std::cerr << "Error: Invalid argument!\n";
	else
	{
		RPN calculate(argv[1]);
	}
	return (0);
}
