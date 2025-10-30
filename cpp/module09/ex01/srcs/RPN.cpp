/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:40 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/30 18:53:48 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN( void )
{
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN( const RPN& copy)
{
	std::cout << "RPN copy constructor called" << std::endl;
	this->_stack = copy._stack;
}

RPN& RPN::operator=( const RPN& copy )
{
    std::cout << "RPN copy assigment opperator called" << std::endl;
	if (this != &copy)
		this->_stack = copy._stack;
    return ( *this );
}

int RPN::performOperation( int a, int b, char op ) const
{
	int result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
	}
	return result;
}

std::string trimExpression( std::string expression )
{
	std::string trimed;
	size_t start = expression.find_first_not_of(" \t\r\n");
 	if (start == std::string::npos)
    	trimed = "";

  	size_t end = expression.find_last_not_of(" \t\r\n");
  	trimed = expression.substr(start, end - start + 1);
	return ( trimed );
}

bool RPN::isOperator( const std::string& token ) const
{
	if (token.find("+"))
}

void RPN::evaluateExpression( const std::string& expression )
{
	std::string temp;
	temp = trimExpression(expression);
	
	std::istringstream ss(temp);
	std::string token;
	int	n;
	while (ss)
	{
		while (ss >> n) {
			this->_stack.push(n);
		}
		ss >> token;
		if (isOperator(token)) {
			int a;
			int b;
			a = this->_stack.top();
			this->_stack.pop();
			b = this->_stack.top();
			this->_stack.pop();
			int result = performOperation(a, b, token.at(0));
			this->_stack.push(result);
		}
	}
	
}

void RPN::printStack( void )
{
	while (!this->_stack.empty())
	{
		std::cout << this->_stack.top() << std::endl;
		this->_stack.pop();
	}
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}
