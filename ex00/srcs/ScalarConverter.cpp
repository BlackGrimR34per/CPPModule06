/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:35:52 by yosherau          #+#    #+#             */
/*   Updated: 2026/09/05 15:34:46 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

bool	shouldUseScientific(double value)
{
	double	abs_value;

	if (!std::isfinite(value) || value == 0.0)
		return (false);
	abs_value = std::fabs(value);
	return (abs_value >= 1000000.0 || abs_value < 0.0001);
}

// String within a string is not a C++ literal
bool ScalarConverter::isChar(std::string &literal)
{
	if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
		return (true);
	// if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	// 	return (true);
	else
		return (false);
}

// What to do if number is greater than INT_MAX???
bool ScalarConverter::isInt(std::string &literal)
{
	size_t	index = 0;
	
	if (literal.empty())
		return (false);
	if (literal[index] == '+' || literal[index] == '-')
		index++;
	if (index == literal.length())
		return (false);
	for (; index < literal.length(); index++)
	{
		if (!std::isdigit(literal[index]))
			return (false);
	}
	return (true);
}

// NPOS might not be necessary, .f
bool ScalarConverter::isFloat(std::string &literal)
{
	size_t	index = 0;
	size_t	f_pos = 0;
	int		decimal_count = 0;
	
	if (literal == "nanf" || literal == "+nanf" || literal == "-nanf"
		|| literal == "inff" || literal == "+inff" || literal == "-inff")
		return (true);
	f_pos = literal.find('f');
	if (literal[index] == '+' || literal[index] == '-')
		index++;
	for (; index < f_pos; index++)
	{
		if (!std::isdigit(literal[index]) && literal[index] != '.')
			return (false);
		if (literal[index] == '.')
			decimal_count += 1;
	}
	if (f_pos == 0 || f_pos != literal.length() - 1 || decimal_count != 1 || f_pos == std::string::npos)
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(std::string &literal)
{
	size_t	index = 0;
	int		decimal_count = 0;

	if (literal == "nan" || literal == "+nan" || literal == "-nan"
		|| literal == "inf" || literal == "+inf" || literal == "-inf")
		return (true);
	if (literal[index] == '+' || literal[index] == '-')
		index++;
	for (; index < literal.length(); index++)
	{
		if (!std::isdigit(literal[index]) && literal[index] != '.')
			return (false);
		if (literal[index] == '.')
			decimal_count += 1;
	}
	if (decimal_count != 1)
		return (false);
	return (true);
}

void ScalarConverter::convert(std::string &literal)
{
	std::stringstream ss;
	double		base_val = 0.0;
	std::string	stripped_literal;

	if (isChar(literal))
		base_val = static_cast<double>(literal[0]);
	else if (isInt(literal))
	{
		ss << literal;
		ss >> base_val;
	}
	else if (isFloat(literal))
	{
		stripped_literal = literal.substr(0, literal.length() - 1);
		if (stripped_literal == "nan" || stripped_literal == "+nan" || stripped_literal == "-nan")
			base_val = std::numeric_limits<double>::quiet_NaN();
		else if (stripped_literal == "inf" || stripped_literal == "+inf")
			base_val = std::numeric_limits<double>::infinity();
		else if (stripped_literal == "-inf")
			base_val = -std::numeric_limits<double>::infinity();
		else
		{
			ss << stripped_literal;
			ss >> base_val;
		}
	}
	else if (isDouble(literal))
	{
		if (literal == "nan" || literal == "+nan" || literal == "-nan")
			base_val = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "inf" || literal == "+inf")
			base_val = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			base_val = -std::numeric_limits<double>::infinity();
		else
		{
			ss << literal;
			ss >> base_val;
		}
	}
	printAll(base_val);
}

void	ScalarConverter::printChar(double base_val)
{
	char	character;

	if (base_val < CHAR_MIN || base_val > CHAR_MAX || !std::isfinite(base_val))
		std::cout << "char: impossible" << std::endl;
	else if (base_val < 32 || base_val > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		character = static_cast<char>(base_val);
		std::cout << "char: " << character << std::endl;
	}
}

// std::cout << base_val << std::endl; print's oyt in scientific notation?
void	ScalarConverter::printInt(double base_val)
{
	int	integer;

	if (base_val < std::numeric_limits<int>::min() || base_val > std::numeric_limits<int>::max() || !std::isfinite(base_val))
		std::cout << "int: impossible" << std::endl;
	else
	{
		integer = static_cast<int>(base_val);
		std::cout << "int: " << integer << std::endl;
	}
}

void	ScalarConverter::printFloat(double base_val)
{
	float	floating_value;

	floating_value = static_cast<float>(base_val);
	if (floating_value != floating_value)
		std::cout << "float: nanf" << std::endl;
	else if (floating_value == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (floating_value == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (base_val < -std::numeric_limits<float>::max() || base_val > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << std::showpoint;
		if (shouldUseScientific(floating_value))
			std::cout << std::scientific;
		else
			std::cout << std::fixed << std::setprecision(1);
		std::cout << floating_value << "f" << std::endl;
		// std::cout << std::defaultfloat;
	}
}

// Might need to include reset of std::cout after alteration for double and float
void	ScalarConverter::printDouble(double base_val)
{
	double	double_value;

	double_value = static_cast<double>(base_val);
	if (double_value != double_value)
		std::cout << "double: nan" << std::endl;
	else if (double_value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (double_value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (double_value < -std::numeric_limits<double>::max() || double_value > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << "double: " << std::showpoint;
		if (shouldUseScientific(double_value))
			std::cout << std::scientific;
		else
			std::cout << std::fixed << std::setprecision(1);
		std::cout << double_value << std::endl;
		// std::cout << std::defaultfloat;
	}
}


void	ScalarConverter::printAll(double base_val)
{
	printChar(base_val);
	printInt(base_val);
	printFloat(base_val);
	printDouble(base_val);
}