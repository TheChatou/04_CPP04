/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:14:19 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:07:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal		*one = new Animal();
	const Animal		*two = new Dog();
	const Animal		*three = new Cat();
	const WrongAnimal	*four = new WrongCat();

	std::cout << std::endl;
	std::cout << "one's type is : " << one->getType() << std::endl;
	std::cout << "two's type is : " << two->getType() << std::endl;
	std::cout << "three's type is : " << three->getType() << std::endl;
	std::cout << "four's type is : " << four->getType() << std::endl;
	
	std::cout << std::endl;
	one->makeSound();
	two->makeSound();
	three->makeSound();
	four->makeSound();
	std::cout << std::endl;
	
	delete one;
	delete two;
	delete three;
	delete four;

	return 0;
}