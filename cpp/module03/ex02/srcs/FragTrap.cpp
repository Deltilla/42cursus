/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:07:21 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/01 19:00:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->setName("Default");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtackDamage(30);
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap Name assigment constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtackDamage(30);
}

FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=( const FragTrap& copy )
{
	std::cout << "FragTrap Copy assigment opperator called" << std::endl;
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setHitPoints(copy.getHitPoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAtackDamage(copy.getAtackDamage());
	}
	return ( *this );
}

void	FragTrap::attack( const std::string& target )
{
	if (this->getEnergyPoints() == 0)
		std::cout << "FragTrap has not energy enough to attack" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << " attacks "  << target 
				<< " causing " << this-> getAtackDamage() << " points of damage!" 
				<< std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->getName() << " is requesting a high five!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}