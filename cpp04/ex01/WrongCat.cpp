/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:35 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/23 14:10:00 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called\n";
	type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called\n";
	type_ = copy.type_;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound() const {
	std::cout << type_ << ": *CHIRP*\n";
}
