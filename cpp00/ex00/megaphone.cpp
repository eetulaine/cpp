/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:54:38 by eelaine           #+#    #+#             */
/*   Updated: 2025/05/08 16:04:11 by eelaine          ###   ########.fr       */
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
	}
	return (0);
}
