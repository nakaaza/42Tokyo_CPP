#include "utils.hpp"

std::string	trunc_to_10(std::string s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	else
		return (std::string(10 - s.length(), ' ') + s);
}
