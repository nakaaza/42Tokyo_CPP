#include <iostream>
#include <string>

int	main()
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "&stringVAR:\t" << &stringVAR << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "&stringREF:\t" << &stringREF << std::endl;
	std::cout << "stringVAR:\t" << stringVAR << std::endl;
	std::cout << "*stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl;
	return (0);
}
