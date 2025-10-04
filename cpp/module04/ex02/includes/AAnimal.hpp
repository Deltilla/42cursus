/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/04 19:53:07 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define	ANIMAL_H

# include <iostream>
# include <string>

class AAnimal
{
	public:
	
		AAnimal();
		AAnimal( std::string type );
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();
	
		// Getters:
	
		std::string	getType( void ) const;
	
		//Setters:
	
		void	setType( std::string type );
	
		//Member Functions:
	
		virtual void	makeSound( void ) const  = 0 ; // pure virtual function to make the class abstract.
	
	protected:
	
		std::string _type;

};

#endif