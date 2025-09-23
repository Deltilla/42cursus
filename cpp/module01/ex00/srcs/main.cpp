/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/23 17:44:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <vector>

int main( void )
{
	Zombie*	zombie;
	Zombie	peter("Peter");
	
	zombie = newZombie("Pascual");
	zombie->Announce();
	delete zombie;
	peter.Announce();
	randomChump("Jose");
}