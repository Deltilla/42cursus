/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/30 11:37:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

Animal::Animal( void )
{
	std::cout << "Animal's default constructor called" << std::endl;
}

Animal::Animal( std::string type )
{
	std::cout << "Animal's Type assigment constructor called" << std::endl;
	this->_type = type;
}

Animal::Animal( const Animal& copy)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=( const Animal& copy )
{
    std::cout << "Animal's copy assigment opperator called" << std::endl;
    if (this != &copy)
		this->_type = copy.getType();
    return (*this);
}

std::string	Animal::getType( void ) const
{
	std::cout << "Animal's getType member function called" << std::endl;
	return( this->_type );
}

void	Animal::makeSound( void ) const
{
	switch (this->_type[0]) {
		case 'D':
			std::cout << "Guau" << std::endl;
			break ;
		case 'C':
			std::cout << "Miau" << std::endl;
			break ;
		default:
			std::cout << "Im not an animal bit**!!" << std::endl;
	}
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called" << std::endl;
}
