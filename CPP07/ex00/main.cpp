#include "whatever.hpp"
#include "Rank.hpp"
#include <iostream>

template <typename T>
static void	test(T &a, T &b)
{
	std::cout << "Test with: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swapped: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "=======================================" << std::endl;
}

int	main(void)
{
	int		i1 = 2;
	int		i2 = 3;
	test(i1, i2);

	float	f1 = 42.0f;
	float	f2 = 4.2f;
	test(f1, f2);


	char	c1 = 'c';
	char	c2 = 'C';
	test(c1, c2);

	std::string s1 = "Tokyo";
	std::string s2 = "Kyoto";
	test(s1, s2);

	int	*p1 = new int(42);
	int	*p2 = new int(-42);
	test(p1, p2);
	delete p1;
	delete p2;

	bool	b1 = true;
	bool	b2 = false;
	test(b1, b2);

	Rank	r1 = Rank(1);
	Rank	r2 = Rank(2);
	test(r1, r2);
}
