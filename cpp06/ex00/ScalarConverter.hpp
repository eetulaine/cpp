/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:23:46 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/06 15:01:05 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

enum Type {

	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID,

};

class ScalarConverter {
	
	private: 

		ScalarConverter() = delete;
		ScalarConverter(const std::string &copy) = delete;
		ScalarConverter &operator=(const std::string &other) = delete;
		~ScalarConverter() = delete;

	public:
	
		static void convert(const std::string &input);

};