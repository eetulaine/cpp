#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : 
    name_(name),
    hitPoints_(10),
    energyPoints_(10),
    attackDamage_(0) {
        std::cout << "Default constructor called\n";
    }

ClapTrap::ClapTrap(const ClapTrap &copy) : 
    name_(copy.name_),
    hitPoints_(copy.hitPoints_),
    energyPoints_(copy.energyPoints_),
    attackDamage_(copy.attackDamage_) {
        std::cout << "Copy constructor called\n";
    }

ClapTrap& Claptrap::operator=(const ClapTrap &other) {
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
    std::cout << "Destructor called\n";
}

// functions

 void ClapTrap::attack(const std::string &target) {
    if (energyPoints_ < 1)
        return std::cout << "ClapTrap " << name_ << " has no energy to attack!\n";
    if (hitPoints_ < 1)
        return std::cout << "ClapTrap " << name_ << " is dead :(\n";
    energyPoints_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target <<", causing " << attackDamage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints_ < 1)
        return std::cout << "Poor ClapTrap " << name_ << " is already dead :(\n";
    hitPoints_ -= amount;
    if (hitPoints_ < 1)
        return std::cout << "ClapTrap " << name_ << " died after taking " << amount << " damage!\n";
	std::cout << "ClapTrap " << name_ << " has taken " << amount << " damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints_ < 1)
        return std::cout << "ClapTrap " << name_ << " has no energy for repairs!\n";
    if (hitPoints_ < 1)
        return std::cout << "Poor ClapTrap " << name_ << " is already dead :(\n";
    hitPoints_ += amount;
    std::cout << "ClapTrap " << name_ << " self-repairs and recovers " << amount << "HP!\n";
    std::cout << "ClapTrap " << name_ << " has " << hitPoints_ << "HP now\n";
}

// getters and setters

std::string ClapTrap::getName() {
    return name_;
}

int ClapTrap::getHitPoints() {
    return hitPoints_;
}

int ClapTrap::getEnergyPoints() {
    return energyPoints_;
}

int ClapTrap::getAttackDamage() {
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