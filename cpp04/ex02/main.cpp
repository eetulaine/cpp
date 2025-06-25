/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:12:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/25 11:52:20 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//AAnimal aanimal;

	Cat cat;
	cat.setIdea(0, "I like mouses\n");
	cat.setIdea(77, "I wanna take a nap\n");
	cat.setIdea(110, "My human is pathetic\n");
	std::cout << "Idea: " << cat.getIdea(0) << "\n";
	std::cout << "Idea: " << cat.getIdea(77) << "\n";
	std::cout << "Idea: " << cat.getIdea(110) << "\n\n";

	return 0;
}
