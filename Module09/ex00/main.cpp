#include "BitcoinExchange.hpp"

int main ( int argc, char **argv )
{
	BitcoinExchange exchange;

	if ( argc != 2 )
	{
		std::cout << "Usage: ./bitcoin [external database]" << std::endl;
		return 1;
	}

	try
	{
		exchange.exchangeResult( argv[1] );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
