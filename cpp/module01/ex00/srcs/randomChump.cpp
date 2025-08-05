/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:53:21 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/05 17:30:09 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void	Zombie::randomChump( std::string name )
{
	typedef	Zombie::t	zombie_t;

	zombie_t	zombie(name);
	zombie.Zombie::Announce();
}