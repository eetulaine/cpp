/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:12:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 17:23:05 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "=== ORTHODOX CANONICAL FORM TESTS ===\n\n";
		
		Animal a;
		Animal b("Random Animal");
		Animal c(b);
		Animal d;
		d = b;
		
		std::cout << "\n\n";
	}
	{
		Cat cat;

		cat.setIdea(0, "I like mouses");
		cat.setIdea(77, "I wanna take a nap");
		cat.setIdea(110, "My human is pathetic");
		std::cout << "Cat: " << cat.getIdea(0) << "\n";
		std::cout << "Cat: " << cat.getIdea(77) << "\n";
		std::cout << cat.getIdea(110) << "\n";

		Dog dog;

		dog.setIdea(0, "I'm hungry!");
		dog.setIdea(77, "Wanna go for a walk?");
		dog.setIdea(110, "I like to eat shoes");
		std::cout << "Dog: " << dog.getIdea(0) << "\n";
		std::cout << "Dog: " << dog.getIdea(77) << "\n";
		std::cout << dog.getIdea(110) << "\n";

		const Animal* arr[10];
		for (int i = 0; i < 10; i++) {
			if (i % 2)
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
			std::cout << "\n";
		}
		for (int i = 0; i < 10; i++) {
			delete arr[i];
			std::cout << "\n";
		}
	
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	return 0;
}
