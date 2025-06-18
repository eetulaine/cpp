/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 14:59:26 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    
	ScavTrap scav("Tuco");
	std::cout << "\nScavTrap initialized as:\n\n";
	std::cout << "	Name: " << scav.getName() << "\n";
	std::cout << "	Hit Points: " << scav.getHitPoints() << "\n";
	std::cout << "	Energy Points: " << scav.getEnergyPoints() << "\n";
	std::cout << "	Attack Damage: " << scav.getAttackDamage() << "\n\n";

	scav.guardGate();

	ScavTrap scav2("Hank");
	scav.attack(scav2.getName());

	return 0;
}