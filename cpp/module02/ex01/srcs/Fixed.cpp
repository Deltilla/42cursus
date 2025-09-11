/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/10 19:02:39 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

const int	Fixed::_fractionalBits;

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int intValue )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed& Fixed::operator=( const Fixed& copy )
{
	std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy)
		_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return( this->_value );
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
