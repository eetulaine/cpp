/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:23:35 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 14:59:23 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	
	private:
		int		fixedPoint_;
		static const int fractional_ = 8;
 
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int n);
		Fixed(const float n);
		Fixed &operator = (const Fixed &other);
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(const int fixedPoint);
		int		toInt() const;
		float	toFloat() const;

		bool	operator > (const Fixed &other) const;
		bool	operator < (const Fixed &other) const;
		bool	operator >= (const Fixed &other) const;
		bool	operator <= (const Fixed &other) const;
		bool	operator == (const Fixed &other) const;
		bool	operator != (const Fixed &other) const;

		Fixed	operator + (const Fixed &rhs) const; //rhs = right-hand side
		Fixed	operator - (const Fixed &rhs) const;
		Fixed	operator * (const Fixed &rhs) const;
		Fixed	operator / (const Fixed &rhs) const;

		Fixed&	operator++(); // pre-increment
		Fixed	operator++(int); // post-increment
		Fixed&	operator--(); // pre-decrement
		Fixed	operator--(int); // post-decrement
		
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator << (std::ostream &stream, const Fixed &fixed);