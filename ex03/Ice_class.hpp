/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:44:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/17 15:37:13 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria_class.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice &operator=(const Ice &copy);

		AMateria*	clone() const;
		void		use(ICharacter &target);
};