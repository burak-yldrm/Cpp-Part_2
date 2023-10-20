#pragma once

#include <iostream>

template < typename Type >
class Array
{
	private:
		Type* array;
		unsigned int nElements;

	public:
		Array() : array( new Type() ), nElements( 0 ) {};
		Array( unsigned int _nElements ) : array( new Type[_nElements] ), nElements( _nElements ) {};

		Array( const Array& ref) : array( new Type[ref.size()] ), nElements( ref.size() )
		{
			for ( unsigned int index = 0; index < nElements; index++ )
				array[index] = ref.array[index];
		};

		Array& operator=( const Array& ref )
		{
			if (this != &ref)
			{
				delete[] array;
				array = new Type[ref.size()];
				nElements = ref.size();
				for ( unsigned int index = 0; index < nElements; index++ )
					array[index] = ref.array[index];
			}
			return *this;
		}

		Type& operator[]( unsigned int index ) const
		{
			if ( index >= nElements )
				throw OutOfBoundsException();
			return array[index];
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index is out of bounds";
				}
		};

		unsigned int size( void ) const { return nElements; }
};

template < typename Type >
std::ostream& operator<<( std::ostream& out, const Array< Type >& array)
{
	for (unsigned int index = 0; index < array.size(); index++)
		out << array[index] << " ";
	return out;
}
