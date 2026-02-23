#include "PmergeMe.hpp"
#include <vector>
#include <deque>

// VectorSort =====================================================================================

void
PmergeMe::VectorSort::execute(std::vector<int>& vec)
{
	fordJohnsonSort(vec);
}

void
PmergeMe::VectorSort::fordJohnsonSort(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	bool hasStraggler = false;
	int  straggler = 0;
	std::vector<Pair> pairs = makePairs(vec, hasStraggler, straggler);

	std::vector<int> bigs;
	bigs.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
		bigs.push_back(pairs[i].big);

	fordJohnsonSort(bigs);

	std::vector<Pair> orderedPairs = reorderPairsBySortedBigs(pairs, bigs);

	std::vector<Node> mainChain;
	mainChain.reserve(vec.size());
	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		Node n;
		n.value  = orderedPairs[i].big;
		n.pairId = orderedPairs[i].id;
		n.isBig  = true;
		mainChain.push_back(n);
	}

	std::vector<Node> pend;
	pend.reserve(orderedPairs.size() + (hasStraggler ? 1 : 0));
	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		if (!orderedPairs[i].hasSmall)
			continue;
		Node s;
		s.value  = orderedPairs[i].small;
		s.pairId = orderedPairs[i].id;
		s.isBig  = false;
		pend.push_back(s);
	}

	if (hasStraggler) {
		Node st;
		st.value  = straggler;
		st.pairId = static_cast<std::size_t>(-1);
		st.isBig  = false;
		pend.push_back(st);
	}

	if (!pend.empty()) {
		mainChain.insert(mainChain.begin(), pend[0]);
		std::vector<std::size_t> order = buildJacobsthalOrder(pend.size());
		for (std::size_t i = 0; i < order.size(); ++i) {
			const std::size_t idx = order[i];
			if (idx == 0)
				continue;
			binaryInsertion(mainChain, pend[idx]);
		}
	}

	vec.clear();
	vec.reserve(mainChain.size());
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		vec.push_back(mainChain[i].value);
}

std::vector<PmergeMe::VectorSort::Pair>
PmergeMe::VectorSort::makePairs(const std::vector<int>& vec, bool& hasStraggler, int& straggler)
{
	std::vector<Pair> pairs;
	pairs.reserve(vec.size() / 2);

	hasStraggler = false;

	std::size_t pid = 0;
	for (std::size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 >= vec.size()) {
			hasStraggler = true;
			straggler = vec[i];
			break;
		}
		const int a = vec[i];
		const int b = vec[i + 1];

		Pair p;
		p.id = pid++;
		p.hasSmall = true;
		if (a < b) {
			p.big = b;
			p.small = a;
		} else {
			p.big = a;
			p.small = b;
		}
		pairs.push_back(p);
	}
	return pairs;
}

std::vector<PmergeMe::VectorSort::Pair>
PmergeMe::VectorSort::reorderPairsBySortedBigs(const std::vector<Pair>& pairs,
									const std::vector<int>& sortedBigs)
{
	std::vector<Pair> ordered;
	ordered.reserve(pairs.size());

	std::vector<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < sortedBigs.size(); ++i) {
		const int target = sortedBigs[i];
		for (std::size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].big == target) {
				ordered.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	return ordered;
}

std::vector<std::size_t>
PmergeMe::VectorSort::buildJacobsthalOrder(std::size_t pendSize)
{
	std::vector<std::size_t> order;
	if (pendSize == 0)
		return order;

	order.reserve(pendSize);
	order.push_back(0);
	if (pendSize == 1)
		return order;

	std::size_t j0 = 0;
	std::size_t j1 = 1;

	while (true) {
		std::size_t j2 = j1 + 2 * j0;
		std::size_t start = j2;
		std::size_t prev  = j1;

		if (start > pendSize)
			start = pendSize;

		for (std::size_t x = start; x > prev; --x)
			order.push_back(x - 1);

		if (start == pendSize)
			break;

		j0 = j1;
		j1 = j2;
	}

	return order;
}

void
PmergeMe::VectorSort::binaryInsertion(std::vector<Node>& mainChain, Node n)
{
	std::size_t lo = 0;
	std::size_t hi = mainChain.size();
	for (std::size_t i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i].isBig && mainChain[i].pairId == n.pairId) {
			hi = i;
			break;
		}
	}

	while (lo < hi) {
		const std::size_t mid = lo + (hi - lo) / 2;
		if (mainChain[mid].value < n.value)
			lo = mid + 1;
		else
			hi = mid;
	}
	mainChain.insert(mainChain.begin() + lo, n);
}

// DequeSort =====================================================================================
void
PmergeMe::DequeSort::execute(std::deque<int>& deq)
{
	fordJohnsonSort(deq);
}

void
PmergeMe::DequeSort::fordJohnsonSort(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;

	bool hasStraggler = false;
	int  straggler = 0;
	std::deque<Pair> pairs = makePairs(deq, hasStraggler, straggler);

	std::deque<int> bigs;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		bigs.push_back(pairs[i].big);

	fordJohnsonSort(bigs);

	std::deque<Pair> orderedPairs = reorderPairsBySortedBigs(pairs, bigs);

	std::deque<Node> mainChain;
	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		Node n;
		n.value  = orderedPairs[i].big;
		n.pairId = orderedPairs[i].id;
		n.isBig  = true;
		mainChain.push_back(n);
	}

	std::deque<Node> pend;
	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		if (!orderedPairs[i].hasSmall)
			continue;
		Node s;
		s.value  = orderedPairs[i].small;
		s.pairId = orderedPairs[i].id;
		s.isBig  = false;
		pend.push_back(s);
	}

	if (hasStraggler) {
		Node st;
		st.value  = straggler;
		st.pairId = static_cast<std::size_t>(-1);
		st.isBig  = false;
		pend.push_back(st);
	}

	if (!pend.empty()) {
		mainChain.insert(mainChain.begin(), pend[0]);
		std::deque<std::size_t> order = buildJacobsthalOrder(pend.size());
		for (std::size_t i = 0; i < order.size(); ++i) {
			const std::size_t idx = order[i];
			if (idx == 0)
				continue;
			binaryInsertion(mainChain, pend[idx]);
		}
	}

	deq.clear();
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		deq.push_back(mainChain[i].value);
}

std::deque<PmergeMe::DequeSort::Pair>
PmergeMe::DequeSort::makePairs(const std::deque<int>& deq, bool& hasStraggler, int& straggler)
{
	std::deque<Pair> pairs;

	hasStraggler = false;

	std::size_t pid = 0;
	for (std::size_t i = 0; i < deq.size(); i += 2) {
		if (i + 1 >= deq.size()) {
			hasStraggler = true;
			straggler = deq[i];
			break;
		}
		const int a = deq[i];
		const int b = deq[i + 1];

		Pair p;
		p.id = pid++;
		p.hasSmall = true;
		if (a < b) {
			p.big = b;
			p.small = a;
		} else {
			p.big = a;
			p.small = b;
		}
		pairs.push_back(p);
	}
	return pairs;
}

std::deque<PmergeMe::DequeSort::Pair>
PmergeMe::DequeSort::reorderPairsBySortedBigs(const std::deque<Pair>& pairs,
									const std::deque<int>& sortedBigs)
{
	std::deque<Pair> ordered;

	std::deque<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < sortedBigs.size(); ++i) {
		const int target = sortedBigs[i];
		for (std::size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].big == target) {
				ordered.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	return ordered;
}

std::deque<std::size_t>
PmergeMe::DequeSort::buildJacobsthalOrder(std::size_t pendSize)
{
	std::deque<std::size_t> order;
	if (pendSize == 0)
		return order;

	order.push_back(0);
	if (pendSize == 1)
		return order;

	std::size_t j0 = 0;
	std::size_t j1 = 1;

	while (true) {
		std::size_t j2 = j1 + 2 * j0;
		std::size_t start = j2;
		std::size_t prev  = j1;

		if (start > pendSize)
			start = pendSize;

		for (std::size_t x = start; x > prev; --x)
			order.push_back(x - 1);

		if (start == pendSize)
			break;

		j0 = j1;
		j1 = j2;
	}

	return order;
}

void
PmergeMe::DequeSort::binaryInsertion(std::deque<Node>& mainChain, Node n)
{
	std::size_t lo = 0;
	std::size_t hi = mainChain.size();
	for (std::size_t i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i].isBig && mainChain[i].pairId == n.pairId) {
			hi = i;
			break;
		}
	}

	while (lo < hi) {
		const std::size_t mid = lo + (hi - lo) / 2;
		if (mainChain[mid].value < n.value)
			lo = mid + 1;
		else
			hi = mid;
	}
	mainChain.insert(mainChain.begin() + lo, n);
}
