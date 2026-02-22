#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

typedef std::map<std::string, double>	t_data;

class BitcoinExchange {

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	static	t_data	data;

public:
	static void		init_data(const std::string &filename);
	static void		execute(const std::string& filename);
	static double	get_rate(const std::string& date);
};

#endif // BITCOINEXCHANGE_HPP
