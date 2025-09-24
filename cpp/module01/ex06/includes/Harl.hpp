/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 11:59:09 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define	HARL_H

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Harl Class                                   //
// ************************************************************************** //

class Harl {
	
public:
	
	typedef void (Harl::*complainFunction)(void);

	Harl( void );
	~Harl( void );
	
	void complain( std::string level );

private:

	complainFunction	levels[4];

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	
};

#endif