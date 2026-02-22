#include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

t_data	BitcoinExchange::data;

void	BitcoinExchange::init_data(const std::string &filename) {
	std::ifstream ifs(filename.c_str());
	if (!ifs)
		throw std::runtime_error("failed to open file: " + filename);

	std::string line;

	if (!std::getline(ifs, line))
		return;

	while (std::getline(ifs, line))
	{
		if (line.empty())
			continue;

		std::string date, valueStr;

		std::stringstream ss(line);
		if (!std::getline(ss, date, ','))
			continue;
		if (!std::getline(ss, valueStr))
			continue;

		if (date.empty() || valueStr.empty())
			continue;

		std::stringstream vs(valueStr);
		double value;
		vs >> value;

		data[date] = value;
	}

	return;
}

static bool is_valid_date(const std::string &date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year, month, day;
	std::stringstream ss(date);
	char dash1, dash2;
	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail())
		return false;

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

	return true;
}

static bool is_valid_number(const std::string &num_str, double &value)
{
	if (num_str.empty())
		return false;

	std::stringstream ss(num_str);

	ss >> value;

	if (ss.fail() || !(ss >> std::ws).eof())
		return false;

	return true;
}

static bool is_valid_line(const std::string &line, std::string& date, double &val)
{
	std::string::size_type pos = line.find(" | ");
	if (pos == std::string::npos) {
		std::cerr << "ERROR: invalid input => " << line << std::endl;
		return false;
	}

	std::string date_str = line.substr(0, pos);
	std::string val_str = line.substr(pos + 3);

	if (!is_valid_date(date_str)) {
		std::cerr << "ERROR: invalid date => " << date_str << std::endl;
		return false;
	}

	if (!is_valid_number(val_str, val)) {
		std::cerr << "ERROR: invalid number => " << val_str << std::endl;
		return false;
	}

	if (val < 0) {
		std::cerr << "ERROR: not a positive number => " << val_str << std::endl;
		return false;
	}

	if (val > 1000) {
		std::cerr << "ERROR: too large a number => " << val_str << std::endl;
		return false;
	}

	date = date_str;
	return true;
}

void	BitcoinExchange::execute(const std::string& filename) {
	std::ifstream ifs(filename.c_str());
	if (!ifs)
		throw std::runtime_error("failed to open file: " + filename);

	std::string line;

	if (!std::getline(ifs, line))
		return;

	while (std::getline(ifs, line))
	{
		if (line.empty())
			continue;
		std::string	date;
		double		val;
		if (!is_valid_line(line, date, val))
			continue;

		double	rate = get_rate(date);
		if (rate < 0) {
			std::cerr << "ERROR: rate not found  => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << val << " = " << val * rate << std::endl;
	}

	return;
}

double BitcoinExchange::get_rate(const std::string& date)
{
	if (data.empty())
		return -1;

	t_data::iterator it = data.lower_bound(date);

	if (it != data.end() && it->first == date)
		return it->second;

	if (it == data.begin())
		return -1;

	--it;
	return it->second;
}
