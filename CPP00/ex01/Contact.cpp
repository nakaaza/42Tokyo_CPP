#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called." << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
	return ;
}

void	Contact::update(void)
{
	std::string	buff;

	std::cout << "Enter first name: ";
	std::cin >> buff;
	this->first_name = buff;
	std::cout << "Enter last name: ";
	std::cin >> buff;
	this->last_name = buff;
	std::cout << "Enter nickname: ";
	std::cin >> buff;
	this->nickname = buff;
	std::cout << "Enter phone number: ";
	std::cin >> buff;
	this->phone_number = buff;
	std::cout << "Enter darkest secret: ";
	std::cin >> buff;
	this->darkest_secret = buff;
	return ;
}

void	Contact::show_summary()
{
	std::cout << "|" << trunc_to_10(this->first_name);
	std::cout << "|" << trunc_to_10(this->last_name);
	std::cout << "|" << trunc_to_10(this->nickname);
	std::cout << "|" << trunc_to_10(this->phone_number);
	std::cout << "|" << std::endl;
}

void	Contact::show_detail()
{
	std::cout << "| first name: " << this->first_name << std::endl;
	std::cout << "| last name:  " << this->last_name << std::endl;
	std::cout << "| nickname: " << this->nickname << std::endl;
	std::cout << "| phone number: " << this->phone_number << std::endl;
	std::cout << "| darkest secret: " << this->darkest_secret << std::endl;
}
