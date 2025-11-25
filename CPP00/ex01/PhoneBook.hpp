#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook {

private:
	Contact	list[8];
	int		oldest;
	int		count;
	void	show_list(void);

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);

};

#endif
