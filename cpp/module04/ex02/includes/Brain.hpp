/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:27 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/02 12:19:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define	BRAIN_H

# include <iostream>
# include <string>

class Brain
{
	public:

    	Brain();
		Brain( std::string* ideas );
    	Brain(const Brain& other);
		Brain& operator=(const Brain& other);
    	~Brain();

		// Getters:
		
		const std::string*	getIdeas( void );

		//Setters:
		
		void	setIdeas( std::string* ideas );
		
		//Member Functions:
	
	private:
	
		std::string _ideas[100];

};

#endif