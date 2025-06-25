/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:48:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/25 11:42:26 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called\n";
	type_ = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal copy constructor called\n";
	type_ = copy.type_;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called\n";
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called\n";
}

std::string	AAnimal::getType() const {
	return type_;
}
