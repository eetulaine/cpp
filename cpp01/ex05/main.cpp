/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:57:12 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/10 11:08:26 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {

	Harl harl;

	std::cout << "\nDebug:\n";
	harl.complain("DEBUG");
	std::cout << "\nInfo:\n";
	harl.complain("INFO");
	std::cout << "\nWarning:\n";
	harl.complain("WARNING");
	std::cout << "\nError:\n";
	harl.complain("ERROR");
	std::cout << "\nInvalid:\n";
	harl.complain("BLEEP BLOOP");

	return 0;
}