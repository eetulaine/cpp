/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/25 16:48:13 by eelaine          ###   ########.fr       */
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
		RobotomyRequestForm robotForm01("R2D2");

		std::cout << "\nCreating a high-ranking bureaucrat..\n";
		Bureaucrat highRank("Obi-Wan Kenobi", 1);

		std::cout << "\nTrying to execute unsigned form..\n";
		highRank.executeForm(robotForm01);

		std::cout << "\nSigning the form..\n";
		highRank.signForm(robotForm01);

		std::cout << "\nExecuting signed form (drilling noises and 50% success rate)..\n";
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);
		highRank.executeForm(robotForm01);

		std::cout << "\nCreating a bureaucrat with exactly sign grade..\n";
		Bureaucrat signGrade("Randy", 72);
		RobotomyRequestForm robotForm02("Bleep");
		signGrade.signForm(robotForm02);

		std::cout << "\nTrying to execute with too low of a grade..\n";
		signGrade.executeForm(robotForm02);

		std::cout << "\nCreating a bureaucrat with exactly exec grade..\n";
		Bureaucrat executeGrade("Professor Blurp", 45);
		executeGrade.executeForm(robotForm02);

		std::cout << "\nCreating a low-ranking bureaucrat..\n";
		Bureaucrat lowRank("Scruffy", 100);
		RobotomyRequestForm robotForm03("Blank");

		std::cout << "\nTrying to sign with insufficient grade..\n";
		lowRank.signForm(robotForm03);

		std::cout << "\nTrying to execute with insufficient grade..\n";
		lowRank.executeForm(robotForm03);

		std::cout << "\n=== SHRUBBERY CREATION FORM TESTS ===\n";

		std::cout << "\nCreating a new ShrubberyCreationForm..\n";
		ShrubberyCreationForm shrubForm01("home");

		std::cout << "\nCreating a high-ranking bureaucrat..\n";
		Bureaucrat highRank2("X183", 1);

		std::cout << "\nTrying to execute unsigned form..\n";
		highRank2.executeForm(shrubForm01);

		std::cout << "\nSigning the form..\n";
		highRank2.signForm(shrubForm01);

		std::cout << "\nExecuting signed form (should create a file)..\n";
		highRank2.executeForm(shrubForm01);

		std::cout << "\nCreating a bureaucrat with exactly sign grade..\n";
		Bureaucrat signGrade2("Zippo", 145);
		ShrubberyCreationForm shrubForm02("office");
		signGrade2.signForm(shrubForm02);

		std::cout << "\nTrying to execute with low grade bureaucrat..\n";
		signGrade2.executeForm(shrubForm02);

		std::cout << "\nCreating a bureaucrat with exactly execute grade..\n";
		Bureaucrat executeGrade2("Bozo", 137);
		executeGrade2.executeForm(shrubForm02);

		std::cout << "\nCreating a low-ranking bureaucrat..\n";
		Bureaucrat lowRank2("Hank", 150);
		ShrubberyCreationForm shrubForm03("garden");

		std::cout << "\nTrying to sign with insufficient grade..\n";
		lowRank2.signForm(shrubForm03);

		std::cout << "\nTrying to execute with insufficient grade..\n";
		lowRank2.executeForm(shrubForm03);

		std::cout << "\nCreating another shrubbery form with different target..\n";
		ShrubberyCreationForm shrubForm04("park");
		highRank2.signForm(shrubForm04);
		highRank2.executeForm(shrubForm04);

    } catch (std::exception &e) {
        std::cout << "Something went wrong.. " << e.what() << std::endl;
	}
	return 0;
}