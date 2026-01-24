#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <limits>

void	print_char(double val)
{
	std::cout << "char: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible";
	else {
		char casted = static_cast<unsigned int>(val);
		if (std::isprint(casted))
			std::cout << "'" << casted << "'";
		else
			std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

void	print_int(double val)
{
	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val)
		|| val < std::numeric_limits<int>::min()
		|| val > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else {
		int casted = static_cast<int>(val);
		std::cout << casted;
	}
	std::cout << std::endl;
}

void	print_float(double val)
{
	std::cout << "float: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << val << 'f';
	else if (val < -std::numeric_limits<float>::max()
			 || val > std::numeric_limits<float>::max() )
		std::cout << "impossible";
	else {
		float casted = static_cast<float>(val);
		int   rounded = static_cast<int>(val);
		if (casted == rounded)
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::fixed << std::setprecision(6);
		std::cout << casted << 'f';
	}
	std::cout << std::endl;
}

void	print_double(double val)
{
	std::cout << "double: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << val;
	else {
		int rounded = static_cast<int>(val);
		if (val == rounded)
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::fixed << std::setprecision(6);
		std::cout << val;
	}
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &target)
{
	char	*end = NULL;
	double	val = strtod(target.c_str(), &end);

	print_char(val);
	print_int(val);
	print_float(val);
	print_double(val);
}
