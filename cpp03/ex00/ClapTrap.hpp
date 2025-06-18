/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:33 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 14:24:01 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap {

    private:
        std::string name_;
        int hitPoints_;
        int energyPoints_;
        int attackDamage_;
    
    public:
		ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        void    setName(std::string name);
        void    setHitPoints(int hitPoints);
        void    setEnergyPoints(int energyPoints);
        void    setAttackDamage(int attackDamage);

        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
};