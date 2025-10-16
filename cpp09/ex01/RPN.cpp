#include "RPN.hpp"

bool RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::calculate(int left, int right, char op) {
	switch (op) {
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': 
			if (right == 0)
				throw std::invalid_argument("division by zero");
			return left / right;
		default: throw std::invalid_argument("unknown operator");
	}
}

void RPN::parseToken(const std::string& token) {

	if (token.length() == 1 && isOperator(token[0])) {// handle operator
		if (stack_.size() < 2)
			throw std::invalid_argument("insufficient operands");
		int right = stack_.top(); stack_.pop(); // pop the most recent number out of the stack
		int left = stack_.top(); stack_.pop(); // pop the first number to be calculated first (left)
		stack_.push(calculate(left, right, token[0])); // calculate and push the result back to stack
	}
	else if (token.length() == 1 && std::isdigit(token[0])) // single digit
		stack_.push(token[0] - '0'); // push the number into stack as int
	else
		throw std::invalid_argument("invalid token: " + token);
}

void RPN::solve(const std::string& input) {
	if (input.empty() || input.length() < 3)
		throw std::invalid_argument("invalid input");
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		parseToken(token);
	}
	if (stack_.size() != 1)
		throw std::invalid_argument("invalid input");
	std::cout << stack_.top() << "\n";
}