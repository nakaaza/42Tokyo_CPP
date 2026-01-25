#include "ScalarConverter.hpp"
#include "TypeDetector.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <limits>

void	printChar(char val, bool impossible = false)
{
	std::cout << "char: ";
	if (impossible)
		std::cout << "impossible";
	else if (std::isprint(val))
		std::cout << "'" << val << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	printInt(int val, bool impossible = false)
{
	std::cout << "int: ";
	if (impossible)
		std::cout << "impossible";
	else
		std::cout << val;
	std::cout << std::endl;
}

void	printFloat(double val, bool impossible = false)
{
	std::cout << "float: ";
	if (impossible)
		std::cout << "impossible";
	else {
		int   rounded = static_cast<int>(val);
		if (val == rounded)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << val << 'f';
		std::cout.unsetf(std::ios::fixed);
	}
	std::cout << std::endl;
}

void	printDouble(double val)
{
	std::cout << "double: ";
	int rounded = static_cast<int>(val);
	if (val == rounded)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << val;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::endl;
}

void	convertChar(const std::string &target)
{
	unsigned char val = target[0];
	printChar(static_cast<unsigned char>(val));
	printInt(static_cast<int>(val));
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertInt(double dVal)
{
	int val = static_cast<int>(dVal);
	printChar(static_cast<unsigned char>(val));
	printInt(static_cast<int>(val));
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertFloat(double dVal)
{
	float val = static_cast<float>(dVal);
	bool impossible = (std::isnan(val) || std::isinf(val)
						|| dVal > std::numeric_limits<int>::max()
						|| dVal < std::numeric_limits<int>::min());
	printChar(static_cast<unsigned char>(val), impossible);
	printInt(static_cast<int>(val), impossible);
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertDouble(double val)
{
	bool impossible = (std::isnan(val) || std::isinf(val)
						|| val > std::numeric_limits<int>::max()
						|| val < std::numeric_limits<int>::min());
	printChar(static_cast<unsigned char>(val), impossible);
	printInt(static_cast<int>(val), impossible);
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	ScalarConverter::convert(const std::string &target)
{
	double				dVal;
	TypeDetector::Type	detectedType = TypeDetector::detect(target, &dVal);

	switch (detectedType)
	{
		case TypeDetector::kCHAR:
			convertChar(target);
			break;
		case TypeDetector::kINT:
			convertInt(dVal);
			break;
		case TypeDetector::kFLOAT:
			convertFloat(dVal);
			break;
		case TypeDetector::kDOUBLE:
			convertDouble(dVal);
			break;
		default:
			std::cout << "Couldn't detect type of \"" << target << "\"" << std::endl;
			break;
	}
}
