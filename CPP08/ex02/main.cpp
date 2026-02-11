#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

void testMutantStack()
{
	std::cout << "[Test: MutantStack<int>] ========================" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

template <typename T>
void test(const std::string &type)
{
	std::cout << "[Test: " << type << "] ========================" << std::endl;
	T container;
	container.push_back(5);
	container.push_back(17);
	std::cout << container.back() << std::endl;
	container.pop_back();
	std::cout << container.size() << std::endl;
	container.push_back(3);
	container.push_back(5);
	container.push_back(737);
	//[...]
	container.push_back(0);
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	testMutantStack();
	std::cout << std::endl;
	test<std::vector<int> >("std::vector<int>");
	std::cout << std::endl;
	test<std::list<int> >("std::list<int>");
	std::cout << std::endl;
	test<std::deque<int> >("std::deque<int>");
	std::cout << std::endl;
	return 0;
}
