#include "VectorSort.hpp"
#include <iostream>
#include <vector>

// static void printVectorRange(const std::vector<int>& v, std::size_t start, std::size_t end)
// {
// 	for (std::size_t i = start; i < end; ++i) {
// 		if (i != start) std::cout << " ";
// 		std::cout << v[i];
// 	}
// 	std::cout << std::endl;
// }

void VectorSort::execute(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;
	fordJohnsonSort(vec);
}

void VectorSort::fordJohnsonSort(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	// 1) ペア化
	bool hasStraggler = false;
	int  straggler = 0;
	std::vector<Pair> pairs = makePairs(vec, hasStraggler, straggler);

	// 2) big だけ取り出して再帰的に Ford–Johnson でソート
	std::vector<int> bigs;
	// std::vector<int> smalls;
	bigs.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		bigs.push_back(pairs[i].big);
		// if (pairs[i].hasSmall)
		// 	smalls.push_back(pairs[i].small);
	}
	// std::cout << "bigs:\t{";
	// printVectorRange(bigs, 0, bigs.size());
	// std::cout << "}" << std::endl;
	// std::cout << "smalls:\t{";
	// printVectorRange(smalls, 0, smalls.size());

	fordJohnsonSort(bigs);

	// 3) big のソート結果に合わせて pairs を並べ替え（重複bigにも対応）
	std::vector<Pair> orderedPairs = reorderPairsBySortedBigs(pairs, bigs);

	// 4) main chain を big で構築（Node に pairId を持たせる）
	std::vector<Node> mainChain;
	mainChain.reserve(vec.size());

	for (std::size_t i = 0; i < orderedPairs.size(); ++i) {
		Node n;
		n.value  = orderedPairs[i].big;
		n.pairId = orderedPairs[i].id;
		n.isBig  = true;
		mainChain.push_back(n);
	}

	// 5) pend（small）を取り出す（ペアID付き）
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

	// straggler（奇数個の最後）も pend として扱う（対応bigが無いので pairId は特殊値）
	if (hasStraggler) {
		Node st;
		st.value  = straggler;
		st.pairId = static_cast<std::size_t>(-1);
		st.isBig  = false;
		pend.push_back(st);
	}

	// pend が空なら bigs を vec に戻して終了
	if (pend.empty()) {
		vec.clear();
		vec.reserve(mainChain.size());
		for (std::size_t i = 0; i < mainChain.size(); ++i)
			vec.push_back(mainChain[i].value);
		return;
	}

	// 6) pend[0] を先に挿入（一般にそうする）
	{
		const Node& s = pend[0];
		std::size_t hi = mainChain.size();
		if (s.pairId != static_cast<std::size_t>(-1))
			hi = findBigPos(mainChain, s.pairId);
		std::size_t pos = lowerBoundNode(mainChain, s.value, hi);
		mainChain.insert(mainChain.begin() + pos, s);
	}

	// 7) Jacobsthal 順に残りを挿入
	std::vector<std::size_t> order = buildJacobsthalOrder(pend.size());
	for (std::size_t oi = 0; oi < order.size(); ++oi) {
		const std::size_t idx = order[oi];
		if (idx == 0) // 0 は既に挿入済み
			continue;

		const Node& s = pend[idx];

		std::size_t hi = mainChain.size();
		if (s.pairId != static_cast<std::size_t>(-1))
			hi = findBigPos(mainChain, s.pairId);

		std::size_t pos = lowerBoundNode(mainChain, s.value, hi);
		mainChain.insert(mainChain.begin() + pos, s);
	}

	// 8) 値だけ vec に戻す
	vec.clear();
	vec.reserve(mainChain.size());
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		vec.push_back(mainChain[i].value);
}

std::vector<VectorSort::Pair>
VectorSort::makePairs(const std::vector<int>& vec, bool& hasStraggler, int& straggler)
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

std::vector<VectorSort::Pair>
VectorSort::reorderPairsBySortedBigs(const std::vector<Pair>& pairs,
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
VectorSort::buildJacobsthalOrder(std::size_t pendSize)
{
	// order には [0..pendSize-1] が（0を含め）Jacobsthal 順で並ぶ
	// 実際の挿入側で 0 はスキップ（最初に挿入済み）
	std::vector<std::size_t> order;
	if (pendSize == 0)
		return order;

	order.reserve(pendSize);
	order.push_back(0);
	if (pendSize == 1)
		return order;

	// Jacobsthal: J0=0, J1=1, Jn = Jn-1 + 2*Jn-2
	std::size_t j0 = 0;
	std::size_t j1 = 1;

	// 既に 0 を入れたので、残り [1..pendSize-1] を構築
	while (true) {
		std::size_t j2 = j1 + 2 * j0; // 次の Jacobsthal
		std::size_t start = j2;
		std::size_t prev  = j1;

		if (start > pendSize)
			start = pendSize;

		// [prev, start) を逆順で追加
		// 例: start=3, prev=1 -> 2,1 を追加
		for (std::size_t x = start; x > prev; --x)
			order.push_back(x - 1);

		if (start == pendSize)
			break;

		j0 = j1;
		j1 = j2;
	}

	return order;
}

std::size_t VectorSort::findBigPos(const std::vector<Node>& mainChain, std::size_t pairId)
{
	for (std::size_t i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i].isBig && mainChain[i].pairId == pairId)
			return i; // big の位置（挿入範囲は [0, i)）
	}
	// 見つからないのは想定外だが、安全側に全範囲
	return mainChain.size();
}

std::size_t VectorSort::lowerBoundNode(const std::vector<Node>& mainChain, int value, std::size_t hi)
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
