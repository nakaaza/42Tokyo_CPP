#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

template <typename Container>
void print_container(const Container& c, const std::string& name)
{
	std::cout << name << ": [";
	typename Container::const_iterator it = c.begin();
	for (; it != c.end(); ++it)
	{
		std::cout << *it;
		typename Container::const_iterator next = it;
		++next;
		if (next != c.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename Container>
void run_tests_for(const std::string& name)
{
	std::cout << "============================================" << std::endl;
	std::cout << "Container: " << name << std::endl;
	std::cout << "============================================" << std::endl;

	Container c;
	c.push_back(10);
	c.push_back(20);
	c.push_back(30);
	c.push_back(40);

	print_container(c, name);

	try
	{
		std::cout << "[" << name << ": 01] easyfind(T&, 20) => iterator" << std::endl;
		typename Container::iterator it = easyfind(c, 20);
		std::cout << "found value: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "UNEXPECTED exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "[" << name << ": 02] easyfind(const T&, 30) => const_iterator" << std::endl;
		const Container& cc = c;
		typename Container::const_iterator cit = easyfind(cc, 30);
		std::cout << "found value: " << *cit << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "UNEXPECTED exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "[" << name << ": 03] easyfind(T&, 777) => should throw" << std::endl;
		typename Container::iterator it = easyfind(c, 777);
		(void)it;
		std::cout << "ERROR: should not reach here" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "caught expected exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "[" << name << ": 04] easyfind(const T&, 888) => should throw" << std::endl;
		const Container& cc = c;
		typename Container::const_iterator cit = easyfind(cc, 888);
		(void)cit;
		std::cout << "ERROR: should not reach here" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "caught expected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	run_tests_for< std::vector<int> >("std::vector<int>");
	run_tests_for< std::list<int>   >("std::list<int>");
	run_tests_for< std::deque<int>  >("std::deque<int>");
	return 0;
}
