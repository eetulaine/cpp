/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:57:37 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/27 12:24:51 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool	isWhitespaceOnly(const std::string& str) {
    return str.find_first_not_of(" \t\n\r") == std::string::npos;
}

static void	printFullContact(Contact contact, int index) {
	std::cout << GREEN "\n=== Contact " << index << " Details ===\n" END;
	std::cout << "First Name: " << contact.getFirstName() << "\n";
	std::cout << "Last Name: " << contact.getLastName() << "\n";  
	std::cout << "Nickname: " << contact.getNickname() << "\n";
	std::cout << "Phone Number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << "\n\n";
}

static std::string	getInput(std::string msg) {
	std::string input;
	while (42) {
		std::cout << msg;
		if (std::getline(std::cin, input)) {
			if (!input.empty() && !isWhitespaceOnly(input))
				return (input);
			std::cout << "Input empty. Please try again\n";
		}
		if (std::cin.eof())
			exit (0);
	}
}

static void	printContact(Contact contact, int index) {
	std::cout << std::setw(10) << index;
	if (contact.getFirstName().length() > 9)
		std::cout << "|" << contact.getFirstName().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.getFirstName();
	if (contact.getLastName().length() > 9)
		std::cout << "|" << contact.getLastName().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.getLastName();
	if (contact.getNickname().length() > 9)
		std::cout << "|" << contact.getNickname().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.getNickname();
	std::cout << "\n";
}

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	Contact	newContact;

	std::cout << "Please provide the following information..\n\n";
	newContact.setFirstName(getInput("	First Name: "));
	newContact.setLastName(getInput("	Last Name: "));
	newContact.setNickname(getInput("	Nickname: "));
	newContact.setPhoneNumber(getInput("	Phone Number: "));
	newContact.setDarkestSecret(getInput("	Darkest Secret: "));
	contact[contactId_ % MAX_CONTACTS] = newContact;
	contactId_++;
	std::cout << GREEN "\nContact " END << newContact.getNickname() << GREEN " added\n\n" END;
}

void	PhoneBook::searchContact() {
	if(!contactId_)
	{
		std::cout << "No contacts in the phonebook, please ADD a contact\n";
		return;
    }
	for (int i = 0; i < MAX_CONTACTS; i++) {
		printContact(contact[i], i);
	}
	askIndex();
}

void PhoneBook::askIndex() {
	std::string	input;
	int			index;
    
	while (true) {
		std::cout << "\nEnter index (0-" << (MAX_CONTACTS - 1) << "): ";
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof())
				return;
			continue;
        }
		if (input.empty() || isWhitespaceOnly(input)) {
			std::cout << "Input empty. Please try again\n";
			continue;
		}
		if (input.length() != 1 || !std::isdigit(input[0])) {
			std::cout << "Please enter a single digit (0-" << (MAX_CONTACTS - 1) << ")\n";
			continue;
		}
		index = input[0] - '0';
        if (index < 0 || index >= MAX_CONTACTS) {
            std::cout << "Index out of range. Please enter 0-" << (MAX_CONTACTS - 1) << "\n";
            continue;
        }
		if (index >= contactId_ || contact[index].getFirstName().empty()) {
			std::cout << "No contact at index " << index << "\n";
			continue;
		}
		printFullContact(contact[index], index);
		return;
    }
}
