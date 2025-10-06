/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:43:35 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/06 20:39:11 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define	FORM_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	public:

    	Form();
		Form( const std::string& name, const int signGrade, const int executeGrade);
		Form( const char* name, const int signGrade, const int executeGrade);
    	Form(const Form& other);
		Form& operator=(const Form& other);
    	~Form();

		std::string	getName( void ) const;
		int			getSignGrade( void ) const;
		int			getExecuteGrade( void ) const;
		bool		getSigned( void ) const;

		void	beSigned( Bureaucrat& bureaucrat );

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Form's grade is too low" );
			}
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Form's grade is too high" );
			}
	};

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
		

};

#endif