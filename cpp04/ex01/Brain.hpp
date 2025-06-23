/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:23:10 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/23 15:26:54 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain {

	public:

		std::string ideas_[100];

		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &other);

};