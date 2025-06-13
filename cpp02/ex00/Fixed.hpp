/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:23:35 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:59 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	
	private:
		int		raw_;
		static const int fractional_ = 8;
 
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
		Fixed& operator = (const Fixed& copy);
};