/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:27:39 by yosherau          #+#    #+#             */
/*   Updated: 2026/09/05 20:09:34 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Base.hpp"
# include "../include/A.hpp"
# include "../include/B.hpp"
# include "../include/C.hpp"

Base::~Base(void)
{

};

Base	*generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	// int	outcome = std::rand() % 3;
	// if (outcome == 1)
	return (new B());
	// else if (outcome == 2)
	// 	return (new B());
	// else
	// 	return (new C());
}

void	identify(Base *p)
{
	// Base *temp = new A();
	// std::cout << temp << std::endl;
	// std::cout << dynamic_cast<A *>(p) << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "It is an A!" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "It is an B!" << std::endl;
	
}