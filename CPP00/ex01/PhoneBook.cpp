#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called." << std::endl;
	this->oldest = 0;
	this->count = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called." << std::endl;
	return ;
}

void	PhoneBook::add()
{
	std::cout << "PhoneBook->add() called." << std::endl;
	this->list[this->oldest].update();
	this->oldest = (this->oldest + 1) % 8;
	if (this->count < 8)
		this->count++;
	std::cout << "New contact added." << std::endl;
	return ;
}

void	PhoneBook::search()
{
	std::string	buff;
	int			idx;

	std::cout << "PhoneBook->search() called." << std::endl;
	this->show_list();
	while (true)
	{
		std::cout << "Enter index to show: ";
		std::cin >> buff;
		std::stringstream	ss(buff);
		ss >> idx;
		if (ss.fail() || idx < 0 || idx >= this->count)
		{
			std::cout << "Entered index is not found on this PhoneBook. Try again." << std::endl;
			continue ;
		}
		std::cout << "Showing detail for contact " << buff << std::endl;
		this->list[idx].show_detail();
		std::cout << std::endl;
		break ;
	}

	return ;
}

void	PhoneBook::show_list()
{
	int	i = -1;

	std::cout << "|----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "|" << std::endl;
	std::cout << "|" << "     index";
	std::cout << "|" << "first_name";
	std::cout << "|" << " last_name";
	std::cout << "|" << "  nickname";
	std::cout << "|" << "phone_num.";
	std::cout << "|" << std::endl;
	std::cout << "|" << "----------";
	std::cout << "|" << "----------";
	std::cout << "|" << "----------";
	std::cout << "|" << "----------";
	std::cout << "|" << "----------";
	std::cout << "|" << std::endl;
	while (++i < this->count)
	{
		std::stringstream	sidx;

		sidx << i;
		std::cout << "|" << trunc_to_10(sidx.str());
		this->list[i].show_summary();
	}
	std::cout << "|----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "-----------";
	std::cout << "|" << std::endl;
}
