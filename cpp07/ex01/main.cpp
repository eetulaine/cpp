#include "iter.hpp"
#include <iostream>

void doStuff(std::string& input) {
	input += " is YUMMY!";
}

void doStuff(int& input) {
	input += 100;
}

void doStuff(float& input) {
	input += 0.001f;
}

void printInt(int& i) {
	std::cout << i << "\n";
}

void printStr(std::string& str) {
	std::cout << str << "\n";
}

template<typename T>
void printStuff(T& stuff) {
	std::cout << stuff << "\n";
}

int	main() {

	{
		std::cout << "\n=== INT TEST (for loop) ===\n";

		int arr[] = {100, 7, 4, 70, 67};
		size_t size = std::size(arr);

		std::cout << "\nbefore:\n";
		for (size_t i = 0; i < size; i++) {
			std::cout << arr[i] << "\n";
		}
		iter(arr, size, doStuff);
		std::cout << "\nafter:\n";
		for (size_t i = 0; i < size; i++) {
			std::cout << arr[i] << "\n";
		}
	}
	{
		std::cout << "\n=== STR TEST ===\n";

		std::string arr[] = {"apple", "orange", "grape", "melon"};
		size_t size = std::size(arr);

		std::cout << "\nbefore:\n";
		iter(arr, size, printStr);
		iter(arr, size, doStuff);
		std::cout << "\nafter:\n";
		iter(arr, size, printStr);
	}
	{
		std::cout << "\n=== INT TEST ===\n";

		int arr[] = {1, 45, 3, 66, 46};
		size_t size = std::size(arr);

		std::cout << "\nbefore:\n";
		iter(arr, size, printInt);
		iter(arr, size, doStuff);
		std::cout << "\nafter:\n";
		iter(arr, size, printInt);
	}
	{
		std::cout << "\n=== FLOAT TEST ===\n";

		float arr[] = {1.912f, 45.619f, 3.356f, 66.168f, 46.154f};
		size_t size = std::size(arr);

		std::cout << "\nbefore:\n";
		iter(arr, size, printStuff);
		iter(arr, size, doStuff);
		std::cout << "\nafter:\n";
		iter(arr, size, printStuff);
		std::cout << "\n";
	}
}