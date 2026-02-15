#ifndef RPN_HPP
# define RPN_HPP

#include <string>

class RPN {

protected:


private:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);
	~RPN();

	static bool	isNumber(const std::string &token, long &out);
	static bool isOperator(const std::string &token);

public:
	static long	evaluate(std::string formula);

};

#endif // RPN_HPP
