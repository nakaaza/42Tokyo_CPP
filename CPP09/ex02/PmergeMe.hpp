#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
class PmergeMe {
	public:
		class VectorSort {
			public:
				static void execute(std::vector<int>& vec);

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
				fordJohnsonSort(std::vector<int>& vec);

				static std::vector<Pair>
				makePairs(const std::vector<int>& vec, bool& hasStraggler, int& straggler);

				static std::vector<Pair>
				reorderPairsBySortedBigs(const std::vector<Pair>& pairs,
										const std::vector<int>& sortedBigs);

				static std::vector<std::size_t>
				buildJacobsthalOrder(std::size_t pendSize);
				
				static void
				binaryInsertion(std::vector<Node>& mainChain, Node n);
			};

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
};

#endif
