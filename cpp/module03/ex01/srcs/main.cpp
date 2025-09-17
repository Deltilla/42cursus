/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/17 19:51:37 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

int main( void )
{
	std::string name = "Rodolfo";
	
	ScavTrap Rodolfo;
	ScavTrap Roberto(name);
	Rodolfo.setName(name);
	Rodolfo.attack("Roberto");
	Roberto.takeDamage(Rodolfo.getAtackDamage());
	Roberto.beRepaired(5);
	Roberto.guardGate();
	std::cout << "Roberto has " << Roberto.getEnergyPoints() << " energy points, " 
			<< Roberto.getHitPoints() << " hit points and " << Roberto.getAtackDamage()
			<< " atack damage" << std::endl;
	std::cout << "Rodolfo has " << Rodolfo.getEnergyPoints() << " energy points, " 
			<< Rodolfo.getHitPoints() << " hit points and " << Rodolfo.getAtackDamage()
			<< " atack damage" << std::endl;
}