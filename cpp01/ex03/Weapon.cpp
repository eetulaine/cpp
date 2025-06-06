/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:52:39 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/06 14:57:34 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

void	Weapon::setType(std::string type) {
	this->type_ = type;
}

const	std::string &Weapon::getType() {
	return (this->type_);
}

Weapon::Weapon(std::string type) {
	this->setType(type);
}