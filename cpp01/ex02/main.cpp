/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:18:38 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/03 15:37:20 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "\nMEMORY ADDRESSES\n";
	std::cout << "string:		" << &brain << "\n";
	std::cout << "stringPTR:	" << stringPTR << "\n";
	std::cout << "stringREF:	" << &stringREF << "\n";

	std::cout << "\nVALUES\n";
	std::cout << "string:		" << brain << "\n";
	std::cout << "stringPTR:	" << *stringPTR << "\n";
	std::cout << "stringREF:	" << stringREF << "\n\n";
}