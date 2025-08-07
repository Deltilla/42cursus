/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/07 17:52:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <vector>

int main( void )
{
	Zombie	*horde;
	std::string	hordeName = "Joses";

	horde = Zombie::zombieHorde( 5, hordeName );
	for (int i = 0; i < 5; ++i) {
		horde[i].Announce();
	}
	delete[] horde;
}