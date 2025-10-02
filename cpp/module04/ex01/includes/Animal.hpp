/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/02 13:22:34 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define	ANIMAL_H

# include <iostream>
# include <string>

class Animal
{
	public:

    	Animal();
		Animal( std::string type );
    	Animal(const Animal& other);
		Animal& operator=(const Animal& other);
    	virtual ~Animal();

		// Getters:
		
		std::string	getType( void ) const;

		//Setters:
		
		void	setType( std::string type );
		
		//Member Functions:
		
		void	makeSound( void ) const;
	
	protected:
	
		std::string _type;

};

#endif