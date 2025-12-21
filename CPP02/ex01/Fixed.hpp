#ifndef FIXED_HPP
# define FIXED_HPP

# include <limits>
# include <iostream>

# define FRAC_BITS 8
# define FIXED_MAX std::numeric_limits<int>::max() >> FRAC_BITS
# define FIXED_MIN std::numeric_limits<int>::min() >> FRAC_BITS

class Fixed {

private:
	const static int	frac_bits;
	int					val;

public:
	Fixed();
	Fixed(const int ini_val);
	Fixed(const float ini_val);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;


};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
