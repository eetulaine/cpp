#include "RPN.hpp"

int main(int ac, char **av) {
	try {
		if (ac != 2)
			throw std::invalid_argument("invalid arguments");
		RPN rpn;
		std::string input = av[1];
		rpn.solve(input);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}