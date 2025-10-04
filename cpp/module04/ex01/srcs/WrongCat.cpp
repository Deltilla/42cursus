/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autogen <autogen@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:00:00 by autogen           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include <WrongCat.hpp>

WrongCat::WrongCat( void )
{
    std::cout << "WrongCat's default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& copy )
{
    std::cout << "WrongCat's copy constructor called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=( const WrongCat& copy )
{
    std::cout << "WrongCat's copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return ( *this );
}

void WrongCat::makeSound( void ) const
{
    std::cout << "Im not a wrong cat..." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat's destructor called" << std::endl;
}
