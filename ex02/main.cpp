/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:14:19 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:05:06 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define ANIMALS_NB		2

int	main()
{
	Animal	*animals[ANIMALS_NB];

	for (int i = 0; i < ANIMALS_NB; i++)
	{
		if (i % 2)
		{
			animals[i] = new Cat();
			if (!animals[i])
			{
				perror("Cat Brain not allocated");
				exit(1);
			}
		}
		else
		{
			animals[i] = new Dog();
			if (!animals[i])
			{
				perror("Cat Brain not allocated");
				exit(1);
			}			
		}
		animals[i]->makeSound();
		std::cout << "animal [" << i << "] is a : " << animals[i]->getType() << std::endl;
	}
	
	std::cout << std::endl;
	
	// Animal *yes = new Animal(*animals[0]);
	// yes->makeSound();
	// std::cout << "the copy animal is a : " << yes->getType() << std::endl;

	// delete yes;

	for (int i = 0; i < ANIMALS_NB; i++)
	{
		delete animals[i];
	}

	// std::cout << std::endl;
	// std::cout << "---- SOME OTHER TESTS ----" << std::endl;

	Cat	cat;

	cat.setCatIdea(0, "Wesh");
	cat.setCatIdea(1, "Deuxieme Idee");
	cat.printCatIdeas(0);
	cat.printCatIdeas(1);
	
	Cat	copy(cat);
	copy.printCatIdeas(0);
	copy.printCatIdeas(1);

	std::cout << std::endl;
	Dog	*dog = new Dog();
	dog->makeSound();
	dog->setDogIdea(102, "big idea");
	dog->setDogIdea(3, "I want a bone !");
	dog->printDogIdeas(3);
	dog->printDogIdeas(0);
	dog->printDogIdeas(102);
	
	std::cout << std::endl;
	delete dog;
		
	return 0;
}