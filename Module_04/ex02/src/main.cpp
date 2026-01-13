/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:19 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:51:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

#define N_ANIMALS 4

int	main(void)
{
	Animal	*animalArray[N_ANIMALS + 1];
	animalArray[N_ANIMALS] = NULL;
	Cat	*cat = new Cat();
	Cat *cat2;

	cat2 = cat;

	std::cout << "\nTesting array of animals\n\n";

	for (int i = 0; i < N_ANIMALS / 2; i++)
		animalArray[i] = new Cat();
	
	for (int i = N_ANIMALS / 2; i < N_ANIMALS; i++)
		animalArray[i] = new Dog();

	for (int i = 0; i < N_ANIMALS; i++)
		animalArray[i]->makeSound();
	
	for (int i = 0; animalArray[i]; i++)
		delete animalArray[i];

	std::cout << "\nTesting cat's brain\n\n";

	cat->makeSound();
	cat2->makeSound();
	cat->getBrain()->setIdea("Cats must murder children.", 0);
	cat->getBrain()->setIdea("To murder children is ok.", 1);
	std::cout << "Inside the cat's brain: " << cat->getBrain()->getIdea(0) << "\n";
	std::cout << "Inside the cat's brain: " << cat->getBrain()->getIdea(1) << "\n";
	delete	cat;

	return (0);
}