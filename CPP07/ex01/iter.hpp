#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T arr[], const size_t len, void (*f)(T&))
{
	size_t	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T>
void	iter(const T arr[], const size_t len, void (*f)(const T&))
{
	size_t	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

#endif // ITER_HPP
