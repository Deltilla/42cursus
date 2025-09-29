/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/29 18:35:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

const int   Fixed::_fractionalBits;

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
    this->_value = intValue * (1 << _fractionalBits);
}

Fixed::Fixed( const float floatValue )
{
    std::cout << "Float constructor called" << std::endl;
	if (_value >= 0)
		this->_value = floatValue * (1 << _fractionalBits) + 0.5f;
	else
		this->_value = floatValue * (1 << _fractionalBits) - 0.5f;
}

Fixed& Fixed::operator=( const Fixed& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
    if (this != &copy)
        _value = copy.getRawBits();
    return ( *this );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
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
    return ( static_cast<float>(this->_value) / (1 << _fractionalBits) );
}

int Fixed::toInt(void) const
{
    return ( this->_value >> _fractionalBits );
}

bool Fixed::operator>(const Fixed& other) const
{
    return ( this->getRawBits() > other.getRawBits() );
}

bool Fixed::operator<(const Fixed& other) const
{
    return  ( this->getRawBits() < other.getRawBits() );
}

bool Fixed::operator>=(const Fixed& other) const
{
    return ( this->getRawBits() >= other.getRawBits() );
}

bool Fixed::operator<=(const Fixed& other) const
{
    return ( this->getRawBits() <= other.getRawBits() );
}

bool Fixed::operator==(const Fixed& other) const
{
    return ( this->getRawBits() == other.getRawBits() );
}

bool Fixed::operator!=(const Fixed& other) const
{
    return ( this->getRawBits() != other.getRawBits() );
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return ( Fixed(this->toFloat() + other.toFloat()) );
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return ( Fixed(this->toFloat() - other.toFloat()) );
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return ( Fixed(this->toFloat() * other.toFloat()) );
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return ( Fixed(this->toFloat() / other.toFloat()) );
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return ( a );
	else
		return ( b );
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a > b)
		return ( a );
	else
		return ( b );
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
		return ( a );
	else
		return ( b );
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
		return ( a );
	else
		return ( b );
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}