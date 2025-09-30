/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/30 11:28:27 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define	CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
	public:

    	ClapTrap();
		ClapTrap( std::string name );
    	ClapTrap( const ClapTrap& other );
		ClapTrap& operator=(const ClapTrap& other);
    	~ClapTrap();

		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAtackDamage( void ) const;

		void	setName( std::string name );
		void	setHitPoints( unsigned int amount );
		void	setEnergyPoints( unsigned int amount );
		void	setAtackDamage( unsigned int amount );
		
		
    	void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	private:
	
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_atackDamage;

};

#endif