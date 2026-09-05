/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:18 by yosherau          #+#    #+#             */
/*   Updated: 2026/04/29 13:55:39 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	private:
		int	randomNumber;
	
	public:
		Data(void);
		~Data(void);
		Data(const Data &other);
		Data	&operator=(const Data &other);
		int		getRandomNumber(void);
};

#endif