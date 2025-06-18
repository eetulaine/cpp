/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:23:35 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 12:59:24 by eelaine          ###   ########.fr       */
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
		Fixed(const Fixed &copy);
		Fixed(const int n);
		Fixed(const float n);
		Fixed &operator = (const Fixed &other);
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(const int fixedPoint);
		int		toInt() const;
		float	toFloat() const;
};

std::ostream	&operator << (std::ostream &stream, const Fixed &fixed);