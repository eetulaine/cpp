/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:20:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/27 15:35:43 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

# define MAX_CONTACTS 8
# define YELLOW	"\033[93m"
# define END	"\e[0m"

class	PhoneBook {

	private:
		Contact	contact[MAX_CONTACTS];
		int		contactId_ = 0;
		bool	maxContactsReached_ = false;

	public:
		PhoneBook();
		~PhoneBook();
	
		void	addContact();
		void	searchContact();
		void	askIndex();
};