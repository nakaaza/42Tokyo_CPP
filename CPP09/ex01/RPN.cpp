#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

bool	RPN::isNumber(const std::string &token, long &out)
{
	char	*end;
	long	val = strtol(token.c_str(), &end, 10);

	if (*end != '\0')
		return false;
	out = val;
	return true;
}

bool	RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

long	RPN::evaluate(std::string formula)
{
	std::istringstream	iss(formula);
	std::string			token;
	std::stack<long>		st;

	while (iss >> token)
	{
		if (iss.fail())
			throw std::runtime_error("Error: Invalid token.");

		long	val;
		if (RPN::isNumber(token, val))
			st.push(val);
		else if (RPN::isOperator(token))
		{
			if (st.size() < 2)
				throw std::runtime_error("Error: Could't perform operation because numeric arguments less than 2.");
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
			if (token == "+") st.push(a + b);
			else if (token == "-") st.push(a - b);
			else if (token == "*") st.push(a * b);
			else if (token == "/") {
				if (b == 0)
					throw std::runtime_error("Error: Division by zero.");
				st.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error: Invalid token.");
	}
	if (st.size() != 1)
		throw std::runtime_error("Error: Could't complete operation.");
	return st.top();
}
