/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:10 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 20:36:10 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

HumanB::HumanB ( std::string name)
{
	this->_name = name;
}

HumanB::~HumanB( void )
{
}

void HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &type )
{
	this->_weapon = &type;
}
