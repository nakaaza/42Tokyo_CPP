#ifndef DEQUESORT_HPP
#define DEQUESORT_HPP

#include <deque>
#include <cstddef>

class DequeSort {
public:
	static void execute(std::deque<int>& deq);

private:
	struct Pair {
		int         big;
		int         small;
		bool        hasSmall;
		std::size_t id;
	};

	struct Node {
		int         value;
		std::size_t pairId;
		bool        isBig;
	};

	static void fordJohnsonSort(std::deque<int>& deq);

	// pend の index を Jacobsthal 順で返す（dequeで保持）
	static std::deque<std::size_t> buildJacobsthalOrder(std::size_t pendSize);

	// mainChain の中で pairId を持つ big ノードの位置
	static std::size_t findBigPos(const std::deque<Node>& mainChain, std::size_t pairId);

	// mainChain[0, hi) に対する lower_bound
	static std::size_t lowerBoundNode(const std::deque<Node>& mainChain, int value, std::size_t hi);

	static std::deque<Pair> makePairs(const std::deque<int>& deq, bool& hasStraggler, int& straggler);

	// big のソート結果に合わせて pairs を並べ替え（重複big対応）
	static std::deque<Pair> reorderPairsBySortedBigs(const std::deque<Pair>& pairs,
	                                                const std::deque<int>& sortedBigs);
};

#endif
