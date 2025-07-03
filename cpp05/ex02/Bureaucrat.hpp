/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:58:04 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/03 14:35:40 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	private:

		const std::string name_;
		int grade_;

	public:
	
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		void increaseGrade(int amount);
		void decreaseGrade(int amount);
		
		void signForm(AForm &form);

		std::string getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "Error: Bureaucrat's grade is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "Error: Bureaucrat's grade is too low";
				}
		};
		class GradeNegative : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "Error: Bureaucrat's grade change negative";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);