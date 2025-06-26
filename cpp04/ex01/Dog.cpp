/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:03:49 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 09:45:33 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called\n";
	type_ = "Dog";
	brain_ = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog copy constructor called\n";
	type_ = copy.type_;
	brain_ = new Brain(*copy.brain_);
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Dog::~Dog() {
	delete brain_;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const {
	std::cout << type_ << ": *MEOWW*\n";
}

void	Dog::setIdea(unsigned int n, std::string idea) {
	if (n > 99)
		std::cout << "Dog has too many ideas!\n";
	else
		brain_->ideas_[n] = idea;
}

std::string Dog::getIdea(unsigned int n) {
	if (n > 99)
		return "Dog has too many ideas!\n";
	else
		return brain_->ideas_[n];
}
