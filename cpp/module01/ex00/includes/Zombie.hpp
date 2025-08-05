/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/05 17:33:17 by analba-s         ###   ########.fr       */
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

	std::string	name;

	Zombie( void );

public:

	typedef	Zombie	t;

	static Zombie*	newZombie( std::string name );
	static void		randomChump( std::string name );

	Zombie( std::string name );
	~Zombie( void );

	void	Announce( void );
	
};

#endif