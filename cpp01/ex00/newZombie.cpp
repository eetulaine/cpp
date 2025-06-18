/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:24:10 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 10:59:38 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	try {
		return new Zombie(name);
	}
	catch (const std::bad_alloc &e) {
		std::cerr << "Memory allocation for zombie failed: " << e.what() << std::endl;
		return nullptr;
	}
}