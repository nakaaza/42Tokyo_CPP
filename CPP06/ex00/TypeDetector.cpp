#include "TypeDetector.hpp"
#include <regex>

TypeDetector::Type	TypeDetector::detect(const std::string &target)
{
	if (detectChar(target))
		return kCHAR;
	if (detectInt(target))
		return kINT;
	if (detectFloat(target))
		return kFLOAT;
	if (detectDouble(target))
		return kDOUBLE;
	return kINVALID;
}

bool	TypeDetector::detectChar(const std::string &target)
{
	return (target.size() == 1 && !isdigit(target[0]));
}

bool	TypeDetector::detectInt(const std::string &target)
{
	std::string tmp	= target;
	size_t		i	= 0;
	if (tmp[0] == '-' || tmp[0] == '+')
		++i;
	while (i < tmp.size())
	{
		if (!isdigit(tmp[i]))
			return false;
		++i;
	}
	return true;
}

bool	TypeDetector::detectFloat(const std::string &target)
{
	std::string tmp	= target;
	size_t		i	= 0;
	bool		has_point = false;
	if (tmp[0] == '-' || tmp[0] == '+')
		++i;
	tmp = tmp.substr(i);
	if (tmp == "inff" || tmp == "nanf")
		return true;
	while (i < tmp.size() - 1)
	{
		if (!isdigit(tmp[i]))
		{
			if (!has_point && tmp[i] == '.')
				has_point = true;
			else
				return false;
		}
		++i;
	}
	return (tmp[i] == 'f');	
}

bool	TypeDetector::detectDouble(const std::string &target)
{
	std::string tmp	= target;
	size_t		i	= 0;
	bool		has_point = false;
	if (tmp[0] == '-' || tmp[0] == '+')
		++i;
	tmp = tmp.substr(i);
	if (tmp == "inf" || tmp == "nan")
		return true;
	while (i < tmp.size())
	{
		if (!isdigit(tmp[i]))
		{
			if (!has_point && tmp[i] == '.')
				has_point = true;
			else
				return false;
		}
		++i;
	}
	return true;	
}
