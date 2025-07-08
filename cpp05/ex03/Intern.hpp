/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:39:19 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/08 13:02:03 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	
	public:
		
		Intern();
		~Intern();
		Intern(const Intern &copy) = delete;
		Intern &operator=(const Intern &other) = delete;
	
		AForm* makeForm(std::string form, std::string target);

		class FormNotCreatedException : public std::exception {
			public:
				const char* what() const noexcept {
					return "Intern couldn't make the form!";
				}
		};
};
