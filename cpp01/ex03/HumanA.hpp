/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:40:15 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/06 15:01:39 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {

	private:
		Weapon &weapon_;
		std::string name_;

	public:
		void attack();
		HumanA(std::string name, Weapon &weapon);
};