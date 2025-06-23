/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:04:15 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/23 15:41:09 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called\n";
	type_ = "Cat";
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called\n";
	type_ = copy.type_;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

Cat::~Cat() {
	delete brain_;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const {
	std::cout << type_ << ": *MEOWW*\n";
}