/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:17 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/07 12:40:43 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default ScavTrap", 100, 50, 20) {
	std::cout << "ScavTrap default contructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap constructor called for " << name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : 
	ClapTrap(copy.name_, copy.hitPoints_, copy.energyPoints_, copy.attackDamage_) {
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << name_ << "\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name_ << " is now in Gate Keeper mode\n";
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints_ < 1)
		std::cout << "ScavTrap " << name_ << " is dead and can't attack\n";
	else if (energyPoints_ < 1)
		std::cout << "ScavTrap " << name_ << " doesn't have enough energy to attack\n";
	else {
		std::cout << "ScavTrap " << name_ << " attacks " << target << " for " << attackDamage_ << " damage!\n";
		energyPoints_--;
	}
}
