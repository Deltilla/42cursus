/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:42:33 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 21:10:01 by analba-s         ###   ########.fr       */
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
	
	HumanA( std::string name, Weapon &type );
	~HumanA( void );

	void	attack();
};

#endif