#pragma once
#include <iostream>

class ClapTrap {

    private:
        std::string name_;
        int hitPoints_;
        int energyPoints_;
        int attackDamage_;
    
    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator= (const ClapTrap &other);
        ~ClapTrap();

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        void    setName(std::string name);
        void    setHitPoints(int hitPoints);
        void    setEnergyPoints(int energyPoints);
        void    setAttackDamage(int attackDamage);

        std::string getName();
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
};