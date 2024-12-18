/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:14:19 by fcoullou          #+#    #+#             */
/*   Updated: 2024/12/18 16:30:14 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define ANIMALS_NB		4

int	main()
{
	std::cout << "---- TESTS WITH A LOT OF ANIMALS, randomly created as Cat or Dog ----" << std::endl;
	Animal	*animals[ANIMALS_NB];

	for (int i = 0; i < ANIMALS_NB; i++)
	{
		if (i % 2)
		{
			animals[i] = new Cat();
			if (!animals[i])
			{
				perror("Cat not allocated");
				exit(1);
			}
		}
		else
		{
			animals[i] = new Dog();
			if (!animals[i])
			{
				perror("Cat not allocated");
				exit(1);
			}			
		}
		animals[i]->makeSound();
		std::cout << "animal [" << i << "] is a : " << animals[i]->getType() << std::endl;
	}
	std::cout << std::endl << "---- TESTS WITH COPY CONSTRUCTOR FROM ANIMAL ----" << std::endl;
	Animal *yes = new Animal(*animals[0]);
	yes->makeSound();
	delete yes;

	for (int i = 0; i < ANIMALS_NB; i++)
	{
		delete animals[i];
	}
	
	std::cout << std::endl << "---- TESTS WITH COPY CONSTRUCTOR, and ASSIGNATION OPERATOR ----" << std::endl;
	
	Dog	*dog1 = new Dog();
	dog1->setDogIdea(0, "I want a bone !");
	Dog *dog2 = new Dog(*dog1);
	dog2->printDogIdeas(0);
	dog2->setDogIdea(0, "I want a ball !");
	dog2->printDogIdeas(0);
	dog2->printDogIdeas(1);

	Dog dog3;
	dog3.setDogIdea(0, "I want a basket !");
	Dog dog4;
	dog4.setDogIdea(0, "I want to sleep !");
	dog3 = dog4;
	dog3.printDogIdeas(0);
	
	dog3 = *dog2;
	dog3.printDogIdeas(0);
	
	delete dog1;
	delete dog2;

	std::cout << std::endl << "---- SOME OTHER TESTS ----" << std::endl;

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