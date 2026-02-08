#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		Array 	&operator=(const Array &rhs);

		T		&operator[](const unsigned int n);
		const T	&operator[](const unsigned int n) const;

		unsigned int	size() const;
};

# include "Array.tpp"

#endif // ARRAY_HPP
