/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:01:53 by yosherau          #+#    #+#             */
/*   Updated: 2026/04/29 13:56:28 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data.hpp"

Data::Data(void): randomNumber(10)
{
	std::cout << "Data's default constructor was called" << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data's destructor was called" << std::endl;
}

Data::Data(const Data &other): randomNumber(other.randomNumber)
{
	std::cout << "Data's copy constructor was called" << std::endl;
}

Data	&Data::operator=(const Data &other)
{
	if (this != &other)
		this->randomNumber = other.randomNumber;
	std::cout << "Data's copy assignment operator was called" << std::endl;
	return (*this);
}

int	Data::getRandomNumber(void)
{
	return (this->randomNumber);
}