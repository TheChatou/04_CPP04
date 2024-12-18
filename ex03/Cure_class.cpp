/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure_class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:52:59 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 15:01:09 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure_class.hpp"

//	COPLIEN ////////////////////////////////////////////////////////////////////
Cure::Cure(): AMateria()
{
	_type = "cure";
	std::cout << GREEN << "\t! Cure \t ^ Default Constructor" << RESET << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
	*this = copy;
	std::cout << GREEN << "\t! Cure \t > Copy Constructor" << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << GREEN << "\t! Cure \t x Destructor" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////
AMateria*	Cure::clone() const
{
	Cure	*copy = new Cure();
	return copy;
}

void	Cure::use(ICharacter &target)
{
	std::cout << GREEN << "\t*** heals " << target.getName() << "’s wounds ***" RESET << std::endl; 
}
