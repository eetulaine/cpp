#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {

	{
		std::cout << "\nVECTOR TESTS\n";
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		try {
			std::vector<int>::iterator it = easyfind(vec, 2);
			std::cout << "Value found in vector: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in vector\n";
		}
		try {
			std::vector<int>::iterator it = easyfind(vec, 7);
			std::cout << "Value found in vector: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in vector\n";
		}
	}
	{
		std::cout << "\nVECTOR TESTS (for loop)\n";
		std::vector<int> vec;
		for (int i = 0; i < 10; i++) {
			vec.push_back(i * 2);
			std::cout << vec[i] << " ";
		}
		try {
			std::vector<int>::iterator it = easyfind(vec, 18);
			std::cout << "\nValue found in vector: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in vector\n";
		}
		try {
			std::vector<int>::iterator it = easyfind(vec, 7);
			std::cout << "Value found in vector: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in vector\n";
		}
	}
	{
		std::cout << "\nLIST TESTS\n";
		std::list<int> list;
		list.push_back(11);
		list.push_back(6);
		list.push_back(233);

		try {
			std::list<int>::iterator it = easyfind(list, 233);
			std::cout << "Value found in list: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in list\n";
		}
		try {
			std::list<int>::iterator it = easyfind(list, 7);
			std::cout << "Value found in list: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in list\n";
		}
	}
	{
		std::cout << "\nDEQUE TESTS\n";
		std::deque<int> deq;
		deq.push_back(-55);
		deq.push_back(-6);
		deq.push_back(16);

		try {
			std::deque<int>::iterator it = easyfind(deq, -6);
			std::cout << "Value found in deque: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in deque\n";
		}
		try {
			std::deque<int>::iterator it = easyfind(deq, 55);
			std::cout << "Value found in deque: " << *it << "\n";
		}
		catch (std::exception& e) {
			std::cout << "Value NOT found in deque\n";
		}
	}
	return 0;
}