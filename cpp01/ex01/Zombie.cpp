/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:54 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 14:35:53 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << "Zombie " << name_ << " destroyed\n";
}

void Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name, int i) {
	this->name_ = name + " " + std::to_string(i + 1);
}