#include "Span.hpp"
#include <iostream>

int main ()
{
	{
		std::cout << BLUE "\nTEST: Basic\n\n" END;
		try {
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE "\nTEST: shortestSpan() and longestSpan()\n\n" END;
		try {
			Span sp0 = Span(5);
			sp0.addNumber(1);
			sp0.addNumber(11);

			std::cout << sp0.shortestSpan() << std::endl;
			std::cout << sp0.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Span sp1 = Span(5);
			sp1.addNumber(1);

			std::cout << sp1.shortestSpan() << std::endl;
			std::cout << sp1.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Span sp2 = Span(50);

			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE "\nTEST: Span full\n\n" END;
		try {
			Span sp(3);
			sp.addNumber(15);
			sp.addNumber(2);
			sp.addNumber(-4);
			sp.addNumber(-13);

			std::cout << sp.shortestSpan() << "\n";
			std::cout << sp.longestSpan() << "\n";
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE "\nTEST: Span full using addRange()\n\n" END;
		try {
			Span sp(50);
			std::vector<int> vec;
			for (int i = 0; i < 10000; i++) {
				vec.push_back(i);
			}
			sp.addRange(vec.begin(), vec.end());
			std::cout << sp.shortestSpan() << "\n";
			std::cout << sp.longestSpan() << "\n";
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE "\nTEST: Huge span filled with addRange()\n\n" END;
		try {
			Span huge(100000);
			std::vector<int> vec;
			for (int i = 0; i < 100000; i++) {
				vec.push_back(i);
			}
			huge.addRange(vec.begin(), vec.end());
			std::cout << huge.shortestSpan() << "\n";
			std::cout << huge.longestSpan() << "\n";
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}