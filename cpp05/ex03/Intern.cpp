/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:45:23 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/15 11:50:23 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern hired\n";
}

Intern::~Intern() {
	std::cout << "Intern fired..\n";
}

static AForm *makeShrub(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobo(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *makePres(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target) {
	
	AForm *(*makeFormFunc[])(std::string target) = {&makePres, &makeRobo, &makeShrub};

	const std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *newForm = NULL;

	for (int i = 0; i < 3; i++) {
		if (form == forms[i]) {
			newForm = makeFormFunc[i](target);
			break ;
		}
	}
	if (!newForm)
		throw FormNotCreatedException();

	std::cout << "Intern creates " << form << "\n";

	return newForm;
}