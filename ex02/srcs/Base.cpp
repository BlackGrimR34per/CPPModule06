/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:27:39 by yosherau          #+#    #+#             */
/*   Updated: 2026/09/05 23:11:40 by yosherau         ###   ########.fr       */
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
	
	int	outcome = std::rand() % 3;
	if (outcome == 1)
		return (new A());
	else if (outcome == 2)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "It is an A!" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "It is an B!" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "It is an C!" << std::endl;
	else
		std::cout << "WHO THIS???" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "It is an A!!" << std::endl;
	} catch (std::exception &e){
		
	}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "It is an B!!" << std::endl;
	} catch (std::exception &e){
		
	}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "It is an C!!" << std::endl;
	} catch (std::exception &e){
		
	}
}
