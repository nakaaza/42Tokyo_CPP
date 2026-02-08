#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int target)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("Target value not found in the container");
	return it;
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int target)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("Target value not found in the container");
	return it;
}

#endif // EASYFIND_TPP
