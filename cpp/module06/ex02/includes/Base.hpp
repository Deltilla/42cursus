/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:36:31 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 20:45:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <iostream>

class Base {
	
    public:
	
        virtual ~Base();

};

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

#endif