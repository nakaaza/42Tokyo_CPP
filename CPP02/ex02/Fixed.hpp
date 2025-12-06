#ifndef FIXED_HPP
# define FIXED_HPP

# include <limits>

# define FRAC_BITS 8
# define FIXED_MAX std::numeric_limits<int>::max() >> FRAC_BITS
# define FIXED_MIN std::numeric_limits<int>::min() >> FRAC_BITS
# define FIXED_EPS 1

class Fixed {

private:
	const static int	frac_bits;
	int					val;

public:
	Fixed();
	Fixed(const int ini_val);
	Fixed(const float ini_val);
	Fixed(const Fixed &src);
	Fixed	&operator=(const Fixed &rhs);
	~Fixed();
	bool	operator>(const Fixed &rhs);
	bool	operator<(const Fixed &rhs);
	bool	operator>=(const Fixed &rhs);
	bool	operator<=(const Fixed &rhs);
	bool	operator==(const Fixed &rhs);
	bool	operator!=(const Fixed &rhs);

	Fixed	operator+(const Fixed &rhs);
	Fixed	operator-(const Fixed &rhs);
	Fixed	operator*(const Fixed &rhs);
	Fixed	operator/(const Fixed &rhs);

	Fixed	&operator++();
	Fixed	&operator--();
	// TOOD: prefix increments
	// Fixed	&operator();
	// Fixed	&operator();

	static Fixed	&min(Fixed &f1, Fixed &f2);
	static Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed	&max(Fixed &f1, Fixed &f2);
	static Fixed	&max(const Fixed &f1, const Fixed &f2);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;


};

// std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
