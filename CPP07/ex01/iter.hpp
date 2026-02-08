#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T arr[], const size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	iter(const T arr[], const size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif // ITER_HPP
