#include "Base.hpp"

Base*	generate( void )
{
	if ( std::rand() % 3 == 0 )
		return ( new A );
	else if ( std::rand() % 3 == 1 )
		return ( new B );
	else
		return ( new C );
}

void identify( Base* p )
{
	if ( dynamic_cast< A* >( p ) )
		std::cout << "A" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C" << std::endl;
}

void identify( Base& p )
{
	try
	{
		A& aRef = dynamic_cast< A& >(p);
		std::cout << "A" << "\n";
		( void )aRef;
	}
	catch(const std::exception& e) {}

	try
	{
		B& bRef = dynamic_cast< B& >(p);
		std::cout << "B" << "\n";
		( void )bRef;
	}
	catch(const std::exception& e) {}

	try
	{
		C& cRef = dynamic_cast< C& >(p);
		std::cout << "C" << "\n";
		( void )cRef;
	}
	catch(const std::exception& e) {}
}
