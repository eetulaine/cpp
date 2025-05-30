/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:15:19 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 13:23:17 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name_(name) {
	std::cout << "Zombie " << name_ << " has risen\n";
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name_ << " destroyed\n";
}

void Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
