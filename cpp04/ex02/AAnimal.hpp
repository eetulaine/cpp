/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:07:04 by eelaine           #+#    #+#             */
/*   Updated: 2025/07/24 16:57:40 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class AAnimal {

	protected:
		std::string type_;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;

		std::string getType() const;
};