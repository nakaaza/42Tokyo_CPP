#include "DequeSort.hpp"

void DequeSort::execute(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;
	fordJohnsonSort(deq);
}

void DequeSort::fordJohnsonSort(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;

	// 1) ペア化
	bool hasStraggler = false;
	int  straggler = 0;
	std::deque<Pair> pairs = makePairs(deq, hasStraggler, straggler);

	// 2) big を再帰的にソート
	std::deque<int> bigs;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		bigs.push_back(pairs[i].big);

	fordJohnsonSort(bigs);

	// 3) big の順に pairs を並べ替え（重複 big 対応）
	std::deque<Pair> orderedPairs = reorderPairsBySortedBigs(pairs, bigs);

	// 4) main chain（big）を Node で構築（ペアID付き）
	std::deque<Node> mainChain;
	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		Node n;
		n.value  = orderedPairs[i].big;
		n.pairId = orderedPairs[i].id;
		n.isBig  = true;
		mainChain.push_back(n);
	}

	// 5) pend（small）を作る
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

	// straggler は対応 big がない（pairId = -1）
	if (hasStraggler) {
		Node st;
		st.value  = straggler;
		st.pairId = static_cast<std::size_t>(-1);
		st.isBig  = false;
		pend.push_back(st);
	}

	// pend が空なら bigs を戻すだけ
	if (pend.empty()) {
		deq.clear();
		for (std::size_t i = 0; i < mainChain.size(); ++i)
			deq.push_back(mainChain[i].value);
		return;
	}

	// 6) pend[0] を先に挿入
	{
		const Node& s = pend[0];

		std::size_t hi = mainChain.size();
		if (s.pairId != static_cast<std::size_t>(-1))
			hi = findBigPos(mainChain, s.pairId);

		const std::size_t pos = lowerBoundNode(mainChain, s.value, hi);
		mainChain.insert(mainChain.begin() + pos, s);
	}

	// 7) Jacobsthal 順で残りを挿入
	const std::deque<std::size_t> order = buildJacobsthalOrder(pend.size());
	for (std::size_t oi = 0; oi < order.size(); ++oi) {
		const std::size_t idx = order[oi];
		if (idx == 0)
			continue;

		const Node& s = pend[idx];

		std::size_t hi = mainChain.size();
		if (s.pairId != static_cast<std::size_t>(-1))
			hi = findBigPos(mainChain, s.pairId);

		const std::size_t pos = lowerBoundNode(mainChain, s.value, hi);
		mainChain.insert(mainChain.begin() + pos, s);
	}

	// 8) 値だけ戻す
	deq.clear();
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		deq.push_back(mainChain[i].value);
}

std::deque<DequeSort::Pair>
DequeSort::makePairs(const std::deque<int>& deq, bool& hasStraggler, int& straggler)
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

		if (a >= b) {
			p.big = a;
			p.small = b;
		} else {
			p.big = b;
			p.small = a;
		}
		pairs.push_back(p);
	}
	return pairs;
}

std::deque<DequeSort::Pair>
DequeSort::reorderPairsBySortedBigs(const std::deque<Pair>& pairs,
                                   const std::deque<int>& sortedBigs)
{
	std::deque<Pair> ordered;

	// used フラグも deque で持つ（vector禁止）
	std::deque<char> used(pairs.size(), 0);

	for (std::size_t i = 0; i < sortedBigs.size(); ++i) {
		const int target = sortedBigs[i];

		for (std::size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].big == target) {
				ordered.push_back(pairs[j]);
				used[j] = 1;
				break;
			}
		}
	}
	return ordered;
}

std::deque<std::size_t>
DequeSort::buildJacobsthalOrder(std::size_t pendSize)
{
	std::deque<std::size_t> order;
	if (pendSize == 0)
		return order;

	order.push_back(0);
	if (pendSize == 1)
		return order;

	// Jacobsthal: J0=0, J1=1, Jn = Jn-1 + 2*Jn-2
	std::size_t j0 = 0;
	std::size_t j1 = 1;

	while (true) {
		const std::size_t j2 = j1 + 2 * j0;

		std::size_t start = j2;
		const std::size_t prev = j1;

		if (start > pendSize)
			start = pendSize;

		// [prev, start) を逆順で push
		// 例: prev=1, start=3 -> 2,1
		for (std::size_t x = start; x > prev; --x)
			order.push_back(x - 1);

		if (start == pendSize)
			break;

		j0 = j1;
		j1 = j2;
	}
	return order;
}

std::size_t DequeSort::findBigPos(const std::deque<Node>& mainChain, std::size_t pairId)
{
	for (std::size_t i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i].isBig && mainChain[i].pairId == pairId)
			return i;
	}
	return mainChain.size();
}

std::size_t DequeSort::lowerBoundNode(const std::deque<Node>& mainChain, int value, std::size_t hi)
{
	std::size_t lo = 0;
	if (hi > mainChain.size())
		hi = mainChain.size();

	while (lo < hi) {
		const std::size_t mid = lo + (hi - lo) / 2;
		if (mainChain[mid].value < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}
