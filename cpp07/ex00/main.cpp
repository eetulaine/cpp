#include "whatever.hpp"
#include <iostream>

int	main() {
	int a = 2;
	int b = 3;
	std::string s1 = "first";
	std::string s2 = "second";
	float f1 = 99.99f;
	float f2 = 99.98f;
	

	std::cout << "\n=== SWAP ===\n";
	::swap(a, b);
	::swap(s1, s2);
	::swap(f1, f2);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;

	std::cout << "\n=== MIN ===\n";
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;

	std::cout << "\n=== MAX ===\n";
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

	std::cout << "\n";

	return 0;
}