/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:37 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/30 18:36:31 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class RPN
{
	public:
	
		RPN( void );
		RPN( const RPN &copy );
		RPN &operator=( const RPN &copy );
		~RPN();

		void	evaluateExpression( const std::string &expression );
		void	printStack( void );

	private:

		std::stack<int>	_stack;

		bool	isOperator( const std::string &token ) const;
		bool	isOperand( const std::string &token ) const;
		int		performOperation( int a, int b, char op ) const;

};

#endif
