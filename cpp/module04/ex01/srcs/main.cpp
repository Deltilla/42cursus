/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/01 12:00:53 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <Brain.hpp>

int main()
{
	Cat cat;
	Dog dog;
	Animal meta;
	Brain brain;
	std::string ideas[100];
	
	for (int i = 0; i < 100; i++)
		ideas[i] = "i got an idea";
	
	brain.setIdeas(ideas);
	
	std::cout << cat.getType() << ": ";
	cat.makeSound();
	
	return 0;
}