/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:32:22 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:41:37 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource_class.hpp"
#include "AMateria_class.hpp"

//	COPLIEN ////////////////////////////////////////////////////////////////////
MateriaSource::MateriaSource(): IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = NULL;
	}
	std::cout << RED << "# MateriaSource\t ^ Default Constructor" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
    {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
	std::cout << RED << "# MateriaSource \t > Copy Constructor" << RESET << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
	std::cout << RED << "# MateriaSource \t x Destructor" << RESET << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& copy)
{
	std::cout << RED << "\t = Assigment Operator" << RESET << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
                delete _materias[i]; // Supprime les Materias existantes

            if (copy._materias[i])
                _materias[i] = copy._materias[i]->clone(); // Clone les Materias du other
            else
                _materias[i] = NULL;
        }
    }
	return *this;
}

//	MEMBER FUNCTIONS	/////////////////////////////////////////////////////////
void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << RED << "# MateriaSource - Learn Materia : [" << m->getType() << "]" << RESET << std::endl << std::endl;
			return;
		}
	}
	delete m;
	std::cout << RED << "# MateriaSource - Can't learn more Materia" << RESET << std::endl << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
		{
			std::cout << RED << "# MateriaSource - Create Materia : [" << type << "]" << RESET << std::endl;
			return _materias[i]->clone();
		}
	}
	std::cout << RED << "# MateriaSource x Don't know how to Create [" << type << "] materia, learning first !" << RESET << std::endl;
	return 0;
}