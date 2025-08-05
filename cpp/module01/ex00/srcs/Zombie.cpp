/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/05 17:31:08 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": got destoyed" << std::endl;
}

void	Zombie::Announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}