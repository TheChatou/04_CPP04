/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:21:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/05 15:11:15 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */
#define ITALIC	"\033[3m"		/* Italic */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Dog::Dog(): Animal()
{
	_type = "Dog";
	_type = CYAN + _type + RESET;
	_brain = new Brain();
	if (!this->_brain)
	{
		perror("Dog Brain not allocated");
		exit(1);
	}
	std::cout << CYAN << "DOG \t ^ Default Constructor" << RESET << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	this->_brain = new Brain();
	if (!this->_brain)
	{
		perror("Cat Brain not allocated");
		exit(1);
	}
	*this = copy;
	std::cout << CYAN << "DOG \t > Copy Constructor" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << CYAN << "DOG \t x Destructor" << RESET << std::endl;
	delete	this->_brain;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << CYAN << "\t = Assigment Operator" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return *this;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////////
void	Dog::makeSound() const
{
	std::cout << CYAN << "\t -- WooOOooF --" << RESET << std::endl;
}

void	Dog::setDogIdea(int i, std::string idea)
{
	if (i > 100)
	{
		std::cout << ITALIC << "\tA Dog has no more than 100 ideas" << std::endl;
	}
	else
	{
		this->_brain->setIdea(i, idea);
	}
}

void	Dog::printDogIdeas(int i)
{
	if (i > 100)
	{
		std::cout << ITALIC << "\tA Dog has no more than 100 ideas" << std::endl;
	}
	else
	{	
		std::cout << GREEN << "\tIdea " << i << " " << RESET << this->_brain->getIdea(i) << std::endl;
	}
}