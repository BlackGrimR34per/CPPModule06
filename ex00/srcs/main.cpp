/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:43:21 by yosherau          #+#    #+#             */
/*   Updated: 2026/09/05 15:34:35 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ScalarConverter.hpp"
# include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (EXIT_FAILURE);
	std::string input = argv[1];
	ScalarConverter::convert(input);
}