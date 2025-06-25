/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:27:38 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/23 15:36:20 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < 100; i++) {
		ideas_[i] = copy.ideas_[i];
	}
}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called\n";
}
