#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

int	ScalarConverter::literalType(std::string const &str)
{
	if (str.size() == 1 && (str[0] < 48 || str[0] > 57))
		return (1);
	else if (str.size() == 1 && str[0] >= 48 && str[0] <= 57)
		return (2);
	else
	{
		long unsigned int	i = 0;
		long unsigned int	n = 0;
		long unsigned int	d = 0;
		long unsigned int	s = 0;
		long unsigned int	f = 0;
		if (str[0] == '-')
		{
			n++;
			i++;
		}
		while (i < str.size())
		{
			if (str[i] == '-')
				n++;
			else if (str[i] == '.' && str[i - 1] >= 48 && str[i - 1] <= 57)
				s++;
			else if (str[i] == 'f')
				f++;
			else if (str[i] >= 48 && str[i] <= 57)
				d++;
			i++;
		}
		if (n <= 1 && s == 0 && f == 0 && str.size() == (n + d) && str[i - 1] >= 48 && str[i - 1] <= 57)
		{
			if (std::atol(str.c_str()) >= INT_MIN && std::atol(str.c_str()) <= INT_MAX)
				return (3);
			else
				return (8);
		}
		else if (n <= 1 && s == 1 && f == 1 && str.size() == (n + d + s + f) && str[i - 2] >= 48 && str[i - 2] <= 57 && str[i - 1] == 'f')
		{
			if (std::atol(str.c_str()) >= INT_MIN && std::atol(str.c_str()) <= INT_MAX)
				return (4);
			else
				return (8);
		}
		else if (n <= 1 && s == 1 && f == 0 && str.size() == (n + d + s) && str[i - 1] >= 48 && str[i - 1] <= 57)
		{
			if (std::atol(str.c_str()) >= INT_MIN && std::atol(str.c_str()) <= INT_MAX)
				return (5);
			else
				return (8);
		}
	}
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (6);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (7);
	return (0);
}

void ScalarConverter::convert(std::string const &str)
{
    std::cout << "------------------------------------------------" << std::endl;
	int	i = ScalarConverter::literalType(str);
	switch (i)
	{
	case 1:
		if (str[0] >= 32 && str[0] <= 126)
			std::cout << YELLOW << "- Printable CHAR detected" << NC << std::endl;
		else
			std::cout << YELLOW << "- Non printable CHAR detected" << NC << std::endl;
		std::cout << "- Char: '" << GREEN << str[0] << NC << "'" << std::endl;
		std::cout << "- Int: " << GREEN << static_cast<int>(str[0]) << NC << std::endl;
		std::cout << "- Float: " << GREEN << static_cast<float>(str[0]) << ".0f" << NC << std::endl;
		std::cout << "- Double: " << GREEN << static_cast<double>(str[0]) << ".0" << NC << std::endl;
		break;
	case 2:
		std::cout << YELLOW << "- INTEGER digit detected" << NC << std::endl;
		std::cout << "- Char: " << RED << "Non displayable" << NC << std::endl;
		std::cout << "- Int: " << GREEN << std::atoi(str.c_str()) << NC << std::endl;
		std::cout << "- Float: " << GREEN << static_cast<float>(std::atoi(str.c_str())) << ".0f" << NC << std::endl;
		std::cout << "- Double: " << GREEN << static_cast<double>(std::atoi(str.c_str())) << ".0" << NC << std::endl;
		break;
	case 3:
		std::cout << YELLOW << "- INTEGER detected" << NC << std::endl;
		if (std::atoi(str.c_str()) >= 32 && std::atoi(str.c_str()) <= 126)
			std::cout << "- Char: '" << GREEN << static_cast<char>(std::atoi(str.c_str())) << NC << "'" << std::endl;
		else
			std::cout << "- Char: " << RED << "Non displayable" << NC << std::endl;
		std::cout << "- Int: " << GREEN << std::atoi(str.c_str()) << NC << std::endl;
		std::cout << "- Float: " << GREEN << static_cast<float>(std::atoi(str.c_str())) << ".0f" << NC << std::endl;
		std::cout << "- Double: " << GREEN << static_cast<double>(std::atoi(str.c_str())) << ".0" << NC << std::endl;
		break;
	case 4:
		std::cout << YELLOW << "- FLOAT detected" << NC << std::endl;
		if (std::atoi(str.c_str()) >= 32 && std::atoi(str.c_str()) <= 126)
			std::cout << "- Char: '" << GREEN << static_cast<char>(std::atoi(str.c_str())) << NC << "'" << std::endl;
		else
			std::cout << "- Char: " << RED << "Non displayable" << NC << std::endl;
		std::cout << "- Int: " << GREEN << static_cast<int>(std::atof(str.c_str())) << NC << std::endl;
		if (std::atof(str.c_str()) - std::atoi(str.c_str()) == 0)
		{
			std::cout << "- Float: " << GREEN << static_cast<float>(std::atof(str.c_str())) << ".0f" << NC << std::endl;
			std::cout << "- Double: " << GREEN << std::atof(str.c_str()) << ".0" << NC << std::endl;
		}
		else
		{
			std::cout << "- Float: " << GREEN << static_cast<float>(std::atof(str.c_str())) << "f" << NC << std::endl;
			std::cout << "- Double: " << GREEN << std::atof(str.c_str()) << NC << std::endl;
		}
		break;
	case 5:
		std::cout << YELLOW << "- DOUBLE detected" << NC << std::endl;
		if (std::atoi(str.c_str()) >= 32 && std::atoi(str.c_str()) <= 126)
			std::cout << "- Char: '" << GREEN << static_cast<char>(std::atoi(str.c_str())) << NC << "'" << std::endl;
		else
			std::cout << "- Char: " << RED << "Non displayable" << NC << std::endl;
		std::cout << "- Int: " << GREEN << static_cast<int>(std::atof(str.c_str())) << NC << std::endl;
		if (std::atof(str.c_str()) - std::atoi(str.c_str()) == 0)
		{
			std::cout << "- Float: " << GREEN << std::atof(str.c_str()) << ".0f" << NC << std::endl;
			std::cout << "- Double: " << GREEN << static_cast<double>(std::atof(str.c_str())) << ".0" << NC << std::endl;
		}
		else
		{
			std::cout << "- Float: " << GREEN << std::atof(str.c_str()) << "f" << NC << std::endl;
			std::cout << "- Double: " << GREEN << static_cast<double>(std::atof(str.c_str())) << NC << std::endl;
		}
		break;
	case 6:
		std::cout << YELLOW << "- Special value detected" << NC << std::endl;
		std::cout << "- Char: " << RED << "impossible" << NC << std::endl;
		std::cout << "- Int: " << RED << "impossible" << NC << std::endl;
		std::cout << "- Float: " << GREEN << str << NC << std::endl;
		if (str == "-inff")
			std::cout << "- Double: " << GREEN << "-inf" << NC << std::endl;
		else if (str == "+inff")
			std::cout << "- Double: " << GREEN << "+inf" << NC << std::endl;
		else if (str == "nanf")
			std::cout << "- Double: " << GREEN << "nan" << NC << std::endl;
		break;
	case 7:
		std::cout << YELLOW << "- Special value detected" << NC << std::endl;
		std::cout << "- Char: " << RED << "impossible" << NC << std::endl;
		std::cout << "- Int: " << RED << "impossible" << NC << std::endl;
		if (str == "-inf")
			std::cout << "- Float: " << GREEN << "-inff" << NC << std::endl;
		else if (str == "+inf")
			std::cout << "- Float: " << GREEN << "+inff" << NC << std::endl;
		else if (str == "nan")
			std::cout << "- Float: " << GREEN << "nanf" << NC << std::endl;
		std::cout << "- Double: " << GREEN << str << NC << std::endl;
		break;
	case 8:
		std::cout << RED << "- This number exceeds the limits" << NC << std::endl;
		break;
	default:
		std::cout << RED << "- Literal type not detected" << NC << std::endl;
		break;
	}
    std::cout << "------------------------------------------------" << std::endl;
}