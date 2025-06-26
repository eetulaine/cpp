/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 15:47:10 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	try {
		Bureaucrat Pekka("Pekka", 0);
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
		Riitta.increaseGrade();
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat Olli("Olli", -1);
	try {
		Olli.decreaseGrade();
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	return 0;
}