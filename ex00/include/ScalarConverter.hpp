/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:29:55 by yosherau          #+#    #+#             */
/*   Updated: 2026/04/04 22:50:40 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	// Making constructor private doesn't allow for it to be initialised
	private:
		ScalarConverter(void);
		static bool	isChar(std::string &literal);
		static bool	isInt(std::string &literal);
		static bool	isFloat(std::string &literal);
		static bool	isDouble(std::string &literal);
		static void	printAll(double base_value);
		static void	printChar(double base_value);
		static void	printInt(double base_value);
		static void	printFloat(double base_value);
		static void	printDouble(double base_value);

	public:
		static void	convert(std::string &literal);
};

#endif