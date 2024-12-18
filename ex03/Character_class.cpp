/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:38:18 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 17:02:59 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character_class.hpp"
#include "AMateria_class.hpp"

//	COPLIEN ////////////////////////////////////////////////////////////////////
Character::Character()
{
	_name = "NoName";
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		trash[i] = NULL;
	}
	std::cout << std::endl << YELLOW << "@ Character \t ^ Default Constructor" << RESET << std::endl;
}

Character::Character(const Character &copy): ICharacter(copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materias[i])
			_materias[i] = copy._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (copy.trash[i])
			trash[i] = copy.trash[i]->clone();
		else
			trash[i] = NULL;
	}
	_name = copy._name;
	std::cout << std::endl << YELLOW << "@ Character \t > Copy Constructor" << RESET << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 100; i++)
	{
		if (trash[i] == NULL)
		{
			continue;
		}
		delete trash[i];
		trash[i] = NULL;
	}
	std::cout << std::endl << YELLOW << "@ Character \t{" << this->getName() << "}\t x Personnal Trash empty" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			continue;
		}
		delete _materias[i];
		_materias[i] = NULL;
	}
	std::cout << std::endl << YELLOW << "@ Character \t{" << this->getName() << "}\t x Destructor" << RESET << std::endl;
}

//	Je libere d'abord la memoire existante, puis je copie les nouvelles valeurs
// et le tableau "trash" qui contient les materia liberes
Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
    {
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
			{
				delete _materias[i];
				_materias[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (copy._materias[i])
				_materias[i] = copy._materias[i]->clone();
			else
				_materias[i] = NULL;
		}

		for (int i = 0; i < 100; i++)
		{
			if (trash[i])
			{
				delete trash[i];
				trash[i] = NULL;
			}
			if (copy.trash[i])
				trash[i] = copy.trash[i]->clone();
			else
				trash[i] = NULL;
		}
	}
	std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t = Assigment Operator" << RESET << std::endl;
	return *this;
}

//	CONSTRUCTOR	////////////////////////////////////////////////////////////////
Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		trash[i] = NULL;
	}
	std::cout << std::endl << YELLOW << "@ Character \t _ Name Constructor : " << _name << RESET << std::endl;
}

//	MEMBER FUNCTIONS	////////////////////////////////////////////////////////
std::string const &	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t x Tried to Equip [-UNKNOWED-] materia" << RESET << std::endl << std::endl;
		return;
	}
		
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
			std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t >> Equip" << " [" << m->getType() << "] in slot " << i << RESET << std::endl << std::endl;
            return;
        }
    }
	for (int i = 0; i < 100; i++)
	{
		if (trash[i] == NULL)
		{
			std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t x Tried to Equip [" << m->getType() << "] in the unvailable slot " << i << " , so I put it in the trash" << RESET << std::endl << std::endl;
			trash[i] = m;
			return;
		}
	}
	return;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _materias[idx] == NULL)
	{
		std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t x Tried to Unequip [-UNKNOWED-] materia from slot " << idx << RESET << std::endl << std::endl;
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		if (trash[i] == NULL)
		{
			std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t << Unequip" << " [" << _materias[idx]->getType() << "] from slot " << idx << RESET << std::endl << std::endl;
			trash[i] = _materias[idx];
			_materias[idx] = NULL;
			return;
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || _materias[idx] == NULL)
	{
		std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t x Tried to Use [-UNKNOWED-] materia" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << "@ Character \t{" << this->getName() << "}\t > Use" << " [" << _materias[idx]->getType() << "]" << RESET << std::endl;
	_materias[idx]->use(target);
}
