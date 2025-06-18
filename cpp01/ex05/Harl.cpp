/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:37:58 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/10 11:13:45 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
	std::cout << "My sensors report an unusual reading\n";
}

void Harl::info() {
	std::cout << "The oxygen levels are lower than recommended\n";
}

void Harl::warning() {
	std::cout << "The oxygen levels are critically low:\nPreparing escape pods \n";
}

void Harl::error() {
	std::cout << "Launching escape pods now!\nGoodbye humans\n";
}

void Harl::complain(std::string level) {

	std::string levels[]{"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*f[i])();
			return;
		}
	}
	std::cout << "Invalid complain level\n\n";
	return;
}