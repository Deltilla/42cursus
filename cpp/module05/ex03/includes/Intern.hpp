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

#ifndef INTERN_H
# define INTERN_H

# include <AForm.hpp>


class Intern
{
public:

    typedef AForm* (Intern::*formCreator)( const std::string& target );

    Intern();
    Intern( const Intern& other );
    Intern& operator=( const Intern& other );
    ~Intern();

    AForm* makeForm( const std::string& formName, const std::string& target );

private:

    formCreator     forms[3];

    AForm* _createRobotomyRequest( const std::string& target );
    AForm* _createPresidentialPardon( const std::string& target );
    AForm* _createShrubberyCreation( const std::string& target );

};


#endif