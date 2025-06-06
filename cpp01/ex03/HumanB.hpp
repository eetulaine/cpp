/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:48:12 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/06 14:50:52 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB {
	
	private:
		std::string name_;
		Weapon	*weapon_;

	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
};