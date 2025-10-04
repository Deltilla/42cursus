/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/17 18:19:37 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int main( void )
{
	std::string		name;
	unsigned int	Damage;
	
	name = "Roberto";
	Damage = 10;
	ClapTrap Rodolfo("Rodolfo");
	ClapTrap Roberto;
	Roberto.setName(name);
	Rodolfo.setAtackDamage(Damage);
	Rodolfo.attack(Roberto.getName());
	Roberto.takeDamage(Damage);
	std::cout << "Roberto has " << Roberto.getEnergyPoints() << " energy points, " 
			<< Roberto.getHitPoints() << " hit points and " << Roberto.getAtackDamage()
			<< " atack damage" << std::endl;
	std::cout << "Rodolfo has " << Rodolfo.getEnergyPoints() << " energy points, " 
			<< Rodolfo.getHitPoints() << " hit points and " << Rodolfo.getAtackDamage()
			<< " atack damage" << std::endl;
}