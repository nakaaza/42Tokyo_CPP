#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>

Span::Span(const Span &src):
	_max_size(src._max_size),
	_data(src._data)
{}

Span::Span(const unsigned int N): _max_size(N) {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_max_size = rhs._max_size;
		_data = rhs._data;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int val)
{
	if (_data.size() >= _max_size)
		throw AlreadyFull();
	_data.push_back(val);
}

unsigned long	Span::shortestSpan() const
{
	if (_data.size() <= 1)
		throw SpanNotFound();
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	unsigned long	ss = std::numeric_limits<unsigned long>::max();
	for (std::vector<int>::size_type i = 0; i + 1 < tmp.size(); i++) {
		unsigned long s = tmp[i + 1] - tmp[i];
		if (s < ss)
			ss = s;
	}
	return ss;
}

unsigned long	Span::longestSpan() const
{
	if (_data.size() <= 1)
		throw SpanNotFound();
	return *std::max_element(_data.begin(), _data.end())
		   - *std::min_element(_data.begin(), _data.end());
}

const char*	Span::AlreadyFull::what() const throw() {
	return "ERROR: Couldn't add number to Span because it is already filled with _max_size numbers.";
}

const char*	Span::ExceedsCapacity::what() const throw() {
	return "ERROR: Couldn't add numbers to Span because it would exceed capacity(_max_size).";
}

const char*	Span::SpanNotFound::what() const throw() {
	return "ERROR: Couldn't find span because no numbers or only one number stored.";
}
