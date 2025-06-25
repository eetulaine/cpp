/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:04:15 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/25 10:55:40 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
	brain_ = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called\n";
	brain_ = new Brain(*copy.brain_);
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
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

void	Cat::setIdea(unsigned int n, std::string idea) {
	if (n > 99)
		std::cout << "Cat has too many ideas!\n";
	else
		brain_->ideas_[n] = idea;
}

std::string Cat::getIdea(unsigned int n) {
	if (n > 99)
		return "Cat has too many ideas!\n";
	else
		return brain_->ideas_[n];
}