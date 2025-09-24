/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:30 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 17:09:01 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>

Brain::Brain( void )
{
	std::cout << "Brain's default constructor called" << std::endl;
}

Brain::Brain( const Brain& copy)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=( const Brain& copy )
{
    std::cout << "Brain's copy assigment opperator called" << std::endl;
    if (this != &copy)
		this->_ideas = copy.getIdeas();
    return (*this);
}

Brain::Brain( std::string* ideas )
{
    std::cout << "Brain's Name assigment constructor called" << std::endl;
    this->_ideas = ideas;
}

std::string*	Brain::getIdeas( void ) const
{
	std::cout << "Brain's getType member function called" << std::endl;
	return( this->_ideas );
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << std::endl;
}