/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:36:26 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/07 15:54:56 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <random>

Base *generate() {

	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, 2);	
	
	int random = dis(gen);

	if (random == 0) {
		std::cout << "Generating A...\n";
		return new A;
	}
	if (random == 1) {
		std::cout << "Generating B...\n";
		return new B;
	}
	else {
		std::cout << "Generating C...\n";
		return new C;
	}
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Pointer: A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer: C\n";
	else
		std::cout << "Pointer: Unknown\n";
}

void identify(Base& p) {
	
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Ref: A\n";
		return;
	} 
	catch(...) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Ref: B\n";
		return;
	}
	catch(...) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Ref: C\n";
		return;
	}
	catch(...) {}
	std::cout << "Ref: Unknown\n";
}

int main() {

	Base* base = generate();

	identify(base);
	identify(*base);

	delete base;

	return 0;
}