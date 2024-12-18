/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria_class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:48 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/17 17:15:07 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ICharacter_interface.hpp"
#include "IMateriaSource_interface.hpp"

//	Some Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define GREEN   "\033[32m"      /* Green */

class AMateria
{
	protected:
		std::string			_type;
		
	public:
		AMateria();
		AMateria(const AMateria& copy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria& copy);

	
		AMateria(std::string const & type);
		
		std::string const &	getType() const;
		
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};