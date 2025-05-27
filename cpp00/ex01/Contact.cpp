/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:44:19 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/27 12:13:50 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {
	firstName_ = "";
	lastName_ = "";
	nickname_ = "";
	phoneNumber_ = "";
	darkestSecret_ = "";
	index_ = "";
}

Contact::~Contact() {
}

std::string Contact::getFirstName() {
	return (firstName_);
}

std::string Contact::getLastName() {
	return (lastName_);
}

std::string Contact::getNickname() {
	return (nickname_);
}

std::string Contact::getPhoneNumber() {
	return (phoneNumber_);
}

std::string Contact::getDarkestSecret() {
	return (darkestSecret_);
}

std::string Contact::getIndex() {
	return (index_);
}

void	Contact::setFirstName(std::string firstName) {
	firstName_ = firstName;
}

void	Contact::setLastName(std::string lastName) {
	lastName_ = lastName;
}

void	Contact::setNickname(std::string nickname) {
	nickname_ = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	phoneNumber_ = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	darkestSecret_ = darkestSecret;
}

void	Contact::setIndex(std::string index) {
	index_ = index;
}
