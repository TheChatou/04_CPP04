/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria_class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:35:48 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 14:09:51 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria_class.hpp"

//	COPLIEN ////////////////////////////////////////////////////////////////////
AMateria::AMateria(): _type("NoType")
{
	std::cout << MAGENTA << "! AMateria \t ^ Default Constructor" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
	std::cout << MAGENTA << "! AMateria \t > Copy Constructor" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << MAGENTA << "! AMateria \t x Destructor" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria& copy)
{
	std::cout << MAGENTA << "\t = Assigment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << std::endl << MAGENTA << "! AMateria \t _ Name Constructor" << RESET << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << MAGENTA << " \t *** heals no one's wounds ***" RESET << std::endl; 
}

