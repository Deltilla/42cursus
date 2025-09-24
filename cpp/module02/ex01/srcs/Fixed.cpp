/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 14:23:56 by analba-s         ###   ########.fr       */
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
	if (floatValue >= 0)
		this->_value = floatValue * (1 << _fractionalBits) + 0.5f; 	// la expresion 1 << _fractionalBits es equivalente a
	else															// pow(2, _fractionalBits) osea 2 elevado a _fractionalBits
		this->_value = floatValue * (1 << _fractionalBits) - 0.5f;	// ya que 1<<8 desplaza 1 8 bits a la izquierda, es decir,
																	// 10000000 en binario = 256 en decimal, usamos 1<<8 porque es mas
																	// eficiente al ser una operacion de bits.
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
