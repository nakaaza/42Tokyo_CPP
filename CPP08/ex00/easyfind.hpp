#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
typename T::iterator		easyfind(T &container, int target);

template <typename T>
typename T::const_iterator	easyfind(const T &container, int target);

# include "easyfind.tpp"

#endif // EASYFIND_HPP
