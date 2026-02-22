#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: Invalid argument(s)." << std::endl
				  << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::string	db_filename = "data.csv";
	BitcoinExchange::init_data(db_filename);

	std::string	input_filename = argv[1];
	try {
		BitcoinExchange::execute(input_filename);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
