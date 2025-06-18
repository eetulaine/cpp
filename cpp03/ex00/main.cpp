/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:38 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 14:46:31 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    
	ClapTrap c1("Lalo");
	std::cout << "ClapTrap initialized as:\n\n";
	std::cout << "	Name: " << c1.getName() << "\n";
	std::cout << "	Hit Points: " << c1.getHitPoints() << "\n";
	std::cout << "	Energy Points: " << c1.getEnergyPoints() << "\n";
	std::cout << "	Attack Damage: " << c1.getAttackDamage() << "\n\n";

	ClapTrap c2("Gus");
	std::cout << "\nTesting attacks, damage, repairs and dying:\n\n";
	c2.setAttackDamage(9);
	c2.attack(c1.getName());
	c1.takeDamage(c2.getAttackDamage());
	c1.beRepaired(5);
	for (int i = 0; i < 11; i++) {
		c1.attack(c2.getName());
	}
	c2.attack(c1.getName());
	c1.takeDamage(c2.getAttackDamage());
	c1.attack(c2.getName());
	std::cout << "\n";

	return 0;
}