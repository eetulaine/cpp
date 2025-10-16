#pragma once

#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define RED		"\033[0;31m"
#define END		"\033[0m"
#define DEBUG	BLUE "[DEBUG] " END

class PmergeMe {
    private:
		static const bool debug_ = false;
		static int comparisons_;

        // creates a vector of Jacobsthal numbers up to n.
		static std::vector<size_t> generateJacobsthalSequence(size_t n) {
    		std::vector<size_t> seq;
			seq.push_back(1);
			seq.push_back(1);
			while (seq.back() < n) {
				seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
			}
			return seq;
		}

		// pair struct to keep track which element is smaller/larger
		template<typename T>
		struct Pair {
			T larger;
			T smaller;
            Pair(T l, T s) : larger(l), smaller(s) {}
		};

		//DEBUGGING print a container
		template<typename Container>
		static void debugPrint(const std::string& label, const Container& container) {
			if (!debug_)
				return;
			std::cout << DEBUG << label << ": ";
			for (size_t i = 0; i < container.size(); i++) {
				std::cout << container[i];
				if (i < container.size() - 1)
					std::cout << " ";
			}
			std::cout << "\n";
		}

		//DEBUGGING print the pairs
		template<typename T>
		static void debugPair(const std::string& label, const std::vector<Pair<T>>& pairs) {
			if (!debug_)
				return;
			std::cout << DEBUG << label << ": ";
			for (size_t i = 0; i < pairs.size(); i++) {
				std::cout << "(" << pairs[i].smaller << "," << pairs[i].larger << ")";
				if (i < pairs.size() - 1)
					std::cout << " ";
			}
			std::cout << "\n";
		}

		//binary search and insert using a narrowed-down search limit
		template<typename Container>
		static void binaryInsert(Container& main, const typename Container::value_type& value, size_t searchLimit) {
			auto endIt = main.begin() + std::min(searchLimit, main.size()); // limit search range
			auto it = std::lower_bound(main.begin(), endIt, value, [](const auto& a, const auto& b) {
				comparisons_++;
				return a < b;
			});
			if (debug_)
				std::cout << DEBUG << "Binary inserting " << value << " in front of " << *it << "\n";
    		main.insert(it, value);
		}

		// the merge-insertion sorting algorithm
        template<typename Container>
        static Container fordJohnsonSort(Container arr) {
            typedef typename Container::value_type T;

            if (arr.size() <= 1)
                return arr;
            if (arr.size() == 2) {
                comparisons_++;
                if (arr[0] > arr[1])
                    std::swap(arr[0], arr[1]);
                return arr;
            }
            // CREATE PAIRS
            std::vector<Pair<T>> pairs;
            bool hasOdd = (arr.size() % 2 == 1);
            T oddElement = T();
            if (hasOdd)
                oddElement = arr.back();

            // STORE PAIRS and prepare vector of larger elements for recursion
            Container largerElements;
            for (size_t i = 0; i + 1 < arr.size(); i += 2) {
                comparisons_++;
                if (arr[i] > arr[i + 1]) {
					pairs.push_back(Pair<T>(arr[i], arr[i + 1]));
					largerElements.push_back(arr[i]);
				} else {
					pairs.push_back(Pair<T>(arr[i + 1], arr[i]));
					largerElements.push_back(arr[i + 1]);
				}
			}

			debugPrint("Current arr", arr);
			debugPrint("Larger elements", largerElements);
			debugPair("Pairs (smaller, larger)", pairs);

			// RECURSION
			Container sortedLargerElements = fordJohnsonSort(largerElements);
			debugPrint("Sorted larger elements", sortedLargerElements);

			std::map<T, T> partnerMap;
			for (const auto& p : pairs) {
				partnerMap[p.larger] = p.smaller;
			}

            // CREATE MAIN & PENDING CHAIN
            Container main;
            std::vector<T> pend;

            // insert the pair's smaller element and larger element into main seq
            if (!sortedLargerElements.empty()) {
                main.push_back(partnerMap[sortedLargerElements[0]]); //the larger numbers pair (smaller number)
                main.push_back(sortedLargerElements[0]); //larger number
				for (size_t i = 1; i < sortedLargerElements.size(); i++) {  // push remaining larger elements to main
					main.push_back(sortedLargerElements[i]);
					pend.push_back(partnerMap[sortedLargerElements[i]]); // push leftover smaller elements to pend
				}
			}

			debugPrint("MAIN chain", main);
			debugPrint("PEND chain", pend);

			// INSERT pending elements using Jacobsthal sequence
			// Jacobstahl will tell us how many elements to insert from the pend to main
			if (!pend.empty()) {
                std::vector<size_t> jacobsthal = generateJacobsthalSequence(pend.size()); // find Jacobsthal seq up to the size of the pend chain
                size_t prevGroupEnd = 0;
				size_t insertedCount = 0;
                for (size_t i = 1; i < jacobsthal.size(); i++) { // iterate over the Jacobsthal indexes in increasing order
                    size_t groupEnd = std::min(jacobsthal[i], pend.size()); //which is smaller, the jacobstahl index or amount of pend elements
                    size_t groupStart = prevGroupEnd;
                    for (size_t j = groupEnd; j > groupStart; j--) { // insert elements in reverse order within the group for minimum search size
						size_t pend_idx = j - 1; // change to 0 index
						T value = pend[pend_idx];
						size_t searchLimit = pend_idx + 1 + insertedCount + 1;
						if (debug_)
							std::cout << DEBUG << "For value " << pend[pend_idx] << " the search limit is: " << searchLimit << "\n";
						binaryInsert(main, value, searchLimit);
						insertedCount++;
					}
					prevGroupEnd = groupEnd;
				}
			}
			// Insert odd element
			if (hasOdd)
				binaryInsert(main, oddElement, main.size());
			return main;
		}

public:
    PmergeMe() {}
    PmergeMe(const PmergeMe& other) { (void)other; }
    PmergeMe& operator=(const PmergeMe& other) { (void)other; return *this; }
    ~PmergeMe() {}
    
    template<typename Container>
    static Container sort(Container arr) {
        comparisons_ = 0;
        return fordJohnsonSort(arr);
    }

    template<typename Container>
    void print(const Container& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if (i < arr.size() - 1)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    static int getComparisons() { return comparisons_; }
};

int PmergeMe::comparisons_ = 0;