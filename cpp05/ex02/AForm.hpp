/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:07:34 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/03 16:17:47 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
	
	private:

		const std::string name_ = "Default form";
		bool signed_ = false;
		const int signGrade_ = 10;
		const int execGrade_ = 10;
		virtual void formExecuted() const = 0;
	
	public:

		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &other);
	
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
		bool isSigned() const;

		void execute(const Bureaucrat &executor) const;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "grade needed for form is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "grade needed for form is too low";
				}
		};
		class GradeNegative : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "bureaucrat's grade is negative";
				}
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept {
					return "Form already signed";
				}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept {
					return "Form not signed and cannot be executed";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);