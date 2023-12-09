#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

static float stringToFloat( const std::string& str )
{
	std::istringstream iss( str );
	float value;

	iss >> value;
	if ( iss.fail() )
		throw std::invalid_argument( "Error: invalid internal database format." );
	return value;
}

static int stringToInt( const std::string& str )
{
	std::istringstream iss( str );
	int value;

	iss >> value;
	if ( iss.fail() )
		throw std::invalid_argument( "Error: invalid internal database format." );
	return value;
}

void BitcoinExchange::dbConnection( const std::string& externalConnectionString )
{
	std::ifstream externalDb( externalConnectionString.c_str(), std::ifstream::in );
	std::ifstream internalDb( RATE_DB, std::ifstream::in );

	if ( externalDb.is_open() != true || internalDb.is_open() != true )
		throw std::ios_base::failure( "Error: could not open file." );

	dbRead( internalDb );
}

void BitcoinExchange::dbRead( std::ifstream& internalDatabase )
{
	std::string tempLine;
	unsigned long delimiterPos;

	std::getline( internalDatabase, tempLine );
	if ( tempLine != "date,exchange_rate" )
		throw std::invalid_argument( "Error: invalid internal database format." );
	while (std::getline( internalDatabase, tempLine ))
	{
		delimiterPos = tempLine.find( ',' );
		if ( delimiterPos == std::string::npos || std::count(tempLine.begin(), tempLine.end(), '-') != 2 )
			throw std::invalid_argument( "Error: invalid internal database format. => " + tempLine );
		_btcDb[ tempLine.substr( 0, delimiterPos ) ] = stringToFloat( tempLine.substr( delimiterPos + 1 ) );
	}
}

bool BitcoinExchange::dateFormatCheck( const std::string& dateValue )
{
	if (dateValue.empty())
		return false;

	if ( dateValue.find( '-' ) == std::string::npos 
		|| dateValue.find( '-', dateValue.find( '-' ) + 1 ) == std::string::npos
		|| dateValue.find_first_not_of( "0123456789.-" ) == std::string::npos )
	{
		std::cerr << "Error: bad input => " << dateValue << std::endl;	
		return false;
	}
	return true;
}

bool BitcoinExchange::dateValidityCheck( const std::string& date )
{
	std::istringstream iss( date );
	std::string tempString;
	int year, month, day;
	int dateCount = 0;

	if ( std::getline( iss, tempString, '-' ) )
	{
		dateCount++;
		year = stringToInt( tempString );
		if (year < 2009 || year > 2022)
		{
			std::cerr << "Error: database does not include this year => " << date << std::endl;
			return false;
		}
	}
	
	if ( std::getline( iss, tempString, '-' ) )
	{
		dateCount++;
		month = stringToInt( tempString );
		if ( month < 1 || month > 12 )
		{
			std::cerr << "Error: bad month => " << date << std::endl;
			return false;
		}
	}

	if ( std::getline( iss, tempString, '-' ) )
	{
		dateCount++;
		day = stringToInt( tempString );
		if ( day < 1 || day > 31 
			|| ( month == 2 && day > 28 )
			|| ( month == 4 && day > 30 )
			|| ( month == 6 && day > 30 )
			|| ( month == 9 && day > 30 )
			|| ( month == 11 && day > 30 ) )
		{
			std::cerr << "Error: bad day => " << date << std::endl;
			return false;
		}
	}

	if ( dateCount != 3 )
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::rateValidityCheck( const std::string& value )
{
	std::string rateString[2] = { value.substr( 0, value.find( '|' ) ), value.substr( value.find( '|' ) + 1 ) };
	if ( rateString[1].empty() || rateString[1].find_first_not_of( "0123456789.-" ) == std::string::npos
		|| rateString[1].at(1) == '.' || rateString[1].find('.', rateString[1].size() - 1) != std::string::npos )
		std::cerr << "Error: invalid rate => " << rateString[1] << std::endl;
	else if (rateString[1].at(1) == '-')
		std::cerr << "Error: not a positive number." << std::endl;
	else if (rateString[1].size() > 10 || (rateString[1].size() == 10 && rateString[1] > "2147483647"))
		std::cerr << "Error: too large a number." << std::endl;
	else
		return true;
	return false;
}

void BitcoinExchange::exchangeResult( const std::string& externalDatabase )
{
	std::string tempLine;

	std::ifstream externalDb( externalDatabase.c_str(), std::ifstream::in );
	std::ifstream internalDb( RATE_DB, std::ifstream::in );

	dbConnection( externalDatabase );

	std::getline( externalDb, tempLine );
	while ( std::getline( externalDb, tempLine ) )
	{
		if ( dateFormatCheck( tempLine ) == false )
			continue;
		if ( dateValidityCheck( tempLine ) == false )
			continue;
		if ( rateValidityCheck( tempLine ) == false )
			continue;
		std::cout << tempLine << " => " << findNearestRate( tempLine.substr( 0, tempLine.find( ' ' ) ) ) * stringToFloat( tempLine.substr( tempLine.find( '|' ) + 1) ) << std::endl;
	}
}

float BitcoinExchange::findNearestRate( const std::string& date )
{
	std::map<std::string, float>::iterator it = _btcDb.lower_bound( date );

	if ( it != _btcDb.end() && it->first == date )
		return it->second;

	if ( it != _btcDb.begin() )
	{
		std::map<std::string, float>::iterator prevIt = it;
		--prevIt;
		
		if ( it == _btcDb.end() || ( it != _btcDb.end() && ( date > it->first || ( it->first > date && prevIt->first < date ) ) ) )
			it = prevIt;
	}

	return it->second;
}
