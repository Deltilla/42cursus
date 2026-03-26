/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:40 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 11:58:16 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN( void )
{
}

RPN::RPN( const RPN& copy)
{
	this->_stack = copy._stack;
}

RPN& RPN::operator=( const RPN& copy )
{
	if (this != &copy)
		this->_stack = copy._stack;
	return (*this);
}

RPN::~RPN()
{
}

std::string RPN::trimWhitespace( const std::string& str ) const
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

bool RPN::isOperator( const std::string& token ) const
{
	return (token.length() == 1 && 
			(token[0] == '+' || token[0] == '-' || 
			 token[0] == '*' || token[0] == '/'));
}

bool RPN::isOperand( const std::string& token ) const
{
	if (token.length() != 1)
		return false;
	return (token[0] >= '0' && token[0] <= '9');
}

int RPN::performOperation( int a, int b, char op ) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return b - a;
		case '*':
			return a * b;
		case '/':
			if (a == 0)
				throw std::runtime_error("Error: division by zero");
			return b / a;
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

void RPN::evaluateExpression( const std::string& expression )
{
	std::string trimmed = trimWhitespace(expression);
	
	if (trimmed.empty())
		throw std::runtime_error("Error");

	std::istringstream ss(trimmed);
	std::string token;

	while (ss >> token)
	{
		if (isOperand(token))
		{
			this->_stack.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (this->_stack.size() < 2)
				throw std::runtime_error("Error");
			int a = this->_stack.top();
			this->_stack.pop();
			int b = this->_stack.top();
			this->_stack.pop();

			int result = performOperation(a, b, token[0]);
			this->_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (this->_stack.size() != 1)
		throw std::runtime_error("Error");
}

void RPN::printStack( void )
{
	if (!this->_stack.empty())
	{
		std::cout << this->_stack.top() << std::endl;
	}
}
