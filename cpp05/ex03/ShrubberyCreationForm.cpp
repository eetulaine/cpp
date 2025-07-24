/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:16:17 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 18:27:12 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target_("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
	std::cout << "ShrubberyCreationForm for " << target_ << " created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target_(copy.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm shredded...\n";
}

void ShrubberyCreationForm::formExecuted() const {
	
	std::string tree = R"(
                                           .         ;  
                 .              .              ;%     ;;   
                   ,           ,                :;%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,..    )";

	std::ofstream file(target_ + "_shrubbery");
	if (!file)
		throw std::runtime_error("Cannot open file for writing: " + target_);
	file << tree;
}