#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class RPN {

	private:
		std::stack<int> stack_;
		void parseToken(const std::string& token);
		static bool isOperator(char c);
		static int calculate(int left, int right, char op);

	public:
		RPN() = default;
		RPN(const RPN& other) = default;
		RPN& operator=(const RPN& other) = default;
		~RPN() = default;

		void solve(const std::string& input);
};