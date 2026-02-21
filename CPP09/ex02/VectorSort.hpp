#ifndef VECTORSORT_HPP
#define VECTORSORT_HPP

#include <vector>
#include <cstddef>

class VectorSort {
public:
	// Ford–Johnson (Merge-Insertion Sort)
	static void execute(std::vector<int>& vec);

private:
	struct Pair {
		int         big;
		int         small;
		bool        hasSmall;
		std::size_t id;
	};

	struct Node {
		int         value;
		std::size_t pairId;   // big/small が属するペアを識別（重複対策）
		bool        isBig;    // main chain 側かどうか
	};

	static void fordJohnsonSort(std::vector<int>& vec);

	// Jacobsthal insertion order を生成（pend の index 群）
	static std::vector<std::size_t> buildJacobsthalOrder(std::size_t pendSize);

	// main chain 上で pairId の big ノード位置を探す（線形でOK）
	static std::size_t findBigPos(const std::vector<Node>& mainChain, std::size_t pairId);

	// mainChain[0, hi) の範囲で value の lower_bound を返す
	static std::size_t lowerBoundNode(const std::vector<Node>& mainChain, int value, std::size_t hi);

	// vec -> pairs
	static std::vector<Pair> makePairs(const std::vector<int>& vec, bool& hasStraggler, int& straggler);

	// big のソート結果から pairs を big 昇順に並べ替える（重複対応）
	static std::vector<Pair> reorderPairsBySortedBigs(const std::vector<Pair>& pairs,
													const std::vector<int>& sortedBigs);
};

#endif
