#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class CheckInputType
{
	public:
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);
		static bool isInteger(const std::string& str);
		static bool isNaN(const std::string& str);
	
	private:
		CheckInputType();
		CheckInputType(CheckInputType const &other);
		CheckInputType &operator=(CheckInputType const &other);
		~CheckInputType();
};