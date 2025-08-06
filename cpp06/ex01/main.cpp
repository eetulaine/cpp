/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:36:13 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/06 15:46:11 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	
	try {
		
		Data d;
		d.id = 42;
		d.name = "Clement";

		std::cout << "Data stored..\nID: " << d.id << "\nName: " << d.name << "\n\n";
		
		uintptr_t raw = Serializer::serialize(&d);

		std::cout << "Creating copy...\n\n";
		
		Data* copy = Serializer::deserialize(raw);

		std::cout << "Data address: " << &d << "\n";
		std::cout << "Copy address: " << copy << "\n";
		std::cout << "Match: " << std::boolalpha << (&d == copy) << "\n\n";
		std::cout << "Copy contents:\nID: " << copy->id << "\nName: " << copy->name << "\n";
		
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}