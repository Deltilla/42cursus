/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/04 19:52:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AAnimal.hpp>

AAnimal::AAnimal( void )
{
	//std::cout << "AAnimal's default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type )
{
	//std::cout << "AAnimal's Name assigment constructor called" << std::endl;
	this->_type = type;
}

AAnimal::AAnimal( const AAnimal& copy)
{
	//std::cout << "AAnimal's copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=( const AAnimal& copy )
{
    if (this != &copy)
		this->_type = copy.getType();
    return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return( this->_type );
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "Im not an Aanimal bit**!!" << std::endl;
}

AAnimal::~AAnimal()
{
	//std::cout << "Animal's destructor called" << std::endl;
}
