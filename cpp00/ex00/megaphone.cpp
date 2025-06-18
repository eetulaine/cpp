/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:54:38 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/18 11:00:03 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++) {
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
		std::cout << "\n";
	}
	return 0;
}
