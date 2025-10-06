/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 15:30:14 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <Brain.hpp>

int main()
{
	// Test with various way to create an animal
	Cat		cat;
	Dog		dog;
	Brain	brain;
	std::string ideas[100];
	
	for (int i = 0; i < 100; i++)
		ideas[i] = "i got an idea";
	
	brain.setIdeas(ideas);
	cat.getBrain()->setIdeas(ideas);
	dog.setBrain(&brain);
	
	std::cout << cat.getType() << ": ";
	cat.makeSound();
	
	for (int i = 0; i < 100; i++)
		std::cout << cat.getBrain()->getIdeas()[i] << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << dog.getBrain()->getIdeas()[i] << std::endl;

	// Test with 100 animals;
	int		N = 100;
	Animal*	animals[N];

	for (int i = 0; i < N / 2; ++i)
        animals[i] = new Dog();
	for (int i = N / 2; i < N; ++i)
        animals[i] = new Cat();
	for (int i = 0; i < 100; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < N; i++)
		delete animals[i];

	Dog basic;
	{
		Dog tmp = basic;
	}
	
	return 0;
}