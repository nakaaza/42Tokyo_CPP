#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++i < argc)
	{
		std::size_t	j = 0;
		std::string	s(argv[i]);
		while (j < s.length())
			std::cout << static_cast<char>(std::toupper(s[j++]));
	}
	std::cout << std::endl;
	return (0);
}
