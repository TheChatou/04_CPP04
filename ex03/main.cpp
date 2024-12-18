/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:40:58 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:59:36 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria_class.hpp"
#include "MateriaSource_class.hpp"
#include "Ice_class.hpp"
#include "Cure_class.hpp"
#include "Character_class.hpp"

int main()
{
	std::cout << std::endl << "---- CONSTRUCT & LEARN ----" << std::endl;
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	MateriaSource src2 ;
	src2 = *src;
	src2.learnMateria(new Cure());
	
	ICharacter* leo = new Character("leo");
	AMateria* tmp;
	
	
	std::cout << std::endl << "---- CREATE & EQUIP ----" << std::endl;
	tmp = src->createMateria("ice");
	leo->equip(tmp);
	tmp = src->createMateria("cure");
	leo->equip(tmp);
	tmp = src->createMateria("fire");
	leo->equip(tmp);
	tmp = src->createMateria("cure");
	leo->equip(tmp);
	tmp = src->createMateria("ice");
	leo->equip(tmp);
	tmp = src->createMateria("cure");
	leo->equip(tmp);
	leo->unequip(3);
	leo->unequip(1);
	ICharacter* bob = new Character("bob");
	bob->equip(src->createMateria("ice"));
	leo->equip(src->createMateria("ice"));
	leo->unequip(3);
	leo->unequip(-1);

	std::cout << std::endl << "---- USE ----" << std::endl;
	leo->use(0, *bob);
	leo->use(1, *bob);
	bob->use(0, *leo);
	bob->use(1, *leo);
	leo->use(2, *bob);
	leo->use(3, *bob);


	std::cout << std::endl << "---- COPY ----" << std::endl;
	*(Character *) bob =* (Character *)leo;
	bob->use(2, *leo);

	Character modele("modele");
	modele.equip(src->createMateria("ice"));
	
	Character copie(modele);
	copie.use(0, *leo);
	bob->use(2, *leo);


	std::cout << std::endl << "---- DELETE ----" << std::endl;
	delete bob;
	delete leo;
	delete src;
	return 0;
}