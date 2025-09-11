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
# include <cmath>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Fixed 
{
	public:

    	Fixed();
    	Fixed(const Fixed& other);
    	Fixed(const int intValue);
    	Fixed(const float floatValue);
    	Fixed& operator=(const Fixed& other);
    	~Fixed();

    	int		getRawBits(void) const;
    	void	setRawBits(int const raw);
    	float	toFloat(void) const;
    	int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif