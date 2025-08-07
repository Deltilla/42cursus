/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/07 17:37:51 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <vector>

int main( void )
{
	Zombie*	zombie;
	Zombie	peter("Peter");
	
	zombie = Zombie::newZombie("Pascual");
	zombie->Announce();
	delete zombie;
	peter.Announce();
	Zombie::randomChump("Jose");
}