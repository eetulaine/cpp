/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:55:26 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 10:36:50 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int	num_zombies = 99;

	std::cout << "Zombie horde alert!\n";
	Zombie* horde = zombieHorde(num_zombies, "Derek");
	delete[] horde;
	return 0;
}