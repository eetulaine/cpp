/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:46 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 14:32:30 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {	
	if (N < 0)
		N = 0;
	if (N > 9999) {
		std::cout << "Arrgh too many zombies!\n";
		exit (1);
	}
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name, i);
		horde[i].announce();
	}
	return (horde);
}
