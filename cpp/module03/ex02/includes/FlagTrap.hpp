/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:08:08 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 16:00:22 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_H
# define FLAGTRAP_H

# include <iostream>
# include <string>
# include <ClapTrap.hpp>

class FlagTrap : public ClapTrap
{
	public:

    	FlagTrap();
		FlagTrap( std::string name );
    	FlagTrap( const FlagTrap& copy );
		FlagTrap& operator=( const FlagTrap& copy );
    	~FlagTrap();
		
    	void highFivesGuys(void);

};

#endif