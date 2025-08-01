/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:50:06 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/01 14:15:44 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie	*newZombie( std::string name )
{
	typedef Zombie::t	zombie_t;
	zombie_t *zombie;
	
	zombie->newZombie(name);
	return (zombie);
}