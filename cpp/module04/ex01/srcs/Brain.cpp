/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:30 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/01 11:53:28 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>

Brain::Brain( void )
{
	std::cout << "Brain's default constructor called" << std::endl;
	this->_ideas = new std::string[100];
}

Brain::Brain( std::string* ideas )
{
	std::cout << "Brain's Name assigment constructor called" << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
}

Brain::Brain( const Brain& copy )
{
	std::cout << "Brain's copy constructor called" << std::endl;
	this->_ideas = copy.getIdeas();
}

Brain& Brain::operator=( const Brain& copy )
{
    std::cout << "Brain's copy assigment opperator called" << std::endl;
    if (this->_ideas)
		delete this->_ideas;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy.getIdeas()[i];
    return ( *this );
}

std::string*	Brain::getIdeas( void ) const
{
	std::cout << "Brain's getIdeas member function called" << std::endl;
	return( this->_ideas );
}

void	Brain::setIdeas( std::string* ideas )
{
	std::cout << "Brain's setIdeas member function called" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (ideas[i].empty())	
			this->_ideas[i] = ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << std::endl;
}