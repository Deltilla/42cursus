/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/10 18:56:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define	HARL_H

# include <iostream>
# include <string>
# include <map>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Harl {
	
public:
	
	typedef void (Harl::*complainLevel)(void);

	Harl( void );
	~Harl( void );
	
	void complain( std::string level );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );	
	
	std::map<std::string, complainLevel> complaints;
	
};

#endif