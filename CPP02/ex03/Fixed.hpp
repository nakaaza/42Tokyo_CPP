#ifndef FIXED_HPP
# define FIXED_HPP

# include <limits>
# include <iostream>

# ifndef DEBUG
#  define DEBUG false
# endif

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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &rhs) const ;
	bool	operator<(const Fixed &rhs) const ;
	bool	operator>=(const Fixed &rhs) const ;
	bool	operator<=(const Fixed &rhs) const ;
	bool	operator==(const Fixed &rhs) const ;
	bool	operator!=(const Fixed &rhs) const ;

	Fixed	operator+(const Fixed &rhs) const ;
	Fixed	operator-(const Fixed &rhs) const ;
	Fixed	operator*(const Fixed &rhs) const ;
	Fixed	operator/(const Fixed &rhs) const ;
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
