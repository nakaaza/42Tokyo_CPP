#ifndef DEQUESORT_HPP
#define DEQUESORT_HPP

#include <deque>
#include <cstddef>

class DequeSort {
public:
	static void execute(std::deque<int>& deq);

private:
	struct Pair {
		int			big;
		int			small;
		bool		hasSmall;
		std::size_t	id;
	};

	struct Node {
		int			value;
		std::size_t	pairId;
		bool		isBig;
	};

	static void
	fordJohnsonSort(std::deque<int>& deq);

	static std::deque<Pair>
	makePairs(const std::deque<int>& deq, bool& hasStraggler, int& straggler);

	static std::deque<Pair>
	reorderPairsBySortedBigs(const std::deque<Pair>& pairs,
							 const std::deque<int>& sortedBigs);

	static std::deque<std::size_t>
	buildJacobsthalOrder(std::size_t pendSize);
	
	static void
	binaryInsertion(std::deque<Node>& mainChain, Node n);
};

#endif
