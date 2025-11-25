#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	buff;
	
	std::cout << "=== WELCOME TO GOOD-OLD PHONEBOOK! ===" << std::endl;
	std::cout << "> ";
	std::cin >> buff;
	while (buff != "EXIT")
	{
		if (buff == "ADD")
			phonebook.add();
		else if (buff == "SEARCH")
			phonebook.search();
		std::cout << "> ";
		std::cin >> buff;
	}
	std::cout << "Your nice PHONEBOOK lost forever..." << std::endl;
	std::cout << "Bye-bye!" << std::endl;
	return (0);
}
