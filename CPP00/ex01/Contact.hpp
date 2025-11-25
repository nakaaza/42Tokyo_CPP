#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact(void);
	~Contact(void);
	void	update(void);
	void	show_summary();
	void	show_detail();

};

#endif
