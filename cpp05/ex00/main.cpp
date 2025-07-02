/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/02 14:09:21 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	try {
		Bureaucrat Pekka("Pekka", 7);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Pirjo("Pirjo", 151);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat Riitta("Riitta", 1);
	try {
		Riitta.decreaseGrade(4);
		std::cout << Riitta.getName() << "'s new grade: " << Riitta.getGrade() << "\n";
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat Olli("Olli", 4);
	try {
		Olli.increaseGrade(-3);
		std::cout << Olli.getName() << "'s new grade: " << Olli.getGrade() << "\n";
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}