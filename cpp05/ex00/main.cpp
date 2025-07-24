/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 17:54:19 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	{
		std::cout << "\n\n=== ORTHODOX CANONICAL FORM TESTS ===\n\n";
		
		Bureaucrat a;
		Bureaucrat b("Random Bureaucrat", 1);
		Bureaucrat c(b);
		std::cout << c.getName() << "\n";
		std::cout << "\n\n";
	}

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