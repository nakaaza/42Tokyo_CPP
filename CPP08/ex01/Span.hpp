#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span {

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
	unsigned long	shortestSpan() const;
	unsigned long	longestSpan() const;

	template <typename Iterator>
	void			addNumbers(Iterator head, Iterator tail)
	{
		unsigned int	add_count = static_cast<unsigned int>(std::distance(head, tail));
		if (add_count > _max_size - _data.size())
			throw Span::ExceedsCapacity();
		_data.insert(_data.end(), head, tail);
	}

	class AlreadyFull: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class ExceedsCapacity: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class SpanNotFound: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif // SPAN_HPP
