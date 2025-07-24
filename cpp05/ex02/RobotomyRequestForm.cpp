/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:16:13 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 18:25:09 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("Default target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::cout << "RobotomyRequestForm for " << target_ << " created\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm shredded..\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target_(copy.target_) {}

void RobotomyRequestForm::formExecuted() const {
	
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, 1);	
	
	std::cout << "*SCREEECHHHHHHH*\n";
	if (!dis(gen))
		std::cout << target_ << " has been robotomized\n";
	else
		std::cout << "Failed to robotomize " << target_ << "\n";
}
