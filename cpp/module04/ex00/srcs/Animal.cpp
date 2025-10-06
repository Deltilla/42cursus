/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 14:59:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

Animal::Animal( void )
{
	std::cout << "Animal's default constructor called" << std::endl;
}

Animal::Animal( std::string type )
{
	std::cout << "Animal's Type assignment constructor called" << std::endl;
	this->_type = type;
}

Animal::Animal( const Animal& copy)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=( const Animal& copy )
{
		std::cout << "Animal's copy assignment operator called" << std::endl;
    if (this != &copy)
		this->_type = copy.getType();
    return (*this);
}

std::string	Animal::getType( void ) const
{
	return( this->_type );
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makes no specific sound." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called" << std::endl;
}
