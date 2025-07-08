/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/08 12:30:32 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main() {

    try {

		std::cout << "\n=== PRESIDENTIAL PARDON FORM TESTS ===\n";
    	std::cout << "\nCreating a new form..\n";
		PresidentialPardonForm form01("Big Bank CEO");

		std::cout << "\nCreating a new high-ranking bureaucrat..\n";
		Bureaucrat highRank1("Judge Judy", 1);

		std::cout << "\nSigning & executing a form..\n";
		highRank1.executeForm(form01);
		highRank1.signForm(form01);
		highRank1.executeForm(form01);

		std::cout << "\nCreating a new low-ranking bureaucrat..\n";
		Bureaucrat lowRank1("Janitor", 148);
		std::cout << "\nTrying to sign a form that's already signed..\n";
		lowRank1.signForm(form01);

		std::cout << "\nTrying to sign a form requiring a more high-ranked bureaucrat..\n";
		PresidentialPardonForm form02("Random crook");
		lowRank1.signForm(form02);
		lowRank1.executeForm(form02);

		std::cout << "\n=== ROBOTOMY REQUEST FORM TESTS ===\n";

		std::cout << "\nCreating a new RobotomyRequestForm..\n";
		RobotomyRequestForm robotForm01("Bender");

		std::cout << "\nCreating a high-ranking bureaucrat..\n";
		Bureaucrat highRank("Dr. Zoidberg", 1);

		std::cout << "\nTrying to execute unsigned form..\n";
		highRank.executeForm(robotForm01);

		std::cout << "\nSigning the form..\n";
		highRank.signForm(robotForm01);

		std::cout << "\nExecuting signed form (should make drilling noises and have 50% success rate)..\n";
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);

		std::cout << "\nCreating a bureaucrat with exactly sign grade (72)..\n";
		Bureaucrat signGrade("Hermes", 72);
		RobotomyRequestForm robotForm02("Fry");
		signGrade.signForm(robotForm02);

		std::cout << "\nTrying to execute with sign-grade bureaucrat (should fail - needs grade 45)..\n";
		signGrade.executeForm(robotForm02);

		std::cout << "\nCreating a bureaucrat with exactly execute grade (45)..\n";
		Bureaucrat executeGrade("Professor Farnsworth", 45);
		executeGrade.executeForm(robotForm02);

		std::cout << "\nCreating a low-ranking bureaucrat..\n";
		Bureaucrat lowRank("Scruffy", 100);
		RobotomyRequestForm robotForm03("Leela");

		std::cout << "\nTrying to sign with insufficient grade..\n";
		lowRank.signForm(robotForm03);

		std::cout << "\nTrying to execute with insufficient grade..\n";
		lowRank.executeForm(robotForm03);

		std::cout << "\n=== SHRUBBERY CREATION FORM TESTS ===\n";

		std::cout << "\nCreating a new ShrubberyCreationForm..\n";
		ShrubberyCreationForm shrubForm01("home");

		std::cout << "\nCreating a high-ranking bureaucrat..\n";
		Bureaucrat highRank2("Lrrr", 1);

		std::cout << "\nTrying to execute unsigned form..\n";
		highRank2.executeForm(shrubForm01);

		std::cout << "\nSigning the form..\n";
		highRank2.signForm(shrubForm01);

		std::cout << "\nExecuting signed form (should create a file)..\n";
		highRank2.executeForm(shrubForm01);

		std::cout << "\nCreating a bureaucrat with exactly sign grade (145)..\n";
		Bureaucrat signGrade2("Zapp Brannigan", 145);
		ShrubberyCreationForm shrubForm02("office");
		signGrade2.signForm(shrubForm02);

		std::cout << "\nTrying to execute with sign-grade bureaucrat (should fail - needs grade 137)..\n";
		signGrade2.executeForm(shrubForm02);

		std::cout << "\nCreating a bureaucrat with exactly execute grade (137)..\n";
		Bureaucrat executeGrade2("Kif", 137);
		executeGrade2.executeForm(shrubForm02);

		std::cout << "\nCreating a low-ranking bureaucrat..\n";
		Bureaucrat lowRank2("Nixon", 150);
		ShrubberyCreationForm shrubForm03("garden");

		std::cout << "\nTrying to sign with insufficient grade..\n";
		lowRank2.signForm(shrubForm03);

		std::cout << "\nTrying to execute with insufficient grade..\n";
		lowRank2.executeForm(shrubForm03);

		std::cout << "\nCreating another shrubbery form with different target..\n";
		ShrubberyCreationForm shrubForm04("park");
		highRank2.signForm(shrubForm04);
		highRank2.executeForm(shrubForm04);

		std::cout << "\nTesting file creation - check for 'home_shrubbery', 'office_shrubbery', and 'park_shrubbery' files\n";

    } catch (std::exception &e) {
        std::cout << "Something went wrong.. " << e.what() << std::endl;
	}
	return 0;
}