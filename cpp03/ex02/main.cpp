/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 15:34:38 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    
	FragTrap frag("Heisenberg");
	std::cout << "\nFragTrap initialized as:\n\n";
	std::cout << "	Name: " << frag.getName() << "\n";
	std::cout << "	Hit Points: " << frag.getHitPoints() << "\n";
	std::cout << "	Energy Points: " << frag.getEnergyPoints() << "\n";
	std::cout << "	Attack Damage: " << frag.getAttackDamage() << "\n\n";

	frag.highFivesGuys();

	ScavTrap scav2("Hank");
	frag.attack(scav2.getName());

	return 0;
}