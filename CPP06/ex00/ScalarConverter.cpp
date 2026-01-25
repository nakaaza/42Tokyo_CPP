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

void	printFloat(double val)
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

void	printDouble(double val)
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

void	convertChar(const std::string &target)
{
	unsigned char val = target[0];
	printChar(static_cast<unsigned char>(val));
	printInt(static_cast<int>(val));
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertInt(const std::string &target)
{
	char *end;
	int val = strtol(target.c_str(), &end, 10);
	printChar(static_cast<unsigned char>(val));
	printInt(static_cast<int>(val));
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertFloat(const std::string &target)
{
	char *end;
	float val = strtof(target.c_str(), &end);
	bool impossible = (std::isnan(val) || std::isinf(val));
	printChar(static_cast<unsigned char>(val), impossible);
	printInt(static_cast<int>(val), impossible);
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	convertDouble(const std::string &target)
{
	char *end;
	double val = strtod(target.c_str(), &end);
	bool impossible = (std::isnan(val) || std::isinf(val));
	printChar(static_cast<unsigned char>(val), impossible);
	printInt(static_cast<int>(val), impossible);
	printFloat(static_cast<float>(val));
	printDouble(static_cast<double>(val));
}

void	ScalarConverter::convert(const std::string &target)
{
	TypeDetector::Type	detectedType = TypeDetector::detect(target);

	switch (detectedType)
	{
		case TypeDetector::kCHAR:
			std::cout << "char detected" << std::endl;
			convertChar(target);
			break;
		case TypeDetector::kINT:
			std::cout << "int detected" << std::endl;
			convertInt(target);
			break;
		case TypeDetector::kFLOAT:
			std::cout << "float detected" << std::endl;
			convertFloat(target);
			break;
		case TypeDetector::kDOUBLE:
			std::cout << "double detected" << std::endl;
			convertDouble(target);
			break;
		default:
			std::cout << "invalid detected" << std::endl;
			break;
	}
}
