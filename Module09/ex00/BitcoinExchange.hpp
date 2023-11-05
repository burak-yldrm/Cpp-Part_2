#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>


#define RATE_DB "./data.csv"

class BitcoinExchange
{
	private:
		std::map< std::string, float > _btcDb;

		BitcoinExchange( const BitcoinExchange& copy );
		BitcoinExchange& operator=( const BitcoinExchange& copy );

		void dbConnection( const std::string& externalConnectionString );
		void dbRead( std::ifstream& internalDatabase );

		bool dateFormatCheck( const std::string& dateValue );
		bool dateValidityCheck( const std::string& date);
		bool rateValidityCheck( const std::string& value );

		float findNearestRate( const std::string& date );
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void exchangeResult( const std::string& externalDatabase );
};
