/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:02 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 21:15:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_H
#define HUMANB_H

# include <Weapon.hpp>

class HumanB {

private:

	std::string	_name;
	Weapon*		_weapon;

public:

	HumanB( void );
	HumanB( std::string name );
	~HumanB( void );

	void	attack();
	void	setWeapon( Weapon &type );
};

#endif