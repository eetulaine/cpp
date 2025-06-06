/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:45:49 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/06 13:39:27 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon {
	
	private:
		std::string	type_;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const	std::string &getType();
		void	setType(std::string type);

};