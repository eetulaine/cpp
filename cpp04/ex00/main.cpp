/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:12:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 16:28:01 by eelaine          ###   ########.fr       */
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
		std::cout << "\n\n=== POLYMORPHISM TESTS ===\n\n";
		
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const WrongAnimal* h = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << h->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		h->makeSound();
		cat->makeSound();

		std::cout << "\n\n=== DELETING ALLOCATED MEMORY FROM THE HEAP ===\n\n";
		delete i;
		delete j;
		delete meta;
		delete h;
		delete cat;
		std::cout << "\n\n";
	}

	return 0;
}
