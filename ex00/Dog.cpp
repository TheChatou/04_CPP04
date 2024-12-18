/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:21:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 15:16:15 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Dog::Dog(): Animal()
{
	_type = "Dog";
	_type = CYAN + _type + RESET;
	std::cout << CYAN << "DOG \t^ Default Constructor" << RESET << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << CYAN << "DOG \t> Copy Constructor" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << CYAN << "DOG \tx Destructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << CYAN << "\t= Assigment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;	
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	Dog::makeSound() const
{
	std::cout << CYAN << "\t-- WooOOooF --" << RESET << std::endl;
}
