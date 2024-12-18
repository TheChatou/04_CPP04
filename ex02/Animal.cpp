/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:27:32 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:49 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Animal::Animal(): _type("NoType")
{
	this->_type = MAGENTA + _type + RESET;
	std::cout << std::endl << MAGENTA << "ANIMAL \t ^ Default Constructor" << RESET << std::endl;
}

Animal::Animal(const Animal &copy): _type(copy._type)
{
	*this = copy;
	std::cout << std::endl << MAGENTA << "ANIMAL \t > Copy Constructor" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << MAGENTA << "ANIMAL \t x Destructor" << RESET << std::endl << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << MAGENTA << "\t = Assigment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	Animal::makeSound() const
{
	std::cout << MAGENTA << "\t -- ..ooOOoo.. --" << RESET << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}