/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autogen <autogen@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:00:00 by autogen           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal( void )
{
    std::cout << "WrongAnimal's default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
    std::cout << "WrongAnimal's copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& copy )
{
    std::cout << "WrongAnimal's copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return ( *this );
}

std::string WrongAnimal::getType( void ) const
{
    return ( this->_type );
}

void WrongAnimal::setType( std::string type )
{
    this->_type = type;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal sound..." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal's destructor called" << std::endl;
}
