#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j;

	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		if (i + 1 < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
