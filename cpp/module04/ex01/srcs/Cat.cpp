/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:06:10 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 15:14:59 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat( void )
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	this->_ownsbrain = true;
}

Cat::Cat( std::string type )
{
	std::cout << "Cat's Type assigment constructor called" << std::endl;
	this->_type = type;
	this->_brain = new Brain();
	this->_ownsbrain = true;
}

Cat::Cat( const Cat& copy )
{
	std::cout << "Cat's copy constructor called" << std::endl;
	this->_type = copy.getType();
	if (copy._brain)
		this->_brain = new Brain(*copy._brain);
	else
		this->_brain = NULL;
	this->_ownsbrain = copy._ownsbrain;
}

Cat& Cat::operator=( const Cat& copy )
{
    if (this != &copy)
		this->_type = copy.getType();
	if (this->_brain && this->_ownsbrain)
	{
		delete this->_brain;
		this->_brain = NULL;
	}
	if (copy._brain)
		this->_brain = new Brain(*copy._brain);
	else
		this->_brain = NULL;
	this->_ownsbrain = copy._ownsbrain;
    return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miau" << std::endl;
}

void	Cat::setBrain( Brain* brain )
{
	if (this->_brain)
		delete this->_brain;
	this->_brain = brain;
	this->_ownsbrain = false;
}

Brain* Cat::getBrain( void )
{
	return ( this->_brain );
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called" << std::endl;
	if (this->_ownsbrain)
		delete this->_brain;
}