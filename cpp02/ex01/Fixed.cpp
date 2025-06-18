/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:21:53 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 12:08:07 by eelaine          ###   ########.fr       */
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

Fixed& Fixed::operator = (const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		fixedPoint_ = other.fixedPoint_;
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getfixedPointbits called\n";
	return fixedPoint_;
}

void Fixed::setRawBits(const int fixedPoint) {
	std::cout << "setfixedPointBits called\n";
	fixedPoint_ = fixedPoint;
}

// converts int to fixed-point
// shifts the integer left by the fractional (8 bits)
// effectively: multiplies integer up by 2^fractional (=256) to store it as fixed-point
// example: 42 * 256 = 10752 
Fixed::Fixed(const int n) : fixedPoint_(n << fractional_) {
	std::cout << "Int constructor called\n";
}

// converts float to fixed-point
// 1 << fractional_ creates scaling factor (2^8)
// multiplies the float by scaling factor to convert to int: roundf(n * 256)
// roundf: rounds to nearest int to minimize precision loss
Fixed::Fixed(const float n) : fixedPoint_(roundf(n * (1 << fractional_))) {
	std::cout << "Float constructor called\n";
}

// converts fixed-point back to int
// shift right, dividing by 2^fractional
// truncates fractional part
int	Fixed::toInt() const {
	return (fixedPoint_ >> fractional_);
}

// converts fixed-point back to float
// divides fixedPoint by scaling factor
// cast to float for decimal representation
float Fixed::toFloat() const {
	return (float)fixedPoint_ / (1 << fractional_);
}

// overlaods the output stream operator for printing
// uses toFloat() to get decimal representation
// returns stream reference
std::ostream	&operator << (std::ostream &stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return stream;
}
