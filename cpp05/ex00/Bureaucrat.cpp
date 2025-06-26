/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:58:25 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 15:08:33 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "New bureaucrat arrives to the office\n";
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name_(name) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	else
		grade_ = grade;
	std::cout << name_ << ", bureaucrat grade " << grade_ << "\n";
}

Bureaucrat::~Bureaucrat () {
	std::cout << "Bureaucrat " << name_ << " got fired\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.name_), grade_(copy.grade_) {
	std::cout << "Copy constructor called for " << name_ << "\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		grade_ = other.grade_;
	return *this;
}

void Bureaucrat::increaseGrade() {
	if (grade_ == 1)
		throw GradeTooHighException();
	else
		grade_--;
}

void Bureaucrat::decreaseGrade() {
	if (grade_ == 150)
		throw GradeTooLowException();
	else
		grade_++;
}


std::string Bureaucrat::getName() const {
	return name_;
}

unsigned int Bureaucrat::getGrade() const {
	return grade_;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
}