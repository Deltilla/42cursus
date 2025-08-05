/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:50:06 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/05 17:32:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	Zombie::newZombie( std::string name )
{
	typedef Zombie::t	zombie_t;
	zombie_t *zombie;

	zombie = new Zombie(name);	
	return (zombie);
}