/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:21:53 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 11:40:18 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) : fixedPoint_(copy.fixedPoint_) {
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator = (const Fixed &copy) {
	std::cout << "Copy assignment operator called\n";
	if (this != &copy) {
		fixedPoint_ = copy.fixedPoint_;
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawbits called\n";
	return fixedPoint_;
}

void Fixed::setRawBits(int const fixedPoint) {
	std::cout << "setRawBits called\n";
	fixedPoint_ = fixedPoint;
}
