/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:31:53 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/30 14:10:32 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie* zombie = newZombie("HeapzzzZ");
	zombie->announce();
	randomChump("StackzzzZ");
	delete zombie;
	return (0);
}
