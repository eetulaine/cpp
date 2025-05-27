/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:34:20 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/27 12:11:59 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Contact {

	private:
		std::string	firstName_;
		std::string	lastName_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	darkestSecret_;
		std::string index_;

	public:
		Contact();
		~Contact();

		std::string getFirstName();
		std::string getLastName();
		std::string	getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		std::string getIndex();
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		void setIndex(std::string index);
};