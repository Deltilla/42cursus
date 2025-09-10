/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/10 19:21:39 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define	FIXED_H

# include <iostream>
# include <string>
# include <map>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Fixed
{
	
public:
	
	typedef void (Harl::*complainLevel)(void);

	Fixed( void );
	~Fixed( void );
	
	void complain( std::string level );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );	
	
	std::map<std::string, complainLevel> complaints;
	
};

#endif