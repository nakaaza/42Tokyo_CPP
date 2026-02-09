#include "iter.hpp"
#include <iostream>
#include <string>

void	increment(int &i)
{
	std::cout << i << " -> ";
	++i;
	std::cout << i << std::endl;
}

void	cast_char(const int &i)
{
	std::cout << i << "->" << static_cast<char>(i) << std::endl;
}

void	respect(const std::string &name)
{
	std::cout << name << " san" << std::endl;
}

template <typename T>
void	print_test_arr(T *arr, size_t len)
{
	std::cout << "arr: [";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i];
		if (i != len - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int	main(void)
{
	std::cout << "Test with non-const arr<int> + func with non-const arg" << std::endl;
	int		arr_i[] = {40, 41, 42, 43};
	size_t	len_i = sizeof(arr_i) / sizeof(*arr_i);
	print_test_arr(arr_i, len_i);
	std::cout << "func: increment" << std::endl;
	std::cout << "-------------------" << std::endl;
	iter(arr_i, len_i, increment);
	std::cout << "=======================================" << std::endl;

	std::cout << "Test with non-const arr<int> + func with const arg" << std::endl;
	print_test_arr(arr_i, len_i);
	std::cout << "func: cast_char" << std::endl;
	std::cout << "-------------------" << std::endl;
	iter(arr_i, len_i, cast_char);
	std::cout << "=======================================" << std::endl;

	std::cout << "Test with const arr<int> + func with const arg" << std::endl;
	const int	arr_j[] = {96, 97, 98, 99, 100};
	size_t	len_j = sizeof(arr_j) / sizeof(*arr_j);
	print_test_arr(arr_j, len_j);
	std::cout << "func: cast_char" << std::endl;
	std::cout << "-------------------" << std::endl;
	iter(arr_j, len_j, cast_char);
	std::cout << "=======================================" << std::endl;

	std::cout << "Test with const arr<std::string> + func with const arg" << std::endl;
	const std::string	arr_s[] = {"Taro", "Hanako", "Oji", "Oba", "Aka"};
	size_t	len_s = sizeof(arr_s) / sizeof(*arr_s);
	print_test_arr(arr_s, len_s);
	std::cout << "func: respect" << std::endl;
	std::cout << "-------------------" << std::endl;
	iter(arr_s, len_s, respect);
	std::cout << "=======================================" << std::endl;

}
