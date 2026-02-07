#ifndef RANK_HPP
# define RANK_HPP

# include <ostream>

class Rank {
private:

public:
	Rank();
	Rank(unsigned int r);
	Rank(const Rank &src);
	Rank &operator=(const Rank &rhs);
	~Rank();

	bool	operator>(const Rank &rhs) const ;
	bool	operator<(const Rank &rhs) const ;

	unsigned int	val;
};

std::ostream &operator<<(std::ostream &os, const Rank &rank);

#endif // RANK_HPP
