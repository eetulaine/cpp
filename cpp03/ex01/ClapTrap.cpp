/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:00:56 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 14:58:03 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    name_("Default ClapTrap"),
    hitPoints_(10),
    energyPoints_(10),
    attackDamage_(0) {
        std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : 
    name_(name),
    hitPoints_(10),
    energyPoints_(10),
    attackDamage_(0) {
        std::cout << "ClapTrap constructor called for " << name << "\n";
}

ClapTrap::ClapTrap(std::string name, int hp, int energy, int atk) : 
    name_(name),
    hitPoints_(hp),
    energyPoints_(energy),
    attackDamage_(atk) {
        std::cout << "ClapTrap constructor called for " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) : 
    name_(copy.name_),
    hitPoints_(copy.hitPoints_),
    energyPoints_(copy.energyPoints_),
    attackDamage_(copy.attackDamage_) {
        std::cout << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name_ << "\n";
}

// functions

 void ClapTrap::attack(const std::string &target) {
	if (hitPoints_ < 1) {
		std::cout << "ClapTrap " << name_ << " is dead and can't do an attack.. like ever :(\n";
		return;
	}
    if (energyPoints_ < 1) {
		std::cout << "ClapTrap " << name_ << " has no energy to attack!\n";
		return;
	}
    energyPoints_--;
	if (!attackDamage_)
		std::cout << "ClapTrap " << name_ << " attacks " << target <<" but does 0 damage\n";
	else
		std::cout << "ClapTrap " << name_ << " attacks " << target <<", causing " << attackDamage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints_ < 1) {
		std::cout << "Poor ClapTrap " << name_ << " is already dead :(\n";
		return;
	}
    hitPoints_ -= amount;
    if (hitPoints_ < 1) {
		std::cout << "ClapTrap " << name_ << " died after taking " << amount << " damage!\n";
		return;
	}
	std::cout << "ClapTrap " << name_ << " has taken " << amount << " damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints_ < 1) {
		std::cout << "ClapTrap " << name_ << " has no energy for repairs!\n";
		return;
	}
    if (hitPoints_ < 1) {
		std::cout << "Poor ClapTrap " << name_ << " is already dead :(\n";
		return;
	}
    hitPoints_ += amount;
    std::cout << "ClapTrap " << name_ << " self-repairs and recovers " << amount << " hit points\n";
    std::cout << "ClapTrap " << name_ << " has " << hitPoints_ << " hit points now\n";
}

// getters and setters

std::string ClapTrap::getName() const {
    return name_;
}

int ClapTrap::getHitPoints() const {
    return hitPoints_;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints_;
}

int ClapTrap::getAttackDamage() const {
    return attackDamage_;
}

void ClapTrap::setName(std::string name) {
    name_ = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
    hitPoints_ = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    energyPoints_ = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
    attackDamage_ = attackDamage;
}