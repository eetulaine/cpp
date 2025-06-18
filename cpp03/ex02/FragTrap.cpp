/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:28:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 15:37:05 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default FragTrap", 100, 100, 30) {
	std::cout << "FragTrap default contructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap constructor called for " << name << "\n";
}

FragTrap::FragTrap(const FragTrap &copy) : 
	ClapTrap(copy.name_, copy.hitPoints_, copy.energyPoints_, copy.attackDamage_) {
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << name_ << "\n";
}

void FragTrap::highFivesGuys() {
	std::cout << name_ << ": 'Heyy gimme a high five guys!'\n";
}

void FragTrap::attack(const std::string &target) {
	if (hitPoints_ < 1)
		std::cout << "FragTrap " << name_ << " is dead and can't attack\n";
	else if (energyPoints_ < 1)
		std::cout << "FragTrap " << name_ << " doesn't have enough energy to attack\n";
	else
		std::cout << "FragTrap " << name_ << " attacks " << target << " for " << attackDamage_ << " damage!\n";
}