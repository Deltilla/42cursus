/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/29 18:04:56 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define	FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed 
{
	public:

    	Fixed();
    	Fixed(const Fixed& copy);
    	Fixed(const int intValue);
    	Fixed(const float floatValue);
    	Fixed& operator=(const Fixed& copy);
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