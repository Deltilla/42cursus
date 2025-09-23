/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/23 17:47:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define	ZOMBIE_H

# include <iostream>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Zombie {
	
	private:
	
		std::string	_name;
		
	public:
		
	
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
	
	void	setName( std::string name );
	void	Announce( void );
	
};

	Zombie*	zombieHorde( int N, std::string name ); // Declaras la funcion como libre para evitar necesitar un objeto Zombie para llamarla ya que carece de sentido 
													// dada su funcionalidad.

#endif