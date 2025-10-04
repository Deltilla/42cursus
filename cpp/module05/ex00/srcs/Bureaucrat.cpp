/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/04 21:09:55 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_atackDamage = 0;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
    if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_atackDamage = copy.getAtackDamage();
	}
    return ( *this );
}

Bureaucrat::Bureaucrat( std::string name )
{
    std::cout << "Name assigment constructor called" << std::endl;
    this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_atackDamage = 0;
}

Bureaucrat::

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}
