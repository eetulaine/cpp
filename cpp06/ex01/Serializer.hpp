/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:22:37 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/06 15:35:56 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <cstdint>

struct Data {
	
	int id;
	std::string name;

};

class Serializer {
	
	private:
		
		Serializer() = delete;
		Serializer(const Serializer &copy) = delete;
		Serializer &operator=(const Serializer &other) = delete;
		~Serializer() = delete;
		
	public:
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};