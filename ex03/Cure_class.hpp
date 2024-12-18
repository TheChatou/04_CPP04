/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure_class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:27:18 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:42 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria_class.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &copy);

		AMateria*	clone() const;
		void		use(ICharacter& target);	
};