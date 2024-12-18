/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:35:03 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 15:15:54 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Cat::Cat(): Animal()
{
	_type = "Cat";
	_type = GREEN + _type + RESET;
	std::cout << GREEN << "CAT \t^ Default Constructor" << RESET << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << GREEN << "CAT \t> Copy Constructor" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << GREEN << "CAT \tx Destructor" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GREEN << "\t= Assignment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	Cat::makeSound() const
{
	std::cout << GREEN << "\t-- MeeEEeew --" << RESET << std::endl;
}
