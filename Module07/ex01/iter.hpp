#pragma once

#include <iostream>

template < typename Type >
void iter( Type *array, size_t length, void ( *function )( Type & ) )
{
	for (size_t index = 0; index < length; index++)
	{
		function( array[index] );
	}
	std::cout << std::endl;
}

template < typename Type>
void printArray( Type &elem )
{
	std::cout << elem << "\n";
}

