/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/07 13:45:05 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main() {

    try {
    	std::cout << "\n\nCreating a new form..\n";
		PresidentialPardonForm form01("Big Bank CEO");
		Bureaucrat highRank("Judge Judy", 1);
		highRank.signForm(form01);
		highRank.executeForm(form01);
		
    } catch (std::exception &e) {
        std::cout << "Something went wrong.. " << e.what() << std::endl;
    }

	return 0;
}