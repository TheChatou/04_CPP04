/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:35:03 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 10:01:20 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */
#define GREEN_ITALIC    "\033[3;32m"    /* Green Italic */

//	COPLIEN ////////////////////////////////////////////////////////////////////
WrongCat::WrongCat(): WrongAnimal()
{
	_type = "WrongCat";
	_type = GREEN_ITALIC + _type + RESET;
	std::cout << GREEN_ITALIC << "WRONG CAT \t^ Default Constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << GREEN_ITALIC << "WRONG CAT \t> Copy Constructor" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN_ITALIC << "WRONG CAT \tx Destructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << GREEN_ITALIC << "\t\t= Assignment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	WrongCat::makeSound() const
{
	std::cout << GREEN_ITALIC << "\t\t-- MeeEEeew --" << RESET << std::endl;
}
