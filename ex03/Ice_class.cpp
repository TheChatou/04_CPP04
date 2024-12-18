/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice_class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:22 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 15:00:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice_class.hpp"
#include "AMateria_class.hpp"

//	COPLIEN ////////////////////////////////////////////////////////////////////
Ice::Ice(): AMateria()
{
	_type = "ice";
	std::cout << CYAN << "\t! Ice \t ^ Default Constructor" << RESET << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
	*this = copy;
	std::cout << CYAN << " \t! Ice \t > Copy Constructor" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << CYAN << " \t! Ice \t x Destructor" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	/////////////////////////////////////////////////////////
AMateria*	Ice::clone() const
{
	Ice	*copy = new Ice();
	return copy;
}

void	Ice::use(ICharacter &target)
{
	std::cout << CYAN << "\t*** shoots a ice bolt at " << target.getName() << " ***" << RESET << std::endl; 
}
