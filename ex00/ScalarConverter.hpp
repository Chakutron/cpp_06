#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define CYAN "\e[36m"
#define NC "\e[0m"

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(std::string const &str);	
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		static int literalType(std::string const &str);
};