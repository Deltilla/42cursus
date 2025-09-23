/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:51:15 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/23 17:39:10 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde;

	if (N < 0) {
		std::cout << "invalid number of zombies" << std::endl;
		return (NULL);
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return (horde);
}