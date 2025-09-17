/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/17 19:33:06 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

ClapTrap::ClapTrap( void )
{
	std::cout << "Claptrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_atackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& copy)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
    if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_atackDamage = copy.getAtackDamage();
	}
    return (*this);
}

ClapTrap::ClapTrap( std::string name )
{
    std::cout << "ClapTrap Name assigment constructor called" << std::endl;
    this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_atackDamage = 0;
}

std::string	ClapTrap::getName( void ) const
{
	std::cout << "ClapTrap getName member function called" << std::endl;
	return( this->_name );
}

void ClapTrap::setName( std::string name )
{
	std::cout << "ClapTrap setName member function called" << std::endl;
	this->_name = name;
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	std::cout << "ClapTrap getHitPoints member function called" << std::endl;
	return( this->_hitPoints );
}

void ClapTrap::setHitPoints( unsigned int amount )
{
	std::cout << "ClapTrap setHitPoints member function called" << std::endl;
	this->_hitPoints = amount;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	std::cout << "ClapTrap getEnergyPoints member function called" << std::endl;
	return( this->_energyPoints );
}

void ClapTrap::setEnergyPoints( unsigned int amount )
{
	std::cout << "ClapTrap setEnergyPoints member function called" << std::endl;
	this->_energyPoints = amount;
}

unsigned int	ClapTrap::getAtackDamage( void ) const
{
	std::cout << "ClapTrap getAtackDamage member function called" << std::endl;
	return( this->_atackDamage );
}

void ClapTrap::setAtackDamage( unsigned int amount )
{
	std::cout << "ClapTrap setAtackDamage member function called" << std::endl;
	this->_atackDamage = amount;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoints == 0)
		std::cout << "ClapTrap has not energy enough to attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks "  << target 
				<< " causing " << this-> _atackDamage << " points of damage!" 
				<< std::endl;
		this->_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name << " receives " << amount 
			<< " points of damage!" << std::endl;
	if (this->_hitPoints - amount < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has died" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount)
{
	if (this->_energyPoints == 0)
		std::cout << "ClapTrap has not energy enough to repair" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << "repair itself " << amount
				<< "points of damage" << std::endl;
		if (this->_hitPoints + amount > 10)
			this->_hitPoints = 10;
		else
			this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}
