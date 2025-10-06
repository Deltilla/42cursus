/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:30 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 14:49:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <Animal.hpp>
# include <Brain.hpp>

class Dog : public Animal
{
	public:

    	Dog();
		Dog( std::string type );
    	Dog(const Dog& other);
		Dog& operator=(const Dog& other);
    	~Dog();

		Brain*	getBrain( void );
		void	setBrain( Brain *brain );
		void	makeSound( void ) const;
		
	private:

		Brain* _brain;
		bool	_ownsbrain;
};

#endif