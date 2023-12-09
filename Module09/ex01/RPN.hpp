#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		RPN();
		RPN( const RPN& copy );
		RPN &operator=( const RPN& copy );

		void	calculateValue ( std::stack<int>& stack );
		bool	checkArgument( std::string argv );
		bool	checkBigNumbers( std::string argv );
		std::stack<int>	st_pushBack( std::stack<int> *st );
		void	setArgument(char *argv);
	public:
		RPN(char* argv);
		~RPN();
};
