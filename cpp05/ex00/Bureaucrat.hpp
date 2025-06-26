/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:58:04 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 14:48:48 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat {

	private:

		const std::string name_;
		unsigned int grade_;

	public:
	
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		void increaseGrade();
		void decreaseGrade();

		std::string getName() const;
		unsigned int getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "The grade is too high\n";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return "The grade is too low\n";
				}
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &other);