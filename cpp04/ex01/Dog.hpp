/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:06:40 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/25 10:50:01 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	
	private:
		Brain *brain_;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog() override;

		void makeSound() const override;
		void setIdea(unsigned int n, std::string idea);
		std::string getIdea(unsigned int n);
};