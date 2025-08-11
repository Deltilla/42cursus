/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:08 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 21:07:39 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

HumanA::HumanA ( std::string name, Weapon &type) : _weapon(type)
{
	this->_name = name;
	//this->_weapon = type;
}

HumanA::~HumanA( void )
{	
}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " 
			<< this->_weapon.getType() << std::endl;
}