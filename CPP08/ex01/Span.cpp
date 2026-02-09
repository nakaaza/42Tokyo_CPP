#include "Span.hpp"
#include <iostream>
#include <stdexcept>

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
		throw std::length_error("Couldn't add number to _data because it is full.");
	_data.push_back(val);
}


const char*	Span::AlreadyFull::what() const throw() {
	return "ERROR: Couldn't add number to Span because it is already filled with _max_size numbers."
}
