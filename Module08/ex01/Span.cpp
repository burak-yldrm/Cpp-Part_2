#include "Span.hpp"

Span::Span( unsigned int maxCount )
{
	srand(static_cast<unsigned>(time(0)));
	if ( maxCount <= 1)
		throw std::length_error("Size not valid!");
	_maxCount = maxCount;
}

Span::~Span() {}

Span::Span(const Span& copy)
{
	_spanVector = copy._spanVector;
	_maxCount = copy._maxCount;
}

void Span::addNumber( int number )
{
	if ( _spanVector.size() > _maxCount )
		throw std::out_of_range("Index limit exceeded!");
	else
		_spanVector.push_back(number);
}

int Span::shortestSpan()
{
	if ( _spanVector.size() <= 1 )
		throw std::runtime_error("Value count not valid!");

	std::sort( _spanVector.begin(), _spanVector.end() );

	int diffrence = _spanVector[1] - _spanVector[0];

	for ( unsigned long index = 0; index < _spanVector.size() - 1; index++ )
	{
		for ( unsigned long index2 = index + 1; index2 < _spanVector.size(); index2++ )
		{
			if ( _spanVector[index2] - _spanVector[index] < diffrence )
				diffrence = _spanVector[index2] - _spanVector[index];
		}
	}
	return diffrence;
}

int Span::longestSpan()
{
	if ( _spanVector.size() <= 1 )
		throw std::runtime_error("Value count not valid!");

	std::sort( _spanVector.begin(), _spanVector.end() );

	int diffrence = _spanVector[_maxCount - 1] - _spanVector[0];

	return diffrence;
}

Span& Span::operator=(const Span& assignment) {
	if (this != &assignment) {
		_spanVector = assignment._spanVector;
		_maxCount = assignment._maxCount;
	}
	return *this;
}

static	int	randomInt(size_t size)
{
	int i;

	i = (rand() % size) + 1;
	return (i);
}

void	Span::fill(void)
{
	size_t	start;

	start = _spanVector.size();
	while (start < _maxCount)
	{
		usleep(50);
		_spanVector.push_back(randomInt(_maxCount));
		start++;
	}
}

void	Span::fillTempValue( void )
{
	std::ofstream tempFile("randomNumber.txt");

	if (tempFile.is_open())
	{
		for (std::vector<int>::iterator tempVecIt = _spanVector.begin(); tempVecIt != _spanVector.end(); tempVecIt++)
		{
			tempFile << *tempVecIt << "\n";
		}

		tempFile.close();
		std::cout << "Numbers written on file!" << std::endl;
	} else {
		std::cerr << "File could not be opened!" << std::endl;
	}
}
