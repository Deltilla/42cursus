/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:49:32 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 19:56:29 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define	SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include <exception>
# include <Bureaucrat.hpp>
# include <AForm.hpp>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:

    	ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
    	ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    	~ShrubberyCreationForm();

		std::string	getTarget( void ) const;
		void		setTarget( std::string target );

		void execute( Bureaucrat const & executor ) const;
		
	private:
		
		std::string _target;

};

void	shrubberyCreation( std::string target );

#endif