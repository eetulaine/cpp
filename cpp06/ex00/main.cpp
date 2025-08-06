/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:29:29 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/06 14:34:25 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << "Invalid arguments!\n";
		return 1;
	}
	std::string input = av[1];	
	ScalarConverter::convert(input);
	return 0;
}