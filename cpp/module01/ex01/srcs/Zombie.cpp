/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/07 17:48:41 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie::Zombie( void )
{
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": got destoyed" << std::endl;
}

void	Zombie::Announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie*	Zombie::newZombie( std::string name )
{
	Zombie *newZombie;

	newZombie = new Zombie(name);	
	return (newZombie);
}

void	Zombie::randomChump( std::string name )
{
	Zombie	zombie(name);
	zombie.Zombie::Announce();
}

void	Zombie::setName( std::string name )
{
	_name = name;
}