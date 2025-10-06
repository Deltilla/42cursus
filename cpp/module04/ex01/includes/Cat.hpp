/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:53:27 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/05 15:06:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <Animal.hpp>
# include <Brain.hpp>

class Cat : public Animal
{
	public:

    	Cat();
		Cat( std::string type );
    	Cat(const Cat& other);
		Cat& operator=(const Cat& other);
    	~Cat();

		Brain*	getBrain( void );
		void	setBrain( Brain *brain );
		void	makeSound( void ) const;
	
	private:

		Brain*	_brain;
		bool	_ownsbrain;
};

#endif