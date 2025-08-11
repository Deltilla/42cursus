/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:13 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 18:45:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

Weapon::Weapon( void )
{
}

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::~Weapon()
{	
}

const std::string& Weapon::getType( void )
{
	return (this->_type);
}

void Weapon::setType( std::string type )
{

	std::string* weapon = &this->_type;
	*weapon = type;
}
