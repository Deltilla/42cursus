/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:07:21 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/30 11:26:59 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->setName("Default");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtackDamage(20);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap Name assigment constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtackDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& copy )
{
	std::cout << "ScavTrap Copy assigment opperator called" << std::endl;
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setHitPoints(copy.getHitPoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAtackDamage(copy.getAtackDamage());
	}
	return ( *this );
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}