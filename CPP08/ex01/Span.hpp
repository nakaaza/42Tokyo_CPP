#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span {

protected:


private:
	Span();

	unsigned int		_max_size;
	std::vector<int>	_data;

public:
	Span(const Span &src);
	Span(const unsigned int N);
	Span &operator=(const Span &rhs);
	~Span();

	void			addNumber(int val);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	// TODO: addNumbers with range iterator

	class AlreadyFull: public std::exception
	{
		public:
			virtual const char* what() const throw();
	}
};

#endif // SPAN_HPP
