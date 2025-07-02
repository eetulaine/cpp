/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:14:10 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/02 15:48:44 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
	
	private:
		const std::string name_ = "Default form";
		bool signed_ = false;
		const int signGrade_ = 10;
		const int execGrade_ = 10;
	
	public:

		Form();
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &other);
	
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
		bool isSigned() const;
		
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
					return "form already signed";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &f);