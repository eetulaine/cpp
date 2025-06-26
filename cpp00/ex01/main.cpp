/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:15:41 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/26 10:25:24 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	PhoneBook	phonebook;
	std::string	input;

	while (42) {

		std::cout << "Please use ADD, SEARCH or EXIT\n";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return 1;
		else if (input == "EXIT")
			return 1;
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "")
			continue ;
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}