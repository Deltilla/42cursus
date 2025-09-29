/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/29 18:03:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define	FIXED_H

# include <iostream>
# include <string>

class Fixed
{
	
public:

	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed& operator=( const Fixed& copy );
	~Fixed( void );
	

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:

	int					_value;
	static const int	_fractionalBits = 8;
	
};

#endif