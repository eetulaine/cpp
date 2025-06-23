/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:48:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/23 14:08:07 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called\n";
	type_ = "Animal";
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