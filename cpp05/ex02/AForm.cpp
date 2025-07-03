/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:14:23 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/03 15:36:51 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() {
	std::cout << "New AForm ready to be signed\n";
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : name_(name), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 0 || execGrade < 0)
		throw GradeNegative();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {
	std::cout << "AForm " << name_ << " shredded\n";
}

AForm::AForm(const AForm &copy) : 
	name_(copy.name_), signed_(copy.signed_), signGrade_(copy.signGrade_), execGrade_(copy.execGrade_) {
	std::cout << "Copy contructor called for " << name_ << "\n";
}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other) {
		signed_ = other.signed_;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (signed_)
		throw FormAlreadySignedException();
	if (bureaucrat.getGrade() > signGrade_)
		throw GradeTooLowException();
	signed_ = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (signed_)
		throw FormAlreadySignedException();
	if (executor.getGrade() > signGrade_)
		throw GradeTooLowException();
	signed_ = true;
}

std::string AForm::getName() const {
	return name_;
}

int AForm::getSignGrade() const {
	return signGrade_;
}

int AForm::getExecGrade() const {
	return execGrade_;
}

bool AForm::isSigned() const {
	return signed_;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	std::string sign = "YES";
	if (form.isSigned())
		sign = "NO";
	os << "AForm: " << form.getName() << "\n" << "Sign grade: " << form.getSignGrade() << "\n" 
	<< "Exec grade: " << form.getExecGrade() << "\n" << "Signed: " << sign << "\n";
	return os;
}