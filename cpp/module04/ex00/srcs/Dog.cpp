/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:06:57 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 15:05:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog( void )
{
	std::cout << "Dog's default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog& copy)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->_type = copy.getType();
}

Dog& Dog::operator=( const Dog& copy )
{
		std::cout << "Dog's copy assignment operator called" << std::endl;
    if (this != &copy)
		this->_type = copy.getType();
    return (*this);
}

Dog::Dog( std::string type )
{
	std::cout << "Dog's Name assignment constructor called" << std::endl;
    this->_type = type;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Guau" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called" << std::endl;
}