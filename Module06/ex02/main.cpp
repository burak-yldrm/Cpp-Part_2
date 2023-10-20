#include "Base.hpp"

int	main( void )
{
	Base*	tmp1 = generate();
	Base*	tmp2 = generate();
	Base*	tmp3 = generate();
	Base*	tmp4 = generate();

	std::cout << "tmp1* = ";
	identify( tmp1 );
	std::cout << "tmp1& = ";
	identify( *tmp1 );
	std::cout << std::endl;

	std::cout << "tmp2* = ";
	identify( tmp2 );
	std::cout << "tmp2& = ";
	identify( *tmp2 );
	std::cout << std::endl;

	std::cout << "tmp3* = ";
	identify( tmp3 );
	std::cout << "tmp3& = ";
	identify( *tmp3 );
	std::cout << std::endl;

	std::cout << "tmp4* = ";
	identify( tmp4 );
	std::cout << "tmp4& = ";
	identify( *tmp4 );
	std::cout << std::endl;


	delete tmp1;
	delete tmp2;
	delete tmp3;
	delete tmp4;

	return (0);
}
