#include "TypeDetector.hpp"
#include <limits>
#include <cmath>

TypeDetector::Type	TypeDetector::detect(const std::string &target, double *dVal)
{
	char	*end;
	*dVal = strtod(target.c_str(), &end);
	if (target == "")
		return kINVALID;
	if (detectChar(target))
		return kCHAR;
	if (detectInt(*dVal, end))
		return kINT;
	if (detectFloat(end))
		return kFLOAT;
	if (detectDouble(end))
		return kDOUBLE;
	return kINVALID;
}

bool	TypeDetector::detectChar(const std::string &target)
{
	return (target.size() == 1 && !isdigit(target[0]));
}

bool	TypeDetector::detectInt(double dVal, char *end)
{
	if (*end != '\0')
		return false;
	if (dVal > static_cast<double>(std::numeric_limits<int>::max())
		|| dVal < static_cast<double>(std::numeric_limits<int>::min()))
		return false;
	if (dVal != static_cast<int>(dVal))
		return false;
	return true;
}

bool	TypeDetector::detectFloat(char *end)
{
	if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0')
		return true;
	return false;
}

bool	TypeDetector::detectDouble(char *end)
{
	if (*end == '\0')
		return true;
	return false;
}
