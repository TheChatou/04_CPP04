/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:35:03 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 15:11:22 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */
#define ITALIC	"\033[3m"		/* Italic */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Cat::Cat(): Animal()
{
	_type = "Cat";
	_type = GREEN + _type + RESET;
	_brain = new Brain();
	if (!this->_brain)
	{
		perror("Cat Brain not allocated");
		exit(1);
	}
	std::cout << GREEN << "CAT \t ^ Default Constructor" << RESET << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	this->_brain = new Brain();
	if (!this->_brain)
	{
		perror("Cat Brain not allocated");
		exit(1);
	}
	*this = copy;
	std::cout << GREEN << "CAT \t > Copy Constructor" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << GREEN << "CAT \t x Destructor" << RESET << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GREEN << "\t = Assignment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	Cat::makeSound() const
{
	std::cout << GREEN << "\t -- MeeEEeew --" << RESET << std::endl;
}

void	Cat::setCatIdea(int i, std::string idea)
{
	if (i > 100)
	{
		std::cout << ITALIC << "\tA Cat has no more than 100 ideas" << std::endl;
	}
	else
	{
		this->_brain->setIdea(i, idea);
	}
}

void	Cat::printCatIdeas(int i)
{
	if (i > 100)
	{
		std::cout << ITALIC << "\tA Cat has no more than 100 ideas" << std::endl;
	}
	else
	{	
		std::cout << GREEN << "\tIdea " << i << " " << RESET << this->_brain->getIdea(i) << std::endl;
	}
}