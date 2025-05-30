/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:51 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 14:22:01 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {

	private:
		std::string name_;
		
	public:
		void	announce();
		void	setName(std::string name, int i);
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie* zombieHorde(int N, std::string name);