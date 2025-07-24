/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:58:25 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 18:32:53 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Unknown"), grade_(150) {
	std::cout << "New bureaucrat arrives to the office\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	grade_ = grade;
	std::cout << name_ << ", bureaucrat grade " << grade_ << "\n";
}

Bureaucrat::~Bureaucrat () {
	std::cout << "Bureaucrat " << name_ << " got fired\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.name_), grade_(copy.grade_) {
	std::cout << "Copy constructor called for " << name_ << "\n";
}

void Bureaucrat::increaseGrade(int amount) {
	if (amount < 0)
		throw GradeNegative();
	if (grade_ - amount < 1)
		throw GradeTooHighException();
	else
		grade_ -= amount;
}

void Bureaucrat::decreaseGrade(int amount) {
	if (amount < 0)
		throw GradeNegative();
	if (grade_ + amount > 150)
		throw GradeTooLowException();
	else
		grade_ += amount;
}

std::string Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return os;
}