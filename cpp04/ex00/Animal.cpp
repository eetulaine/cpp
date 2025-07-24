/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:48:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 16:07:39 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : type_(type) {
	std::cout << "Animal constructor called for " << type << "\n";
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called\n";
	type_ = copy.type_;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called\n";
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n";
}

std::string	Animal::getType() const {
	return type_;
}

void	Animal::makeSound() const {
	std::cout << type_ << ": *RANDOM ANIMAL SOUNDS*\n";
}