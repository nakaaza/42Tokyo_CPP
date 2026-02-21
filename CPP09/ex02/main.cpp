#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
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
		if (value > INT_MAX)
			return false;
	}
	if (value <= 0)
		return false;

	out = static_cast<int>(value);
	return true;
}

static void printVectorPreview(const std::vector<int>& v)
{
	// 大量入力でも見やすいように preview 表示（必要なら全表示に変えてOK）
	const std::size_t limit = 20;

	for (std::size_t i = 0; i < v.size() && i < limit; ++i) {
		if (i) std::cout << " ";
		std::cout << v[i];
	}
	if (v.size() > limit)
		std::cout << " ...";
	std::cout << std::endl;
}

static double elapsedUs(std::clock_t start, std::clock_t end)
{
	return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

int main(int argc, char** argv)
{
	if (argc <= 1) {
		std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	vec.reserve(static_cast<std::size_t>(argc - 1));

	for (int i = 1; i < argc; ++i) {
		int n = 0;
		if (!parsePositiveInt(argv[i], n)) {
			std::cerr << "Error: invalid positive integer: \"" << argv[i] << "\"" << std::endl;
			return 1;
		}
		vec.push_back(n);
	}

	std::deque<int> deq(vec.begin(), vec.end());

	std::cout << "Before: ";
	printVectorPreview(vec);

	// vector 計測
	std::clock_t vStart = std::clock();
	VectorSort::execute(vec);
	std::clock_t vEnd = std::clock();

	// deque 計測
	std::clock_t dStart = std::clock();
	DequeSort::execute(deq);
	std::clock_t dEnd = std::clock();

	std::cout << "After : ";
	printVectorPreview(vec);

	std::cout << "Time to process a range of "
	          << vec.size()
	          << " elements with std::vector : "
	          << elapsedUs(vStart, vEnd)
	          << " us"
	          << std::endl;

	std::cout << "Time to process a range of "
	          << deq.size()
	          << " elements with std::deque  : "
	          << elapsedUs(dStart, dEnd)
	          << " us"
	          << std::endl;

	return 0;
}
