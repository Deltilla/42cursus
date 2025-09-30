/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:07:21 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/30 11:29:02 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FlagTrap.hpp>

FlagTrap::FlagTrap( void ) : ClapTrap()
{
	std::cout << "FlagTrap Default constructor called" << std::endl;
	this->setName("Default");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtackDamage(30);
}

FlagTrap::FlagTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FlagTrap Name assigment constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtackDamage(30);
}

FlagTrap::FlagTrap( const FlagTrap& copy ) : ClapTrap(copy)
{
	std::cout << "FlagTrap Copy constructor called" << std::endl;
	*this = copy;
}

FlagTrap& FlagTrap::operator=( const FlagTrap& copy )
{
	std::cout << "FlagTrap Copy assigment opperator called" << std::endl;
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setHitPoints(copy.getHitPoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAtackDamage(copy.getAtackDamage());
	}
	return ( *this );
}

void FlagTrap::highFivesGuys( void )
{
	std::cout << "FlagTrap " << this->getName() << " is requesting a high five!" << std::endl;
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap Destructor called" << std::endl;
}