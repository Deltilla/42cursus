/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/17 16:59:19 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

// El uso de map esta prohibido hasta el modulo 08, en consecuencia hay que cambiar este proyecto

Harl::Harl( void )
{
	complaints["debug"] = &Harl::debug;
	complaints["info"] = &Harl::info;
	complaints["warning"] = &Harl::warning;
	complaints["error"] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug( void ) 
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	std::map<std::string, complainLevel>::iterator it = complaints.find(level);
	if (it != complaints.end())
		(this->*(it->second))();
	else
		std::cout << "Harl is complaining about something irrelevant" << std::endl;
}