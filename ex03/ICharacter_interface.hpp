/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter_interface.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:12:52 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/17 16:05:48 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */
#define ORANGE  "\033[38;5;208m" /* Orange */
#define PINK    "\033[38;5;213m" /* Pink */
#define RED     "\033[31m"      /* Red */

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual	void equip(AMateria* m) = 0;
		virtual	void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
