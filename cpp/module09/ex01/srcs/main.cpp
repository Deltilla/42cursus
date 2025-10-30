/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/30 18:38:38 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int arc, char** arv)
{
	if (arc == 2)
	{
		RPN rpn;
		rpn.evaluateExpression(arv[1]);
		rpn.printStack();
	}
	else
		std::cerr << "Usage --> ./RPN 'n n +' ";
}