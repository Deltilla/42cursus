/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:27 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 17:09:57 by analba-s         ###   ########.fr       */
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
		Brain( std::string type );
    	Brain(const Brain& other);
		Brain& operator=(const Brain& other);
    	~Brain();

		// Getters:
		
		std::string*	getIdeas( void ) const;

		//Setters:
		
		void	setIdeas( std::string type );
		
		//Member Functions:
	
	private:
	
		std::string _ideas[100];

};

#endif