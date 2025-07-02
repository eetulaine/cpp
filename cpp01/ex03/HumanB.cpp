/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:06:57 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/02 12:32:54 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void HumanB::attack() {
	if (weapon_)
		std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
}