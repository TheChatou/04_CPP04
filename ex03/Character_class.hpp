/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:32:38 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 10:46:05 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter_interface.hpp"
#include "AMateria_class.hpp"

class Character: public ICharacter
{
	private:
		std::string	_name;	
		AMateria*	_materias[4];

	public:
		AMateria*	trash[100];
		
		Character();
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);

		Character(std::string name);
	
		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);	
};