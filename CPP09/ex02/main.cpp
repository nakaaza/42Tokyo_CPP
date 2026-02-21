#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <limits>
#include <ctime>

#include "VectorSort.hpp"
#include "DequeSort.hpp"

static bool parsePositiveInt(const std::string& s, int& out)
{
	if (s.empty())
		return false;

	long value = 0;
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (s[i] < '0' || s[i] > '9')
			return false;
		value = value * 10 + (s[i] - '0');
		if (value > std::numeric_limits<int>::max())
			return false;
	}
	if (value <= 0)
		return false;

	out = static_cast<int>(value);
	return true;
}

static void printVector(const std::vector<int>& v)
{
	const std::size_t limit = 20;

	for (std::size_t i = 0; i < v.size() && i < limit; ++i) {
		if (i) std::cout << " ";
		std::cout << v[i];
	}
	if (v.size() > limit)
		std::cout << " ...";
	std::cout << std::endl;
}

static bool isSameArr(const std::vector<int>& v, const std::deque<int>& d)
{
	if (v.size() != d.size())
		return false;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] != d[i])
			return false;
	}
	return true;
}

static double elapsedMs(std::clock_t start, std::clock_t end)
{
	return static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

int main(int argc, char** argv)
{
	if (argc <= 1) {
		std::cerr << "ERROR: Invalid argument" << std::endl
				  << "Usage: " << argv[0] << " <positive integers...>"
				  << std::endl;
		return 1;
	}

	std::vector<int> vec;
	vec.reserve(static_cast<std::size_t>(argc - 1));

	for (int i = 1; i < argc; ++i) {
		int n = 0;
		if (!parsePositiveInt(argv[i], n)) {
			std::cerr << "ERROR: Non positive integer argument detected: " << argv[i] << std::endl;
			return 1;
		}
		vec.push_back(n);
	}

	std::deque<int> deq(vec.begin(), vec.end());

	std::cout << "Before: ";
	printVector(vec);

	std::clock_t vStart = std::clock();
	VectorSort::execute(vec);
	std::clock_t vEnd = std::clock();

	std::clock_t dStart = std::clock();
	DequeSort::execute(deq);
	std::clock_t dEnd = std::clock();

	std::cout << "After : ";
	printVector(vec);

	if (!isSameArr(vec, deq))
		std::cerr << "Error: Sort result is different between VectorSort::execute() and DequeSort::execute()" << std::endl;

	std::cout << "Time to process a range of "
			<< vec.size()
			<< " elements with std::vector : "
			<< elapsedMs(vStart, vEnd)
			<< " ms"
			<< std::endl;

	std::cout << "Time to process a range of "
			<< deq.size()
			<< " elements with std::deque  : "
			<< elapsedMs(dStart, dEnd)
			<< " ms"
			<< std::endl;

	return 0;
}
