/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:09:42 by yosherau          #+#    #+#             */
/*   Updated: 2026/04/29 13:53:03 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	temp = reinterpret_cast<uintptr_t>(ptr);
	return (temp);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*temp = reinterpret_cast<Data *>(raw);
	return (temp);
}