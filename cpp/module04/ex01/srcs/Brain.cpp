/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:30 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/02 12:19:42 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>

Brain::Brain( void )
{
	std::cout << "Brain's default constructor called" << std::endl;
}

Brain::Brain( std::string* ideas )
{
	std::cout << "Brain's Name assigment constructor called" << std::endl;
	for (int i = 0; i < 100 && ideas[i].size() != 0; i++)
		this->_ideas[i] = ideas[i];
}

Brain::Brain( const Brain& copy )
{
	std::cout << "Brain's copy constructor called" << std::endl;
	for (int i = 0; i < 100 && copy._ideas[i].size() != 0; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=( const Brain& copy )
{
	for (int i = 0; i < 100 && copy._ideas[i].size() != 0; i++)
		this->_ideas[i] = copy._ideas[i];
    return ( *this );
}

const std::string*	Brain::getIdeas( void )
{
	return( this->_ideas );
}

void	Brain::setIdeas( std::string* ideas )
{
	for (int i = 0; i < 100 && ideas[i].size() != 0; i++)
		this->_ideas[i] = ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << std::endl;
}