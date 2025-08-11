/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:05 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/11 17:54:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define	WEAPON_H

# include <iostream>

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

class Weapon {

private:

	std::string _type;

public:

	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	const std::string&	getType();
	void				setType( std::string type );
	
};

#endif