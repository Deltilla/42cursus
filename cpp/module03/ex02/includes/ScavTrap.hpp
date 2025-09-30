/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:08:08 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/30 11:28:32 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define	SCAVTRAP_H

# include <iostream>
# include <string>
# include <ClapTrap.hpp>

class ScavTrap : public ClapTrap
{
	public:

    	ScavTrap();
		ScavTrap( std::string name );
    	ScavTrap( const ScavTrap& copy );
		ScavTrap& operator=( const ScavTrap& copy );
    	~ScavTrap();
		
    	void	guardGate( void );

};

#endif