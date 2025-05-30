/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:36:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 13:36:22 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {
	
	private:
		std::string name_;

	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
		
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
