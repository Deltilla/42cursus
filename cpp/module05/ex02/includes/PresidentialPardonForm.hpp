/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:49:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 20:14:34 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define	PRESIDENTIALPARDONFORM_H

# include <iostream>
# include <string>
# include <exception>
# include <Bureaucrat.hpp>
# include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	public:

    	PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
    	PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    	~PresidentialPardonForm();

		std::string	getTarget( void ) const;
		void		setTarget( std::string target );

		void execute( Bureaucrat const & executor ) const;
	
	private:

		std::string _target;

};

void	presidentialPardon( std::string target );

#endif