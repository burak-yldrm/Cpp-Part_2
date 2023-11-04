#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include <fstream>

class Span
{
	private:
		unsigned int _maxCount;
		std::vector<int> _spanVector;

		Span();
	public:
		Span( unsigned int maxCount );
		Span( const Span& copy );
		~Span();

		Span &operator=(const Span& assigment);

		void addNumber( int number );

		int shortestSpan();
		int longestSpan();

		void fill( void );

		// Fills the elements in the Vector into a text document
		void fillTempValue( void );
};
