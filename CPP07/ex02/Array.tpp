#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <stdexcept>

template <typename T>
Array<T>::Array():
	_data(NULL),
	_size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n):
	_data(n ? new T[n]() : NULL),
	_size(n)
{}

template <typename T>
Array<T>::Array(const Array &src):
	_data(src._size ? new T[src._size] : NULL),
	_size(src._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
		_data[i] = src._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T> 	&Array<T>::operator=(const Array<T> &rhs) 
{
	if (this != &rhs)
	{
		delete[] this->_data;
		_size = rhs._size;
		_data = (_size ? new T[_size]() : NULL);
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = rhs._data[i];
	}
	return *this;
}

template <typename T>
T		&Array<T>::operator[](const unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("Array: index out of range.");
	return _data[n];
}

template <typename T>
const T	&Array<T>::operator[](const unsigned int n) const {
	if (n >= _size)
		throw std::out_of_range("Array: index out of range.");
	return _data[n];
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

#endif // ARRAY_TPP
