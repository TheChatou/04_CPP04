/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:34:55 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:23:55 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */

//	COPLIEN ////////////////////////////////////////////////////////////////////
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = "** Empty Idea **";
	}
	std::cout << YELLOW << "BRAIN \t ^ Default Constructor" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << YELLOW << "BRAIN \t > Copy Constructor" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << YELLOW << "BRAIN \t x Destructor" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << YELLOW << "BRAIN \t = Assigment Operator" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

void	Brain::setIdea(int i, std::string idea)
{
	std::cout << YELLOW << "BRAIN \t + Set Idea : '" << idea << "' at index : " << i << RESET << std::endl;
	this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i)
{
	return this->_ideas[i];
}