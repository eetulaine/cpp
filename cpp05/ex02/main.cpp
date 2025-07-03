/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/03 14:13:37 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

    try {
    	std::cout << "\n\nCreating a new form..\n";
		AForm mostWantedList("Most Wanted List", 20, 10);
		std::cout << mostWantedList;
        
        std::cout << "\n\nHiring bureaucrats..\n";
        Bureaucrat bigShot("Michelle", 10);
        Bureaucrat lowRank("Mike", 120);
        
        std::cout << "\n\nBureaucrat signs a form succesfully..\n";
        bigShot.signForm(mostWantedList);
        
        std::cout << "\n\nTrying to sign the same form twice..\n";
        bigShot.signForm(mostWantedList);
        
        std::cout << "\n\nA low-ranking bureaucrat tries to sign a classified document..\n";
        AForm topSecret("Top Secret document", 50, 25);
        lowRank.signForm(topSecret);
        
        std::cout << "\n\nA low-ranking bureaucrat signs a totally meaningless piece of paper..\n";
        AForm simple("order form for paperclips", 140, 140);
        lowRank.signForm(simple);
        
        std::cout << "\n\nCreating invalid forms..\n";
        try {
            AForm invalidForm("Invalid Form", 0, 50);
        } catch (std::exception &e) {
            std::cout << "Something went wrong.. " << e.what() << std::endl;
        }
        try {
            AForm invalidForm2("Invalid Form", 100, 151);
        } catch (std::exception &e) {
            std::cout << "Something went wrong.. " << e.what() << std::endl;
        }
		
		std::cout << "\n\nPromoting bureaucrat so that they can sign the classified document..\n";
		lowRank.increaseGrade(100);
		lowRank.signForm(topSecret);
		std::cout << "\n\n";
        
    } catch (std::exception &e) {
        std::cout << "Something went wrong.. " << e.what() << std::endl;
    }

	return 0;
}