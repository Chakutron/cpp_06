#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc == 2) 
    	ScalarConverter::convert(argv[1]);    
	else
		std::cout << CYAN << " - Usage: " << BLUE << "./ex00 <literal string>" << NC << std::endl;
    return (0);
}