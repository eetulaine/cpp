/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:23:35 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 11:39:25 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	
	private:
		int		fixedPoint_;
		static const int fractional_ = 8;
 
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int const fixedPoint);
		Fixed	&operator = (const Fixed &copy);
};