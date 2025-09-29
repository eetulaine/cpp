#include "Array.hpp"
#include "Array.tpp"

#define SIZE 10

int main() {

	{
		std::cout << "\n\n=== DEFAULT CONTRUCTOR TEST ===\n\n";
		Array<int> empty;
		std::cout << "Empty array size:\n" << empty.size() << "\n";
		try {
			std::cout << empty[0] << "\n";
		} catch (const std::exception& e) {
			std::cout << "Trying to access empty arr elements: " << e.what() << std::endl;
		}
		std::cout << "\n\n=== BOUNDARY TEST ===\n\n";
		Array<int> small(1);
		try {
			std::cout << small[1] << "\n";
		} catch (const std::exception& e) {
			std::cout << "Trying to access out of bounds elements: " << e.what() << std::endl;
		}
	}
	{
		Array<int> arr(SIZE);
		for (size_t i = 0; i < SIZE; i++) {
			arr[i] = i;
		}
		std::cout << "\n\n=== INT ===\narr:\n";
		for (size_t i = 0; i < SIZE; i++) {
			std::cout << arr[i];
		}
		Array<int> copy(arr);
		std::cout << "\n\ncopy:\n";
		for (size_t i = 0; i < SIZE; i++)
			std::cout << copy[i];
		std::cout << "\n\n";

		std::cout << "=== COPY ASSIGNMENT OPERATOR TEST === \n\n";
		Array<int> copy2;
		copy2 = arr;

		std::cout << "Arr size:\n" << arr.size() << "\n";
		std::cout << "Copy size:\n" << copy.size() << "\n";
		std::cout << "Copy2 size:\n" << copy2.size() << "\n";
	}
	{
		Array<std::string> arr(SIZE);
		for (size_t i = 0; i < SIZE; i++) {
			arr[i] = "element" + std::to_string(i);
		}
		std::cout << "\n\n=== STRING ===\narr:\n";
		for (size_t i = 0; i < SIZE; i++) {
			std::cout << arr[i] << "\n";
		}
		Array<std::string> copy(arr);
		std::cout << "\n\ncopy:\n";
		for (size_t i = 0; i < SIZE; i++)
			std::cout << copy[i] << "\n";
		std::cout << "\n\n";

		std::cout << "Modidying the original to showcase deep copy:\n\n";
		arr[0] = "zero";
		std::cout << "OG: " << arr[0] << "\n\n";
		std::cout << "CP: " << copy[0] << "\n\n";
	}
}