/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:50:02 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/16 15:46:27 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// comparison operators
	std::cout << "\n\nComparison operators\n===========\n\n";
	if (Fixed(3) > Fixed(2.99f))
		std::cout << ">: ✅\n";
	if (Fixed(1.99f) < Fixed(100))
		std::cout << "<: ✅\n";
	if (Fixed(7) >= Fixed(7.00f))
		std::cout << ">=: ✅\n";
	if (Fixed(900) >= Fixed(9.99f))
		std::cout << ">=: ✅\n";
	if (Fixed(7) <= Fixed(7.00f))
		std::cout << "<=: ✅\n";
	if (Fixed(2) <= Fixed(7.00f))
		std::cout << "<=: ✅\n";
	if (Fixed(7) == Fixed(7.00f))
		std::cout << "==: ✅\n";
	if (Fixed(1.01f) != Fixed(1))
		std::cout << "!=: ✅\n";

	// arithmetic operators
	std::cout << "\n\nArithmetic operators\n===========\n\n";
	Fixed const n1(Fixed(2.00f) + Fixed(2));
	std::cout << "2.00 + 2 = " << n1 << "\n";
	Fixed const n2(Fixed(44.00f) - Fixed(2));
	std::cout << "44.00 - 2 = " << n2 << "\n";
	Fixed const n3(Fixed(3512.70f) * Fixed(3));
	std::cout << "3512.70 * 3 = " << n3 << "\n";
	Fixed const n4(Fixed(84.80f) / Fixed(2));
	std::cout << "84.80 / 2 = " << n4 << "\n";

	return 0;
}
