#include "Rank.hpp"

Rank::Rank(unsigned int r): val(r) {}

Rank::Rank(const Rank &src) : val(src.val) {}

Rank &Rank::operator=(const Rank &rhs) {
	if (this != &rhs)
		this->val = rhs.val;
	return *this;
}

Rank::~Rank() {}

bool	Rank::operator>(const Rank &rhs) const {
	return (this->val < rhs.val);
}

bool	Rank::operator<(const Rank &rhs) const {
	return (this->val > rhs.val);
}

std::ostream &operator<<(std::ostream &os, const Rank &rank)
{
	os << rank.val;
	return (os);
}
