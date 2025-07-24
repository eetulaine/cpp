/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:14:23 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 18:09:20 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {
	std::cout << "New form ready to be signed\n";
}

Form::Form(const std::string name, int signGrade, int execGrade) : name_(name), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 0 || execGrade < 0)
		throw GradeNegative();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

Form::~Form() {
	std::cout << "Form " << name_ << " shredded\n";
}

Form::Form(const Form &copy) : 
	name_(copy.name_), signed_(copy.signed_), signGrade_(copy.signGrade_), execGrade_(copy.execGrade_) {
	std::cout << "Copy contructor called for " << name_ << "\n";
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (signed_)
		throw FormAlreadySignedException();
	if (bureaucrat.getGrade() > signGrade_)
		throw GradeTooLowException();
	signed_ = true;
}

std::string Form::getName() const {
	return name_;
}

int Form::getSignGrade() const {
	return signGrade_;
}

int Form::getExecGrade() const {
	return execGrade_;
}

bool Form::isSigned() const {
	return signed_;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	std::string sign = "YES";
	if (!form.isSigned())
		sign = "NO";
	os << "Form: " << form.getName() << "\n" << "Sign grade: " << form.getSignGrade() << "\n" 
	<< "Exec grade: " << form.getExecGrade() << "\n" << "Signed: " << sign << "\n";
	return os;
}