/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/04 21:09:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define	BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat
{
	public:

    	Bureaucrat();
		Bureaucrat( std::string name );
    	Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
    	~Bureaucrat();

		const std::string	getName( void );
		void				setName( std::string name ) const;
		int					getGrade( void );
		void				setGrade( int grade );

		void	improveGrade( void );
		void	wrosenGrade( void );

	private:

		const std::string	_name;
		int					grade;
		

};

#endif