/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:08:08 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/01 18:56:05 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>
# include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
	public:

    	FragTrap();
		FragTrap( std::string name );
    	FragTrap( const FragTrap& copy );
		FragTrap& operator=( const FragTrap& copy );
    	~FragTrap();
		
    	void	highFivesGuys(void);
		void	attack( const std::string& target );

};

#endif