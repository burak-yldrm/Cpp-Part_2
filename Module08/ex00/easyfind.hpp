#pragma once

#include <iostream>
#include <algorithm>

/**
 * Function: Searches for the integer value given as a parameter in the template
 * Return: Operation is succesfull return iterator if no occurrence is found, return exception.
*/
template <typename Type>
typename Type::iterator easyfind(Type& container, int searchValue)
{
	typename Type::iterator it = std::find(container.begin(), container.end(), searchValue);

	if (it != container.end())
		return it;
	else
		throw std::runtime_error("Value not found in container");
}
