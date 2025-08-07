/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/07 17:47:50 by analba-s         ###   ########.fr       */
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
	
	typedef	Zombie	t;
	
	static Zombie*	newZombie( std::string name );
	static void		randomChump( std::string name );
	static Zombie*	zombieHorde( int N, std::string name );
	
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
	
	void	setName( std::string name );
	void	Announce( void );
	
};

#endif