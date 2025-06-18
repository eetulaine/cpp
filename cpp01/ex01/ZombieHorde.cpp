/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:46 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 10:35:29 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {	
	if (N < 0)
		N = 0;
	/* if (N > 9999) {
		std::cout << "Arrgh too many zombies!\n";
		exit (1);
	} */
	Zombie* horde = nullptr;
	try {
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc &e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
	for (int i = 0; i < N; i++) {
		horde[i].setName(name, i);
		horde[i].announce();
	}
	return horde;
}
