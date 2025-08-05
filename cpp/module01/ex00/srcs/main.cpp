/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/05 17:41:13 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <vector>

int main( void )
{
	Zombie::t	*zombie;
	Zombie		peter("Peter");
	
	zombie = Zombie::newZombie("Pascual");
	zombie->Announce();
	Zombie::randomChump("Jose");
	peter.Announce();
	delete zombie;
}