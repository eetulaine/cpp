#include "PmergeMe.hpp"
#include <chrono>

static void validateInput(int ac, char **av) {
	if (ac < 3)
		throw std::invalid_argument("no integer sequence provided");
	std::unordered_set<int> seen;
	for (int i = 1; i < ac; i++) {
		std::string arg(av[i]);
		if (arg.empty())
			throw std::invalid_argument("invalid input");
		for (char c : arg) {
			if (!std::isdigit(c)) // check for ints
				throw std::invalid_argument("invalid input");
		}
		int num = std::stoi(arg);
		if (num == 0)
			throw std::invalid_argument("only positive integers allowed");
		if (!seen.insert(num).second)  // bool false when insertion didn't happen = already existing
			throw std::invalid_argument("duplicate input");
	}
}

template<typename Container>
Container storeInput(int ac, char **av) {
    Container numbers;
    
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]);
        std::stringstream ss(arg);
        int value;
        ss >> value;
        numbers.push_back(value);
    }
    return numbers;
}

int main(int ac, char **av) {
	try {
		validateInput(ac, av);
		std::vector<int> num_vec = storeInput<std::vector<int>>(ac, av);
		std::deque<int> num_deq = storeInput<std::deque<int>>(ac, av);

		PmergeMe sorter;

		// === SORT VECTOR ===
		std::cout << BLUE << "\nSORTING VECTOR..\n\n" END;

		std::cout << "Before:\n";
		sorter.print(num_vec);

		// time and initialize sorting
		auto start_vec = std::chrono::steady_clock::now();
		std::vector<int> sorted_vec = sorter.sort(num_vec);
		auto end_vec = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::micro> duration_vec = end_vec - start_vec;

		// print sorted vector
		std::cout << "\nAfter:\n";
		sorter.print(sorted_vec);

		// verify sorting
		if (std::is_sorted(sorted_vec.begin(), sorted_vec.end()))
			std::cout << GREEN "VECTOR SORTED ✅\n" END;
		else	
			std::cout << RED "VECTOR SORTING FAILED ❌\n" END;

		std::cout << "\nTime to process a range of " << num_vec.size() << " elements with std::vector : " << duration_vec.count() << " us\n";
		std::cout << "Comparisons: " << sorter.getComparisons() << "\n";

		// === SORT DEQUE ===
		std::cout << BLUE << "\nSORTING DEQUE..\n\n" END;

		std::cout << "Before:\n";
		sorter.print(num_deq);

		// time and initialize sorting
		auto start_deq = std::chrono::steady_clock::now();
		std::deque<int> sorted_deq = sorter.sort(num_deq);
		auto end_deq = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::micro> duration_deq = end_deq - start_deq;

		// print sorted deque
		std::cout << "\nAfter:\n";
		sorter.print(sorted_deq);

		// verify sorting
		if (std::is_sorted(sorted_deq.begin(), sorted_deq.end()))
			std::cout << GREEN "DEQUE SORTED ✅\n" END;
		else	
			std::cout << RED "DEQUE SORTING FAILED ❌\n" END;

		std::cout << "\nTime to process a range of " << num_deq.size() << " elements with std::deque : " << duration_deq.count() << " us\n";
		std::cout << "Comparisons: " << sorter.getComparisons() << "\n";

	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}