/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 12:35:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK
# define MUTANT_STACK

# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <stack>

class MutantStack
{
	public:

    	MutantStack();
		MutantStack( unsigned int N );
    	MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
    	~MutantStack();

	private:

		

};


#endif