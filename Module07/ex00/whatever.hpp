#pragma once

#include <iostream>

template< typename Type >
void	swap( Type& firstValue, Type& secondValue )
{
	Type temp = firstValue;
	firstValue = secondValue;
	secondValue = temp;
}

template< typename Type >
Type	min( Type& firstValue, Type& secondValue )
{
	return ( firstValue < secondValue ? firstValue : secondValue );
}

template< typename Type >
Type	max( Type& firstValue, Type& secondValue )
{
	return ( firstValue > secondValue ? firstValue : secondValue );
}
