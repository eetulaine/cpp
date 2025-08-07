/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:33:08 by eelaine           #+#    #+#             */
/*   Updated: 2025/08/07 10:23:56 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// reinterpret_cast<uintptr_t>(ptr) takes the memory address of the Data object
// and treats that address as an unsigned integer
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// reinterpret_cast<Data*>(raw) takes the raw integer value and interprets it as
// a memory address that points to a Data object
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}