/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/15 17:47:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define	BUREAUCRAT_H

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
	public:

    	Bureaucrat();
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const char* name, int grade);
    	Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
    	~Bureaucrat();

		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				setGrade( int grade );

		void	improveGrade( void );
		void	worsenGrade( void );
		void	signForm( Form& form );

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Bureaucrat's grade is too low" );
			}
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ( "Bureaucrat's grade is too high" );
			}
	};

	private:

		const std::string	_name;
		int					_grade;
		

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif