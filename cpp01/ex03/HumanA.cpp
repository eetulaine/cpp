/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:00:45 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/02 12:32:44 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon) {
	this->name_ = name;
}
void HumanA::attack() {
	std::cout << name_ << " attacks with their " << weapon_.getType() << "\n";
}
