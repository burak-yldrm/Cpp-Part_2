#pragma once

#include <iostream>
#include <stack>

template < typename Type >
class MutantStack : public std::stack< Type >
{
	private:

	public:
		MutantStack( void ) : std::stack< Type >() {};
		MutantStack( MutantStack const& copy ) : std::stack< Type >( copy )
		{
			*this = copy;
		};

		~MutantStack() { };

		MutantStack &operator=( MutantStack const& assigmentSource )
		{
			std::stack< Type >::operator=( assigmentSource );
			return *this;
		}

		typedef typename std::stack< Type >::container_type::iterator iterator;

		// "c" is the special access token of the object under the stack object
		iterator begin( void )
		{
			return this->c.begin();
		}

		// "c" is the special access token of the object under the stack object
		iterator end( void )
		{
			return this->c.end();
		}
};
