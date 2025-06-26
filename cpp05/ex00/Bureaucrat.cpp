/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:58:25 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 13:56:18 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "New bureaucrat arrives to the office\n";
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name_(name) {
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
	else
		grade_ = grade;
}

Bureaucrat::~Bureaucrat () {
	std::cout << "Bureaucrat got fired\n";
}


std::string Bureaucrat::getName() const {
	return name_;
}

unsigned int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::setName(std::string name) {
	name_ = name;
}

void Bureaucrat::setGrade(unsigned int grade) {
	grade_ = grade;
}