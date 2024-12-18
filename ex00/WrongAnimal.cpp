/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:27:32 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 10:02:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA_ITALIC  "\033[3;35m"    /* Magenta Italic */

//	COPLIEN ////////////////////////////////////////////////////////////////////
WrongAnimal::WrongAnimal(): _type("NoType")
{
	_type = MAGENTA_ITALIC + _type + RESET;
	std::cout << std::endl << MAGENTA_ITALIC <<  "WRONG ANIMAL \t^ Default Constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): _type(copy._type)
{
	*this = copy;
	std::cout << MAGENTA_ITALIC << "WRONG ANIMAL \t> Copy Constructor" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << MAGENTA_ITALIC << "WRONG ANIMAL \tx Destructor" << RESET << std::endl << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << MAGENTA_ITALIC << "\t\t= Assigment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	WrongAnimal::makeSound() const
{
	std::cout << MAGENTA_ITALIC << "\t-- ..ooOOoo.. --" << RESET << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}