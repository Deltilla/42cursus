/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:42:33 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/23 17:52:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

# include <Weapon.hpp>

class HumanA {

private:

	std::string	_name;
	Weapon& 	_weapon;

public:
	
	HumanA( Weapon &type );
	HumanA( std::string name, Weapon &type );
	~HumanA( void );

	void	attack();
};

#endif