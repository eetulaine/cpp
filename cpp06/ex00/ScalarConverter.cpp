/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:39 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/07 10:09:32 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isSpecialValue(const std::string &input) {
	
	std::string temp = input;
	for (size_t i = 0; i < temp.length(); i++) {
		temp[i] = std::tolower(temp[i]);
	}
	if (temp == "nan" || temp == "nanf" || temp == "+inf" || temp == "+inff" 
		|| temp == "inf" || temp == "inff" || temp == "-inf" || temp == "-inff")
		return true;
	return false;
}

bool isValidNumber(const std::string &input) {
	
	bool hasDecimal = false;

	for (size_t i = 0; i < input.length(); i++) {
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			continue;
		if (input[i] == '.' && !hasDecimal) {
			hasDecimal = true;
			continue;
		}
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

Type checkInputType(const std::string &input) {

	if (isSpecialValue(input))
		return SPECIAL;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	if (input.length() > 1 && input[input.length() - 1] == 'f') {
		std::string digitPart = input.substr(0, input.length() - 1);
		if (isValidNumber(digitPart)) {
			return FLOAT;
		}
	}
	if (isValidNumber(input)) {
		return input.find('.') != std::string::npos ? DOUBLE : INT;
	}
	return INVALID;
}

void printSpecial(const std::string &input) {

	float floatVal = std::stod(input);
	double doubleVal = std::stod(input);

	std::cout << "char: impossible\nint: impossible\n";
	std::cout << "float: " << floatVal << "f\n";
	std::cout << "double: " << doubleVal << "\n";
}

void printChar(const std::string &input) {

	char c = input[0];
	
	std::cout << "char: " << c << "\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void printInt(const std::string &input) {
	
	long l = std::stol(input);
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		std::cout << "char: impossible\nint: impossible\n";
	else {
		char c = static_cast<char>(l);
		if (std::isprint(c))
			std::cout << "char: " << c << "\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << l << "\n";
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(l) << "f\n";
	std::cout << "double: " << static_cast<double>(l) << "\n";
}

void printFloat(const std::string &input) {
	
	float f = std::strtof(input.c_str(), nullptr);
	if (std::isnan(f) || std:: isinf(f))
		std::cout << "char: impossible\nint: impossible\n";
	else {
		char c = static_cast<char>(f);
		if (f < 0 || f > 127)
			std::cout << "char: impossible\n";
		else {
			if (std::isprint(c))
				std::cout << "char: " << c << "\n";
			else
				std::cout << "char: Non displayable\n";
		}
		std::cout << "int: " << static_cast<int>(f) << "\n";
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(f) << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void printDouble(const std::string &input) {
	
	double d = std::strtod(input.c_str(), nullptr);
	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible\nint: impossible\n";
	else {
		char c = static_cast<char>(d);
		if (d < 0 || d > 127)
			std::cout << "char: impossible\n";
		else {
			if (isprint(c))
				std::cout << "char: " << c << "\n";
			else
				std::cout << "char: Non displayable\n";
		}
		std::cout << "int: " << static_cast<int>(d) << "\n";
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}

void printImpossible() {
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

void ScalarConverter::convert(const std::string &input) {

	try {
	
		Type type = checkInputType(input);
		if (type == SPECIAL)
			return printSpecial(input);
		if (type == CHAR)
			return printChar(input);
		if (type == INT)
			return printInt(input);
		if (type == FLOAT)
			return printFloat(input);
		if (type == DOUBLE)
			return printDouble(input);
		return printImpossible();
	
	} catch (const std::exception &e) {
		std::cout << "Not possible: " << e.what() << std::endl;
	}
}
