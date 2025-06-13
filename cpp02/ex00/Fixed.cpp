/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:21:53 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:44 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy) : raw_(copy.raw_) {
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed & Fixed::operator = (const Fixed& copy) {
	std::cout << "Copy assignment operator called\n";
	if (this != &copy) {
		raw_ = copy.raw_;
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawbits called\n";
	return raw_;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits called\n";
	raw_ = raw;
}
