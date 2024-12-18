/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource_class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:47:49 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/17 17:28:38 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource_interface.hpp"
#include "AMateria_class.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &copy);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

