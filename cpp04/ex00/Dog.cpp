/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:03:49 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/16 15:52:54 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called\n";
	type_ = "Dog";
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy constructor called\n";
	type_ = copy.type_;
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const {
	std::cout << type_ << ": *WOOF*\n";
}