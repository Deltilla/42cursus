/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:06:57 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/04 19:51:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog( void )
{
	//std::cout << "Dog's default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	this->_ownsbrain = true;
}

Dog::Dog( std::string type )
{
	//std::cout << "Dog's Type assigment constructor called" << std::endl;
	this->_type = type;
	if (!this->_brain) {
		this->_brain = new Brain();
		this->_ownsbrain = true;
	}
}

Dog::Dog( const Dog& copy)
{
	//std::cout << "Cat's copy constructor called" << std::endl;
	this->_type = copy.getType();
	if (!this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*copy._brain);
	this->_ownsbrain = copy._ownsbrain;
}

Dog& Dog::operator=( const Dog& copy )
{
    if (this != &copy)
		this->_type = copy.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*copy._brain);
	this->_ownsbrain = copy._ownsbrain;
    return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout << "Guau" << std::endl;
}

void	Dog::setBrain( Brain* brain )
{
	if (this->_brain)
		delete this->_brain;
	this->_brain = brain;
	this->_ownsbrain = false;
}

Brain* Dog::getBrain( void )
{
	return ( this->_brain );
}

Dog::~Dog()
{
	//std::cout << "Dog's destructor called" << std::endl;
	if (this->_ownsbrain)
		delete this->_brain;
}