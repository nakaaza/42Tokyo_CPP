#ifndef FIXED_HPP
# define FIXED_HPP

# define FRAC_BITS 8;

class Fixed {

private:
	const static int	frac_bits;
	int					val;

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

#endif
