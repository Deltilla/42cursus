/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:43:35 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 16:45:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define	AFORM_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	public:

    	AForm();
		AForm( const std::string& name, const int signGrade, const int executeGrade);
		AForm( const char* name, const int signGrade, const int executeGrade);
    	AForm(const AForm& other);
		AForm& operator=(const AForm& other);
    	virtual ~AForm();

		std::string	getName( void ) const;
		int			getSignGrade( void ) const;
		int			getExecuteGrade( void ) const;
		bool		getSigned( void ) const;

		void			beSigned( Bureaucrat& bureaucrat );
		virtual void	execute( Bureaucrat const & executor ) const = 0;

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Grade is too low" );
			}
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Grade is too high" );
			}
	};

	class FormNotSignedException : public std::exception
	{
	    private:
	        std::string _message;
	
	    public:
	        FormNotSignedException(const std::string& forName)
	            : _message("Form: Error: " + forName + "form not signed") {}
	
	        virtual ~FormNotSignedException() throw() {}
	
	        virtual const char* what() const throw()
	        {
	            return _message.c_str();
	        }
	};

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
		

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif