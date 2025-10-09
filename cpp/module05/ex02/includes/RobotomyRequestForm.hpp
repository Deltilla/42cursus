/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:49:29 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 20:19:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define	ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <string>
# include <exception>
# include <Bureaucrat.hpp>
# include <AForm.hpp>
# include <random>

class RobotomyRequestForm : public AForm
{
	public:

    	RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
    	RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    	~RobotomyRequestForm();

		std::string	getTarget( void ) const;
		void		setTarget( std::string target );

		void execute( Bureaucrat const & executor ) const;

	private :

		std::string _target;
		

};

void	robotomyRequest( std::string target );

#endif