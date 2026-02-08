#include "Span.hpp"
#include <iostream>

Span::Span(const Span &src) {
	// TODO
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span::Span(const unsigned int N): _size(N) {}

Span &Span::operator=(const Span &rhs) {
	// TODO
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &rhs) {
		// TODO: copy member variables here
	}
	return *this;
}

Span::~Span() {}
